#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include<QString>
#include"label.h"

using namespace boost::asio;
using boost::system::error_code;

struct Client {

    Client() = default;

    static const size_t bufferSize = 1024;
    constexpr static const char ipAddress[16] = "127.0.0.1";
    static const unsigned int port = 8007;
    static void convert(std::vector<char> &c, const std::string &s);
    static void convert(std::vector<char> &c, const QString &qs);
    [[nodiscard]] static bool add_label(const QString &name, const QString &nickname, const QString &type, const QString &description, const QString &address);
    [[nodiscard]] static bool update_label_list(Label_List &labelList);
    [[nodiscard]] static int sing_in(const QString &nickname, const QString &password);
    [[nodiscard]] static int sing_up(const QString &nickname, const QString &password);
    [[nodiscard]] static int subscribe(const QString &nickname, const QString &user);

    io_service io_service_;
    ip::tcp::endpoint ep{ip::address::from_string(ipAddress), port};
    ip::tcp::socket sock{io_service_};
};

#endif // CLIENT_H

