#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#define STOP_SIMBOL '#'
#define BUFFER_SIZE 1024

using namespace boost::asio;
using namespace boost::posix_time;
using boost::system::error_code;
io_service service;


void handle_connections() {
    //создали приемник
    ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(),8002));
    std::cout << "Listening to client" << '\n';
    bool client_connected = false;
    while (!client_connected) {

        char buff_server[BUFFER_SIZE];
        ip::tcp::socket sock(service);
        acceptor.accept(sock);
        std::cout << "Server message: ";
        std::cin.getline(buff_server, BUFFER_SIZE);
        sock.write_some(buffer(buff_server));
        sock.close();

        client_connected = true;
    }

    exit(1);

}


int main(int argc, char* argv[]) {
    handle_connections();
}
