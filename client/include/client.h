#ifndef CLIENT_H
#define CLIENT_H

#include "label.h"
#include <QString>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <string>

using namespace boost::asio;
using boost::system::error_code;

enum server_response {
  SERVER_OK,
  SERVER_NICKNAME_EXISTS,
  SERVER_UNAVAILABLE_NICKNAME,
  SERVER_UNAVAILABLE_PASSWORD,
  SERVER_WRONG_NICKNAME,
  NO_CONNECTION
};

enum client_command {
  ADD_LABEL,
  UPDATE,
  SIGN_IN,
  SIGN_UP,
  SUBSCRIBE,
  SEARCH_ACCOUNT,
  USER_INFORMATION,
  LOG_OUT,
  UPDATE_SUBSCRIBES
};

struct Client {

  Client() = default;

  [[nodiscard]] static server_response
  add_label(const QString &name, const QString &user_id, const QString &type,
            const QString &description, const QString &address,
            double longitude, double latitude);
  [[nodiscard]] static server_response
  user_information(const QString &subscribe_name, QString &lables_size,
                   QString &subscribes_size);
  [[nodiscard]] static server_response sign_up(const QString &nickname,
                                               const QString &password,
                                               QString &user_id, int &size);
  [[nodiscard]] static server_response
  sign_in(const QString &nickname, const QString &password, QString &user_id);
  [[nodiscard]] static server_response
  update_subscribes(const QString &user_id, std::vector<std::string> &users);
  [[nodiscard]] static server_response
  update_label_list(Label_List &labelList, const QString &user_id);
  [[nodiscard]] static server_response subscribe(const QString &nickname,
                                                 const QString &user);
  [[nodiscard]] static server_response search_account(const QString &nickname);
  [[nodiscard]] static server_response log_out(const QString &user_id);

private:
  static const size_t bufferSize = 1024;
  constexpr static const char ipAddress[16] = "127.0.0.1";
  static const unsigned int port = 8010;
  ip::tcp::iostream stream;
  ip::tcp::endpoint ep{ip::address::from_string(ipAddress), port};
};

#endif // CLIENT_H
