#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
const int max_length = 1024;
using boost::system::error_code;

void session(socket_ptr sock) {

    int cnt = 10;
    char message_normal[4];
    char message_stop[1];
    std::string msg_normal = "Boo!";
    message_stop[0] = '#';
    
    for (int i = 0; i < 4; i++) {
        char a = msg_normal[i];
        message_normal[i] = a;
    }
    
    while (true) {
        boost::this_thread::sleep(boost::posix_time::seconds(2));
        sock->write_some(buffer(message_normal));
        cnt--;
        if (cnt == 0) {
            sock->write_some(buffer(message_stop));
            break;
        }
    }
    //sock->close();

}

void server(io_service& io_service_) {
    ip::tcp::acceptor acceptor_(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 8021));

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

