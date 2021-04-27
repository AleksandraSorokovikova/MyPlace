#include"client.h"
#include <iostream>

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

bool Client::add_label(const QString &name, const QString &user_id, const QString &type, const QString &description, const QString &address) {

    Client client;
    std::string command("add-label");

    try {
        client.stream.socket().connect(client.ep);
    } catch (...) {
        return false;
    }

    client.stream << command << std::endl;

    client.stream << name.toStdString() << std::endl;
    client.stream << user_id.toStdString() << std::endl;
    client.stream << type.toStdString() << std::endl;
    client.stream << description.toStdString() << std::endl;
    client.stream << address.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);

    if (msg_from_server =="ok") {
        client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
        return true;
    }

    return false;

}


bool Client::update_label_list(Label_List &labelList, const QString &user_id) {

    Client client;

    std::string command("update");

    try {
        client.stream.socket().connect(client.ep);
    } catch (...) {
        return false;
    }
    client.stream << command << std::endl;
    client.stream << user_id.toStdString() << std::endl;

    std::string size_;
    std::getline(client.stream, size_);
    int size = stoi(size_);

    labelList.reset();

    for (int i = 0; i < size; i++) {

        std::string id, name, nickname, type, description, address;

        std::getline(client.stream, id);
        std::getline(client.stream, name);
        std::getline(client.stream, nickname);
        std::getline(client.stream, type);
        std::getline(client.stream, description);
        std::getline(client.stream, address);

        Label label(id, name, nickname, type, description, address);
        labelList.add(label);
    }

    client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);

    return true;

}

int Client::sing_in(const QString &nickname, const QString &password, QString &user_id) {

    Client client;

    std::string command("sign-in");

    try {
        client.stream.socket().connect(client.ep);
    } catch (...) {
        return false;
    }

    client.stream << command << std::endl;

    client.stream << nickname.toStdString() << std::endl;
    client.stream << password.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);

    //никнейм и пароль совпали
    if (msg_from_server == "ok") {

        std::string user_id_;
        std::getline(client.stream, user_id_);
        user_id = QString::fromStdString(user_id_);
        client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
        return 3;
    //такого никнейма нет
    } else if (msg_from_server == "unavailable-nickname") {
        return 1;
    }

    //не совпал пароль
    return 2;
}

int Client::sing_up(const QString &nickname, const QString &password, QString &user_id, int &size) {

    Client client;

    std::string command("sign-up");

    try {
        client.stream.socket().connect(client.ep);
    } catch (...) {
        return false;
    }

    client.stream << command << std::endl;


    client.stream << nickname.toStdString() << std::endl;
    client.stream << password.toStdString() << std::endl;


    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);
    if (msg_from_server =="ok") {

        std::string user_id_;
        std::getline(client.stream, user_id_);
        user_id = QString::fromStdString(user_id_);
        client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);

        return 2;
    }

    //nickname is in use
    return 1;
}

int Client::subscribe(const QString &nickname, const QString &user_id) {

    Client client;

    std::string command("subscribe");

    try {
        client.stream.socket().connect(client.ep);
    } catch (...) {
        return false;
    }

    client.stream << command << std::endl;
    client.stream << nickname.toStdString() << std::endl;
    client.stream << user_id.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);
    if (msg_from_server == "ok") {
        client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
        return 2;
    }

    //нет такого никнейма
    return 1;
}


