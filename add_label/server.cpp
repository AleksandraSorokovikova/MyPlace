#include <iostream>
#include "label.h"
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <mutex>

using namespace boost::asio;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
Label_List labelList;
std::mutex door;
const int max_length = 1024;
using boost::system::error_code;

void convert(std::vector<char> &c, const std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

void session(socket_ptr sock) {

    while (true) {
        char command[1024];
        boost::system::error_code error;
        std::cout << "reading command" << '\n';
        sock->read_some(buffer(command), error);
        std::cout << "stopped reading" << '\n';
        std::cout << "command: " << command << '\n';
        if (!strcmp(command, "stop")) {
            break;
        } else if (!strcmp(command, "update")) {

            char size[max_length];
            auto size_of_list = std::to_string(labelList.size());
            for (int i = 0; i < size_of_list.length(); i++) {
                size[i] = size_of_list[i];
            }
            sock->write_some(buffer(size));

            for (auto x : labelList.data) {
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


        } else if (!strcmp(command, "add-label")) {
            char name[max_length], nickname[] = "@nickname", type[max_length], description[max_length], address[max_length];
            boost::system::error_code error_;
            std::cout << "reading data" << '\n';
            sock->read_some(buffer(name), error_);
            sock->read_some(buffer(nickname), error_);
            sock->read_some(buffer(type), error_);
            sock->read_some(buffer(description), error_);
            sock->read_some(buffer(address), error_);
            std::cout << "stopped reading" << '\n';

            Label label(name, nickname, type, description, address, labelList);


            door.lock();
            labelList.add(label);
            door.unlock();
        }
    }

}

void server(io_service& io_service_) {
    ip::tcp::acceptor acceptor_(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 8016));

    while (true) {
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

