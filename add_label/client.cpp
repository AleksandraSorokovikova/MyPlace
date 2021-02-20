#include <iostream>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include "label.h"

using namespace boost::asio;
using boost::system::error_code;
ip::tcp::endpoint my_computer( ip::address::from_string("127.0.0.1"), 8016);
io_service io_service_;
const int max_length = 1024;
Label_List labelList;

void client() {
    ip::tcp::socket sock(io_service_);
    sock.connect(my_computer);

    while (true) {
        std::cout << "> ";
        char command[max_length];
        std::cin.getline(command, max_length);

        sock.write_some(buffer(command));

       if (!strcmp(command, "stop")) {
           break;
       } else if (!strcmp(command, "update")) {

           char size[1024];
           boost::system::error_code error;

           sock.read_some(boost::asio::buffer(size), error);
           int size_int = *(int*)size - 48;
           std::cout << size_int << " label(s) found" << '\n';
           labelList.reset();


           for (int i = 0; i < size_int; i++) {

               char id[max_length], name[max_length], nickname[max_length], type[max_length], description[max_length], address[max_length];

               sock.read_some(buffer(id), error);
               sock.read_some(buffer(name), error);
               sock.read_some(buffer(nickname), error);
               sock.read_some(buffer(type), error);
               sock.read_some(buffer(description), error);
               sock.read_some(buffer(address), error);

               Label label(id, name, nickname, type, description, address);
               labelList.add(label);

           }


       } else if (!strcmp(command, "add-label")) {
           char name[max_length], nickname[] = "@nickname", type[max_length], description[max_length], address[max_length];
           std::cout << "name: "; std::cin.getline(name, max_length);
           std::cout << "type: "; std::cin.getline(type, max_length);
           std::cout << "description: "; std::cin.getline(description, max_length);
           std::cout << "address: "; std::cin.getline(address, max_length);

           sock.write_some(buffer(name));
           sock.write_some(buffer(nickname));
           sock.write_some(buffer(type));
           sock.write_some(buffer(description));
           sock.write_some(buffer(address));

       } else if (!strcmp(command, "print")) {
           std::cout << labelList.size() << " labels found" << '\n';
           labelList.print_labels();
       }
    }

    std::cout << "Connection stopped" << '\n';
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    sock.close();

}

int main() {

    try {
        client();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}