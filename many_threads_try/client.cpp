#include <iostream>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
using boost::system::error_code;
ip::tcp::endpoint my_computer( ip::address::from_string("127.0.0.1"), 8021);
io_service io_service_;
const int max_length = 1024;
#define STOP_SYMBOL '#'


bool find_stop_signal(const char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == STOP_SYMBOL) {
            return true;
        }
    }
    return false;
}

size_t read_complete(char * buf, const error_code & err, size_t bytes) {
    if (err) return 0;
    bool found = std::find(buf, buf + bytes, '\n') < buf + bytes;
    // we read one-by-one until we get to enter, no buffering
    return found ? 0 : 1;
}

void echo() {
    ip::tcp::socket sock(io_service_);
    sock.connect(my_computer);

    bool close_connection = false;
    
    while (!close_connection) {
        char buf[max_length];
        boost::system::error_code error;
        //read(sock, buffer(buf), boost::bind(read_complete, buf, _1, _2));
        sock.read_some(boost::asio::buffer(buf), error);
        std::cout << buf;
        std::cout << '\n';
        
        close_connection = find_stop_signal(buf);
    }

    std::cout << "Connection stopped" << '\n';
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    sock.close();

}

int main() {

    try {
        echo();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}


