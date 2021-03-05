#include"client.h"

void Client::convert(std::vector<char> &c, const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

void Client::convert(std::vector<char> &c, const QString &qs) {
    std::string s = qs.toStdString().c_str();
    for (size_t i = 0; i < s.length(); i++) {
        c[i] = s[i];
    }
}

bool Client::add_label(const QString &name, const QString &nickname, const QString &type, const QString &description, const QString &address) {

    Client client;

    std::string command("add-label");
    std::vector<char> command_v(bufferSize);
    convert(command_v, command);

    try {
        client.sock.connect(client.ep);
    } catch (...) {
        return false;
    }

    client.sock.write_some(buffer(command_v));

    std::vector<char> name_v(bufferSize);
    std::vector<char> nickname_v(bufferSize);
    std::vector<char> type_v(bufferSize);
    std::vector<char> description_v(bufferSize);
    std::vector<char> address_v(bufferSize);

    convert(name_v, name);
    convert(nickname_v, nickname);
    convert(type_v, type);
    convert(description_v, description);
    convert(address_v, address);

    client.sock.write_some(buffer(name_v));
    client.sock.write_some(buffer(nickname_v));
    client.sock.write_some(buffer(type_v));
    client.sock.write_some(buffer(description_v));
    client.sock.write_some(buffer(address_v));

    char msg_from_server[bufferSize];
    boost::system::error_code error;
    client.sock.read_some(buffer(msg_from_server), error);

    if (!strcmp(msg_from_server, "ok")) {
        client.sock.close();
        return true;
    }

    return false;

}


bool Client::update_label_list(Label_List &labelList) {

    Client client;

    std::string command("update");
    std::vector<char> command_v(bufferSize);
    convert(command_v, command);


    try {
        client.sock.connect(client.ep);
    } catch(...) {
        return false;
    }

    client.sock.write_some(buffer(command_v));


    char size[1024];
    boost::system::error_code error;

    client.sock.read_some(boost::asio::buffer(size), error);
    int size_int = *(int*)size - 48;
    labelList.reset();


    for (int i = 0; i < size_int; i++) {

        char id[bufferSize], name[bufferSize], nickname[bufferSize], type[bufferSize], description[bufferSize], address[bufferSize];

        client.sock.read_some(buffer(id), error);
        client.sock.read_some(buffer(name), error);
        client.sock.read_some(buffer(nickname), error);
        client.sock.read_some(buffer(type), error);
        client.sock.read_some(buffer(description), error);
        client.sock.read_some(buffer(address), error);

        Label label(id, name, nickname, type, description, address);
        labelList.add(label);

    }

    client.sock.close();

    return true;

}

