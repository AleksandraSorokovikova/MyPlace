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

void user_information(stream_ptr stream) {
    std::string user_nickname;
    std::getline(*stream, user_nickname);

    User user = userList.get_user_by_nickname(user_nickname);

    *stream << user.number_of_own_labels() << std::endl;
    *stream << user.number_of_subscribes() << std::endl;

}

void log_out(stream_ptr stream) {
    std::string user_id;
    std::getline(*stream, user_id);

    door.lock();
    activeUsers.deactivate(user_id);
    door.unlock();

}

void add_label(stream_ptr stream) {
    std::string name, user_id, type, description, address;

    std::getline(*stream, name);
    std::getline(*stream, user_id);
    std::getline(*stream, type);
    std::getline(*stream, description);
    std::getline(*stream, address);

    std::string nickname(activeUsers.get_nickname(user_id));

    Label label(name, nickname, type, description, address, labelList);

    door.lock();
    labelList.add(label);
    userList.add_label_for_current_user(nickname, label.id);
    door.unlock();


    *stream << SERVER_OK << std::endl;

    boost::this_thread::sleep(boost::posix_time::millisec(200));
}

void update(stream_ptr stream) {
    std::string user_id;
    std::getline(*stream, user_id);

    User user = userList.get_user_by_nickname(activeUsers.get_nickname(user_id));
    size_t number_of_labels = user.number_of_own_labels();

    for (const auto &subscribe : user.subscribes) {
        User user_subscribe = userList.get_user_by_nickname(subscribe);
        number_of_labels += user_subscribe.number_of_own_labels();
    }

    *stream << std::to_string(number_of_labels) << std::endl;
    for (const auto &label_id : user.labels) {
        Label subscribe_label = labelList.get_by_id(label_id);
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
    size_t number_of_subscribes = user.number_of_subscribes();

    *stream << std::to_string(number_of_subscribes) << std::endl;


    for (const auto &subscribe : user.subscribes) {
        User user_subscribe = userList.get_user_by_nickname(subscribe);

        *stream << user_subscribe.nickname << std::endl;
    }

    boost::this_thread::sleep(boost::posix_time::millisec(200));
}


void sign_up(stream_ptr stream) {

    std::string nickname, password;
    std::getline(*stream, nickname);
    std::getline(*stream, password);

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

        *stream << SERVER_OK << std::endl;
        *stream << id << std::endl;

        boost::this_thread::sleep(boost::posix_time::millisec(200));
    }

}


void sign_in(stream_ptr stream) {
    std::string nickname, password;

    std::getline(*stream, nickname);
    std::getline(*stream, password);

    std::vector<char> msg_to_client(max_length);
    if (!userList.nickname_in_list(nickname)) {

        *stream << SERVER_UNAVAILABLE_NICKNAME << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    } else {

        if (!userList.check_password(nickname, password)) {

            *stream << SERVER_UNAVAILABLE_PASSWORD << std::endl;
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

        std::string id;

        door.lock();
        id = activeUsers.activate(nickname);
        door.unlock();

        *stream << SERVER_OK << std::endl;
        *stream << id << std::endl;

        boost::this_thread::sleep(boost::posix_time::millisec(200));
    }
}

void subscribe(stream_ptr stream) {
    std::string user_id, other_nickname;
    std::getline(*stream, other_nickname);
    std::getline(*stream, user_id);

    std::string nickname(activeUsers.get_nickname(user_id));

    if (!userList.nickname_in_list(nickname) || nickname == other_nickname || userList.get_user_by_nickname(nickname).is_subscribed(other_nickname)) {
        *stream << SERVER_WRONG_NICKNAME << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));
    } else {
        userList.subscribe_user(nickname, other_nickname);
        *stream << SERVER_OK << std::endl;
        boost::this_thread::sleep(boost::posix_time::millisec(200));

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

        try {
            getline(*stream, command);

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
                    boost::this_thread::sleep(boost::posix_time::millisec(200));
                    exit(1);
            }
        } catch(...) {
            boost::this_thread::sleep(boost::posix_time::millisec(200));
        }

}

void server(io_service& io_service_) {
    ip::tcp::acceptor acceptor_(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 8010));

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
