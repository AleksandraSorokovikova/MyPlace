#include"client.h"

using namespace boost::asio;
using boost::system::error_code;


void convert(std::vector<char> &c, const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

void convert(std::vector<char> &c, const QString &qs) {
    std::string s = qs.toStdString().c_str();
    for (size_t i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

bool add_label(const QString &name, const QString &nickname, const QString &type, const QString &description, const QString &address) {

    io_service io_service_;
    ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 8007);
    const int max_length = 1024;

    ip::tcp::socket sock(io_service_);
    std::string command("add-label");
    std::vector<char> command_v(max_length);
    convert(command_v, command);

    try {
        sock.connect(ep);
    } catch (...) {
        return false;
    }

    sock.write_some(buffer(command_v));


    std::vector<char> name_v(max_length);
    std::vector<char> nickname_v(max_length);
    std::vector<char> type_v(max_length);
    std::vector<char> description_v(max_length);
    std::vector<char> address_v(max_length);

    convert(name_v, name);
    convert(nickname_v, nickname);
    convert(type_v, type);
    convert(description_v, description);
    convert(address_v, address);


    sock.write_some(buffer(name_v));
    sock.write_some(buffer(nickname_v));
    sock.write_some(buffer(type_v));
    sock.write_some(buffer(description_v));
    sock.write_some(buffer(address_v));


    sock.close();
    return true;

}

bool update_label_list(Label_List &labelList) {

    io_service io_service_;
    ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 8007);
    const int max_length = 1024;

    ip::tcp::socket sock(io_service_);
    std::string command("update");
    std::vector<char> command_v(max_length);
    convert(command_v, command);
    try {
        sock.connect(ep);
    } catch(...) {
        return false;
    }

    sock.write_some(buffer(command_v));


    char size[1024];
    boost::system::error_code error;

    sock.read_some(boost::asio::buffer(size), error);
    int size_int = *(int*)size - 48;
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

    sock.close();

    return true;

}
