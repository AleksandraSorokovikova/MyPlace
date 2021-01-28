#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>
#define BUFFER_SIZE 1024
#define STOP_SIMBOL '#'
using namespace boost::asio;
using boost::system::error_code;
io_service service;

size_t read_complete(char * buf, const error_code & err, size_t bytes) {
    if (err) return 0;
    bool found = std::find(buf, buf + bytes, '\n') < buf + bytes;
    // we read one-by-one until we get to enter, no buffering
    return found ? 0 : 1;
}
bool find_stop_signal(std::string &msg) {
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == STOP_SIMBOL) {
            return true;
        }
    }
    return false;
}
ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 8002);

void sync_echo() {

    std::cout << "Connected to server" << '\n';
    while (true) {
        ip::tcp::socket sock(service);
        sock.connect(ep);
        char buff_client[BUFFER_SIZE];

        std::cout << "Client: ";
        std::cin.getline(buff_client, BUFFER_SIZE);
        std::cout << "Server: ";
        std::string msg(buff_client);
        sock.write_some(buffer(buff_client));
        if (find_stop_signal(msg)) {
            std::cout << "Goodbye" << '\n';
            sock.close();
            break;
        }
        char buff_server[BUFFER_SIZE];
        read(sock, buffer(buff_server), boost::bind(read_complete,buff_server,_1,_2));
        std::cout << buff_server;
        std::cout << '\n';

        sock.close();
    }
}

int main(int argc, char* argv[]) {
    // connect several clients
    /*
    char* messages[] = { "John says hi", "so does James",
                         "Lucy just got home", "Boost.Asio is Fun!", 0 }; */
    /*
    boost::thread_group threads;
    for (char ** message = messages; *message; ++message) {
        threads.create_thread(boost::bind(sync_echo, *message));
        boost::this_thread::sleep( boost::posix_time::millisec(100));
    }
    threads.join_all(); */
    sync_echo();
}
