#include <iostream>
#include "label.h"
#include "users.h"
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <mutex>
#include <map>

using namespace boost::asio;
typedef boost::shared_ptr<ip::tcp::iostream> stream_ptr;
Label_List labelList;
User_List userList;
Active_Users activeUsers;
std::mutex door;
const int max_length = 1024;
using boost::system::error_code;

enum server_response {
    SERVER_OK,
    SERVER_NICKNAME_EXISTS,
    SERVER_UNAVAILABLE_NICKNAME,
    SERVER_UNAVAILABLE_PASSWORD,
    SERVER_WRONG_NICKNAME
};

enum client_command {
    ADD_LABEL,
    UPDATE,
    SIGN_IN,
    SIGN_UP,
    SUBSCRIBE,
    SEARCH_ACCOUNT,
    USER_INFORMATION,
    LOG_OUT,
    UPDATE_SUBSCRIBES
};

//нужен для консольного вывода команды (чтобы их отслеживать)
std::map<int, std::string> commands = {{0, "ADD_LABEL"}, {1, "UPDATE"},
                                       {2, "SIGN_IN"}, {3, "SIGN_UP"}, {4, "SUBSCRIBE"},
                                       {5, "SEARCH_ACCOUNT"}, {6, "USER_INFORMATION"},
                                       {7, "LOG_OUT"}, {8, "UPDATE_SUBSCRIBES"}};

void user_information(stream_ptr stream) {
    std::string user_nickname;
    std::getline(*stream, user_nickname);

    User user = userList.get_user_by_nickname(user_nickname);

    std::cout << "INFORMATION ABOUT " << user_nickname << ": " << '\n';
    std::cout << "SUBSCRIBES: " << user.own_labels() << '\n';
    std::cout << "SUBSCRIBES: " << user.subscribes.size() << '\n';

    *stream << user.own_labels() << std::endl;
    *stream << user.subscribes.size() << std::endl;

}

void log_out(stream_ptr stream) {
    std::string user_id;
    std::getline(*stream, user_id);

    std::cout << "DEACTIVATING {" << user_id << ", " << activeUsers.get_nickname(user_id) << "}" << '\n';

    door.lock();
    activeUsers.deactivate(user_id);
    door.unlock();


    std::cout << "ACTIVE USERS: " << '\n';
    for (const auto & x : activeUsers.active_users) {
        std::cout << x.second << '\n';
    }

}

void add_label(stream_ptr stream) {
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
    userList.add_label_for_current_user(nickname, label.id);
    door.unlock();

    std::cout << "labels of " << nickname << ": " << '\n';
    for (const auto &id : userList.data.find(nickname)->second.labels) {
        std::cout << labelList.data.find(id)->second.name << '\n';
    }

    *stream << SERVER_OK << std::endl;

    boost::this_thread::sleep(boost::posix_time::millisec(200));
}

void update(stream_ptr stream) {
    std::string user_id;
    std::getline(*stream, user_id);

    std::cout << "available users: " << '\n';
    for (const auto &x : userList.nickname_list) {
        std::cout << x << '\n';
    }

    User user = userList.get_user_by_nickname(activeUsers.get_nickname(user_id));
    size_t number_of_labels = user.labels.size();

    for (const auto &subscribe : user.subscribes) {
        User user_subscribe = userList.get_user_by_nickname(subscribe);
        number_of_labels += user_subscribe.labels.size();
    }

    std::cout << "NUMBER OF LABELS IS " << user.number_of_labels << '\n';
    *stream << std::to_string(number_of_labels) << std::endl;


    std::cout << "Subscribes of: " << user.nickname << '\n';
    for (const auto &x : user.subscribes) {
        std::cout << x << '\n';
    }

    for (const auto &label_id : user.labels) {
        Label subscribe_label = labelList.get_by_id(label_id);
        std::cout << "Sending label..." << '\n';
        std::cout << subscribe_label.id << '\n';
        std::cout << subscribe_label.name << '\n';
        std::cout << subscribe_label.nickname << '\n';
        std::cout << subscribe_label.type << '\n';
        std::cout << subscribe_label.description << '\n';
        std::cout << subscribe_label.address << '\n';

        *stream << subscribe_label.id << std::endl;
        *stream << subscribe_label.name << std::endl;
        *stream << subscribe_label.nickname << std::endl;
        *stream << subscribe_label.type << std::endl;
        *stream << subscribe_label.description << std::endl;
        *stream << subscribe_label.address << std::endl;
    }

    for (const auto &subscribe : user.subscribes) {
        User user_subscribe = userList.get_user_by_nickname(subscribe);
        for (const auto &label_id : user_subscribe.labels) {
            Label subscribe_label = labelList.get_by_id(label_id);
            std::cout << "Sending label..." << '\n';
            std::cout << subscribe_label.id << '\n';
            std::cout << subscribe_label.name << '\n';
            std::cout << subscribe_label.nickname << '\n';
            std::cout << subscribe_label.type << '\n';
            std::cout << subscribe_label.description << '\n';
            std::cout << subscribe_label.address << '\n';

            *stream << subscribe_label.id << std::endl;
            *stream << subscribe_label.name << std::endl;
            *stream << subscribe_label.nickname << std::endl;
            *stream << subscribe_label.type << std::endl;
            *stream << subscribe_label.description << std::endl;
            *stream << subscribe_label.address << std::endl;

        }
    }

    boost::this_thread::sleep(boost::posix_time::millisec(200));
}

void update_subscribes(stream_ptr stream) {

    std::string user_id;
    std::getline(*stream, user_id);


    User user = userList.get_user_by_nickname(activeUsers.get_nickname(user_id));
    size_t number_of_subscribes = user.subscribes.size();


    std::cout << "NUMBER OF SUBSCRIBES IS " << number_of_subscribes << '\n';
    *stream << std::to_string(number_of_subscribes) << std::endl;


    std::cout << "Subscribes of: " << user.nickname << '\n';
    for (const auto &x : user.subscribes) {
        std::cout << x << '\n';
    }

    for (const auto &subscribe : user.subscribes) {
        User user_subscribe = userList.get_user_by_nickname(subscribe);
        std::cout << "Sending information about subscribe..." << '\n';

        //никнейм пользователя
        std::cout << user_subscribe.nickname << '\n';
        //колиество подписок пользователя
        std::cout << user_subscribe.subscribes.size() << '\n';
        //количество собственных меток пользователя
        std::cout << user_subscribe.labels.size() << '\n';

        *stream << user_subscribe.nickname << std::endl;
        *stream << user_subscribe.subscribes.size() << std::endl;
        *stream << user_subscribe.labels.size() << std::endl;

    }

    boost::this_thread::sleep(boost::posix_time::millisec(200));
}


void sign_up(stream_ptr stream) {

    std::string nickname, password;
    std::getline(*stream, nickname);
    std::getline(*stream, password);


    std::cout << "creating new_account\n";
    std::cout << "nickname: " << nickname << '\n';
    std::cout << "password: " << password << '\n';

    if (userList.nickname_in_list(nickname)) {

        *stream << SERVER_NICKNAME_EXISTS << std::endl;
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
        *stream << SERVER_OK << std::endl;

        //отправляем временный id текущего пользователя
        *stream << id << std::endl;

        boost::this_thread::sleep(boost::posix_time::millisec(200));
    }

}


void sign_in(stream_ptr stream) {
    std::string nickname, password;

    std::getline(*stream, nickname);
    std::getline(*stream, password);

    std::cout << "trying to sign in\n";
    std::cout << "nickname: " << nickname << '\n';
    std::cout << "password: " << password << '\n';

    std::vector<char> msg_to_client(max_length);
    if (!userList.nickname_in_list(nickname)) {

        *stream << SERVER_UNAVAILABLE_NICKNAME << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    } else {

        if (!userList.right_password(nickname, password)) {

            *stream << SERVER_UNAVAILABLE_PASSWORD << std::endl;
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

        std::string id;

        door.lock();
        id = activeUsers.activate(nickname);
        door.unlock();

        std::cout << "ACTIVATING USER: {" << id << ", " << nickname << "}" << '\n';

        //отправляем статус, что вход состоялся
        *stream << SERVER_OK << std::endl;

        //отправляем временный id текущего пользователя
        *stream << id << std::endl;

        boost::this_thread::sleep(boost::posix_time::millisec(200));
    }
}

void subscribe(stream_ptr stream) {
    std::string user_id, other_nickname;
    std::getline(*stream, other_nickname);
    std::getline(*stream, user_id);

    std::string nickname(activeUsers.get_nickname(user_id));

    std::cout << "SUBSCRIBING\n";
    std::cout << "user: {" << user_id << ", " << nickname << "}" << '\n';
    std::cout << "other nickname: " << other_nickname << '\n';

    if (!userList.nickname_in_list(nickname) || nickname == other_nickname || userList.get_user_by_nickname(nickname).is_subscribed(other_nickname)) {
        *stream << SERVER_WRONG_NICKNAME << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    } else {
        User other_user = userList.data.find(nickname)->second;
        userList.data.find(nickname)->second.subscribe(other_nickname, other_user.labels.size());
        *stream << SERVER_OK << std::endl;

        boost::this_thread::sleep(boost::posix_time::millisec(200));

        std::cout << "number of subscribes of " << nickname << ": " << userList.data.find(nickname)->second.subscribes.size()<< '\n';
    }
}

void search_account(stream_ptr stream) {
    std::string nickname;
    std::getline(*stream, nickname);

    if (!userList.nickname_in_list(nickname)) {
        *stream << SERVER_WRONG_NICKNAME << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    } else {
        *stream << SERVER_OK << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    }


}


void session(stream_ptr stream) {

        std::string command;
        std::cout << "reading command" << '\n';
        getline(*stream, command);


        std::cout << "stopped reading" << '\n';
        std::cout << "command: " << commands[std::stoi(command)] << '\n';
        int client_command = std::stoi(command);

        switch (client_command) {
            case ADD_LABEL:
                add_label(stream);
                break;
            case UPDATE:
                update(stream);
                break;
            case SIGN_IN:
                sign_in(stream);
                break;
            case SIGN_UP:
                sign_up(stream);
                break;
            case SUBSCRIBE:
                subscribe(stream);
                break;
            case SEARCH_ACCOUNT:
                search_account(stream);
                break;
            case USER_INFORMATION:
                user_information(stream);
                break;
            case LOG_OUT:
                log_out(stream);
                break;
            case UPDATE_SUBSCRIBES:
                update_subscribes(stream);
                break;
            default:
                //тут все крашится
                boost::this_thread::sleep(boost::posix_time::millisec(200));
                exit(1);
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
