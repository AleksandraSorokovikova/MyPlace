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


size_t read_complete(char * buff, const error_code & err, size_t bytes) {
    if (err) return 0;
    bool found = std::find(buff, buff + bytes, '\n') < buff + bytes;
    // we read one-by-one until we get to enter, no buffering
    return found ? 0 : 1;
}

bool find_stop_signal(const char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == STOP_SIMBOL) {
            return true;
        }
    }
    return false;
}

void handle_connections() {
    //создали приемник
    ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(),8012));
    ip::tcp::socket sock(service);
    acceptor.accept(sock);
    std::cout << "Listening to client" << '\n';
    //буффер, будем туда читать
    while (true) {
        char buff_client[BUFFER_SIZE];
        char buff_server[BUFFER_SIZE];
    
        //read(sock, buffer(buff_client),
                         //boost::bind(read_complete,buff_client,_1,_2));
        boost::system::error_code error;
        sock.read_some(boost::asio::buffer(buff_client), error);
        std::cout << "Client: " << buff_client << '\n';
        std::cout << "Server: ";

        if (find_stop_signal(buff_client)) {
            std::cout << "Goodbye" << '\n';
            break;
        }

        std::cin.getline(buff_server, BUFFER_SIZE);

        std::string msg_to_client(buff_server);
        sock.write_some(buffer(buff_server));

    }
    sock.close();
    exit(1);

}


int main(int argc, char* argv[]) {
    handle_connections();
}
