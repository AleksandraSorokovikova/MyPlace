#include <iostream>
#include "label.h"
#include "users.h"
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <mutex>

using namespace boost::asio;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
typedef boost::shared_ptr<ip::tcp::iostream> stream_ptr;
Label_List labelList;
User_List userList;
Active_Users activeUsers;
std::mutex door;
const int max_length = 1024;
using boost::system::error_code;


void session(stream_ptr stream) {

        std::string command;
        std::cout << "reading command" << '\n';
        getline(*stream, command);


        std::cout << "stopped reading" << '\n';
        std::cout << "command: " << command << '\n';
        if (command == "stop") {
            boost::this_thread::sleep(boost::posix_time::millisec(200));
            //break;
        } else if(command == "stop all") {
            //НЕБЕЗОПАСНО! ВЫЗЫВАТЬ ТОЛЬКО ЕСЛИ ВСЕ КЛИЕНТЫ ОТКЛЮЧЕНЫ
            boost::this_thread::sleep(boost::posix_time::millisec(200));
            exit(1);

        } else if (command == "update") {

            std::cout << "available users: " << '\n';
            for (auto x : userList.nickname_list) {
                std::cout << x << '\n';
            }

            *stream << std::to_string(labelList.size()) << std::endl;


            for (auto x : labelList.data) {
                std::cout << "Sending label..." << '\n';
                std::cout << x.second.id << '\n';

                *stream << x.second.id << std::endl;
                *stream << x.second.name << std::endl;
                *stream << x.second.nickname << std::endl;
                *stream << x.second.type << std::endl;
                *stream << x.second.description << std::endl;
                *stream << x.second.address << std::endl;
            }

            boost::this_thread::sleep(boost::posix_time::millisec(200));

        } else if (command == "add-label") {

            std::string name, user_id, type, description, address;

            std::getline(*stream, name);
            std::getline(*stream, user_id);
            std::getline(*stream, type);
            std::getline(*stream, description);
            std::getline(*stream, address);

            std::string nickname(activeUsers.get_nickname(user_id));

            std::cout << "USER {" << user_id << ", " << nickname << "}" << "ADDED LABEL" << '\n';
            
            std::cout << "some data received\n";
            std::cout << name << '\n';
            std::cout << nickname << '\n';
            std::cout << type << '\n';
            std::cout << description << '\n';
            std::cout << address << '\n';

            Label label(name, nickname, type, description, address, labelList);

            door.lock();
            labelList.add(label);
            userList.data.find(nickname)->second.add_label(label.id);
            door.unlock();

            std::cout << "labels of " << nickname << ": " << '\n';
            for (auto id : userList.data.find(nickname)->second.labels) {
                std::cout << labelList.data.find(id)->second.name << '\n';
            }

            *stream << "ok" << std::endl;
            
            boost::this_thread::sleep(boost::posix_time::millisec(200));

    } else if (command == "sign-up") {
        std::string nickname, password;
        std::getline(*stream, nickname);
        std::getline(*stream, password);


        std::cout << "creating new_account\n";
        std::cout << "nickname: " << nickname << '\n';
        std::cout << "password: " << password << '\n';

        if (userList.nickname_in_list(nickname)) {

            *stream << "not-ok" << std::endl;
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        } else {

            User user(nickname, password, userList);
            std::string id;

            door.lock();
            userList.add(user);
            id = activeUsers.activate(nickname);
            door.unlock();

            std::cout << "ACTIVATING USER: {" << id << ", " << nickname << "}" << '\n';

            //отправляем статус, что аккаунт добавлен успешно
            *stream << "ok" << std::endl;

            //отправляем временный id текущего пользователя
            *stream << id << std::endl;

            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

    } else if (command == "sign-in") {

        std::string nickname, password;

        std::getline(*stream, nickname);
        std::getline(*stream, password);

        std::cout << "trying to sign in\n";
        std::cout << "nickname: " << nickname << '\n';
        std::cout << "password: " << password << '\n';

        std::vector<char> msg_to_client(max_length);
        if (!userList.nickname_in_list(nickname)) {

            *stream << "unavailable-nickname" << std::endl;
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        } else {

            if (!userList.right_password(nickname, password)) {

                *stream << "unavailable-password" << std::endl;
                boost::this_thread::sleep(boost::posix_time::millisec(200));
            }

            std::string id;

            door.lock();
            id = activeUsers.activate(nickname);
            door.unlock();

            std::cout << "ACTIVATING USER: {" << id << ", " << nickname << "}" << '\n';

            //отправляем статус, что вход состоялся
            *stream << "ok" << std::endl;

            //отправляем временный id текущего пользователя
            *stream << id << std::endl;

            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

    } else if (command == "subscribe") {
            std::string user_id, other_nickname;
            std::getline(*stream, other_nickname);
            std::getline(*stream, user_id);

            std::string nickname(activeUsers.get_nickname(user_id));

            std::cout << "SUBSCRIBING\n";
            std::cout << "user: {" << user_id << ", " << nickname << "}" << '\n';
            std::cout << "other nickname: " << other_nickname << '\n';
            std::vector<char> msg_to_client(max_length);

            if (!userList.nickname_in_list(nickname)) {
                *stream << "unavailable-nickname" << std::endl;
                boost::this_thread::sleep(boost::posix_time::millisec(200));
            } else {
                userList.data.find(nickname)->second.subscribe(other_nickname);
                *stream << "ok" << std::endl;

                boost::this_thread::sleep(boost::posix_time::millisec(200));

                std::cout << "number of subscribes of " << nickname << ": " << userList.data.find(nickname)->second.subscribes.size()<< '\n';
            }
        }

    std::cout << "Connection stopped" << '\n';

}

void server(io_service& io_service_) {
    ip::tcp::acceptor acceptor_(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 8007));

    while (true) {

        stream_ptr stream(new ip::tcp::iostream);
        acceptor_.accept(*stream->rdbuf());

        boost::thread thread_(boost::bind(session, stream));

    }
}

int main() {

    boost::asio::io_service io_service;
    server(io_service);
    return 0;
}
