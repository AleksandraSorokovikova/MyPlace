#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>
#define BUFFER_SIZE 1024
using namespace boost::asio;
using boost::system::error_code;

io_service service;
ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 8002);

size_t read_complete(char * buf, const error_code & err, size_t bytes) {
    if (err) return 0;
    bool found = std::find(buf, buf + bytes, '\n') < buf + bytes;
    // we read one-by-one until we get to enter, no buffering
    return found ? 0 : 1;
}


void sync_echo() {

    ip::tcp::socket sock(service);
    sock.connect(ep);


    char buff_server[BUFFER_SIZE];
    read(sock, buffer(buff_server), boost::bind(read_complete,buff_server,_1,_2));


    std::cout << buff_server;
    std::cout << '\n';

    sock.close();
}

int main(int argc, char* argv[]) {
    sync_echo();
}
