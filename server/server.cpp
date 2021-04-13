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
Label_List labelList;
User_List userList;
Active_Users activeUsers;
std::mutex door;
const int max_length = 1024;
using boost::system::error_code;

void convert(std::vector<char> &c, const std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

void session(socket_ptr sock) {

        char command[1024];
        boost::system::error_code error;
        std::cout << "reading command" << '\n';
        sock->read_some(buffer(command), error);
        std::cout << "stopped reading" << '\n';
        std::cout << "command: " << command << '\n';
        if (!strcmp(command, "stop")) {
            boost::this_thread::sleep(boost::posix_time::millisec(200));
            //break;
        } else if(!strcmp(command, "stop all")) {
            //НЕБЕЗОПАСНО! ВЫЗЫВАТЬ ТОЛЬКО ЕСЛИ ВСЕ КЛИЕНТЫ ОТКЛЮЧЕНЫ
            boost::this_thread::sleep(boost::posix_time::millisec(200));
            exit(1);

        } else if (!strcmp(command, "update")) {

            std::cout << "available users: " << '\n';
            for (auto x : userList.nickname_list) {
                std::cout << x << '\n';
            }

            char size[max_length];
            auto size_of_list = std::to_string(labelList.size());
            for (int i = 0; i < size_of_list.length(); i++) {
                size[i] = size_of_list[i];
            }
            sock->write_some(buffer(size));

            for (auto x : labelList.data) {
                std::cout << x.second.id << '\n';
                std::vector<char> id(max_length);
                convert(id, x.second.id);
                std::vector<char> name(max_length);
                convert(name, x.second.name);
                std::vector<char> nickname(max_length);
                convert(nickname, x.second.nickname);
                std::vector<char> type(max_length);
                convert(type, x.second.type);
                std::vector<char> description(max_length);
                convert(description, x.second.description);
                std::vector<char> address(max_length);
                convert(address, x.second.address);

                sock->write_some(buffer(id));
                sock->write_some(buffer(name));
                sock->write_some(buffer(nickname));
                sock->write_some(buffer(type));
                sock->write_some(buffer(description));
                sock->write_some(buffer(address));

            }

            boost::this_thread::sleep(boost::posix_time::millisec(200));
            //break;


        } else if (!strcmp(command, "add-label")) {
            char name[max_length], user_id[max_length], type[max_length], description[max_length], address[max_length];
            boost::system::error_code error_;
            
            sock->read_some(buffer(name), error_);
            sock->read_some(buffer(user_id), error_);
            sock->read_some(buffer(type), error_);
            sock->read_some(buffer(description), error_);
            sock->read_some(buffer(address), error_);
            std::string nickname(activeUsers.get_nickname(user_id));

            std::cout << "USER " << user_id << ", " << nickname << "}" << "ADDED LABEL" << '\n';
            
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
            
            std::vector<char> msg_to_client(max_length);
            convert(msg_to_client, "ok");
            sock->write_some(buffer(msg_to_client));
            
            boost::this_thread::sleep(boost::posix_time::millisec(200));

    } else if (!strcmp(command, "sign-up")) {
        char nickname[max_length], password[max_length];
        boost::system::error_code error_;

        sock->read_some(buffer(nickname), error_);
        sock->read_some(buffer(password), error_);


        std::cout << "creating new_account\n";
        std::cout << "nickname: " << nickname << '\n';
        std::cout << "password: " << password << '\n';

        if (userList.nickname_in_list(nickname)) {
            std::vector<char> msg_to_client(max_length);
            convert(msg_to_client, "not-ok");
            sock->write_some(buffer(msg_to_client));
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
            std::vector<char> msg_to_client(max_length);
            convert(msg_to_client, "ok");
            sock->write_some(buffer(msg_to_client));

            //отправляем временный id текущего пользователя
            std::vector<char> id_v(max_length);
            convert(id_v, id);
            //sock->write_some(buffer(id_v));
            write(*sock, buffer(id_v));

            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

    } else if (!strcmp(command, "sign-in")) {
        char nickname[max_length], password[max_length];
        boost::system::error_code error_;

        sock->read_some(buffer(nickname), error_);
        sock->read_some(buffer(password), error_);
        std::cout << "trying to sign in\n";
        std::cout << "nickname: " << nickname << '\n';
        std::cout << "password: " << password << '\n';

        std::vector<char> msg_to_client(max_length);
        if (!userList.nickname_in_list(nickname)) {
            convert(msg_to_client, "unavailable-nickname");
            sock->write_some(buffer(msg_to_client));
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        } else {

            if (!userList.right_password(nickname, password)) {
                convert(msg_to_client, "unavailable-password");
                sock->write_some(buffer(msg_to_client));
                boost::this_thread::sleep(boost::posix_time::millisec(200));
            }

            std::string id;

            door.lock();
            id = activeUsers.activate(nickname);
            door.unlock();

            std::cout << "ACTIVATING USER: {" << id << ", " << nickname << "}" << '\n';

            //отправляем статус, что вход состоялся
            convert(msg_to_client, "ok");
            sock->write_some(buffer(msg_to_client));

            //отправляем временный id текущего пользователя
            std::vector<char> id_v(max_length);
            convert(id_v, id);
            sock->write_some(buffer(id_v));

            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

    } else if (!strcmp(command, "subscribe")) {
            char user_id[max_length], other_nickname[max_length];
            boost::system::error_code error_;
            sock->read_some(buffer(other_nickname), error_);
            sock->read_some(buffer(user_id), error_);
            std::string nickname(activeUsers.get_nickname(user_id));

            std::cout << "SUBSCRIBING\n";
            std::cout << "user: {" << user_id << ", " << nickname << "}" << '\n';
            std::cout << "other nickname: " << other_nickname << '\n';
            std::vector<char> msg_to_client(max_length);

            if (!userList.nickname_in_list(nickname)) {
                convert(msg_to_client, "unavailable-nickname");
                sock->write_some(buffer(msg_to_client));
                boost::this_thread::sleep(boost::posix_time::millisec(200));
            } else {
                userList.data.find(nickname)->second.subscribe(other_nickname);
                //userList.data.find(nickname)->second.subscribe(nickname);

                convert(msg_to_client, "ok");
                sock->write_some(buffer(msg_to_client));

                boost::this_thread::sleep(boost::posix_time::millisec(200));

                std::cout << "number of subscribes of " << nickname << ": " << userList.data.find(nickname)->second.subscribes.size()<< '\n';
                /*
                for (auto x : userList.data.find(nickname)->second.subscribes) {
                    std::cout << x << '\n';
                } */
            }
        }

    std::cout << "Connection stopped" << '\n';

}

void server(io_service& io_service_) {
    ip::tcp::acceptor acceptor_(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 8007));

    int cnt = 1;
    while (true) {
        //std::cout << (cnt++) << '\n';
        socket_ptr sock(new ip::tcp::socket(io_service_));
        acceptor_.accept(*sock);
        boost::thread thread_(boost::bind(session, sock));

    }
}

int main() {

    boost::asio::io_service io_service;
    server(io_service);
    return 0;
}
