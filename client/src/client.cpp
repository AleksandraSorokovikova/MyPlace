#include "include/client.h"
#include <iostream>

server_response Client::add_label(const QString &name, const QString &user_id,
                                  const QString &type,
                                  const QString &description,
                                  const QString &address, double longitude,
                                  double latitude) {

  Client client;

  std::string description_str = description.toStdString();

  for (auto &c : description_str) {
    if (c == '\n') {
      c = '&';
    }
  }

  try {
    client.stream.socket().connect(client.ep);
    client.stream << ADD_LABEL << std::endl;

    client.stream << name.toStdString() << std::endl;
    client.stream << user_id.toStdString() << std::endl;
    client.stream << type.toStdString() << std::endl;
    client.stream << description_str << std::endl;
    client.stream << address.toStdString() << std::endl;

    client.stream << std::to_string(latitude) << std::endl;
    client.stream << std::to_string(longitude) << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);

    if (std::stoi(msg_from_server) == SERVER_OK) {
      client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
      return SERVER_OK;
    }
    return NO_CONNECTION;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::update_label_list(Label_List &labelList,
                                          const QString &user_id) {

  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << UPDATE << std::endl;
    client.stream << user_id.toStdString() << std::endl;

    std::string size_;
    std::getline(client.stream, size_);
    int size = stoi(size_);

    labelList.reset();

    for (int i = 0; i < size; i++) {

      std::string id, name, nickname, type, description, address, latitude,
          longitude;

      std::getline(client.stream, id);
      std::getline(client.stream, name);
      std::getline(client.stream, nickname);
      std::getline(client.stream, type);
      std::getline(client.stream, description);
      std::getline(client.stream, address);
      std::getline(client.stream, latitude);
      std::getline(client.stream, longitude);

      for (auto &c : description) {
        if (c == '&') {
          c = '\n';
        }
      }

      Label label(id, name, nickname, type, description, address, latitude,
                  longitude);
      labelList.add(label);
    }

    client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);

    return SERVER_OK;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::sign_in(const QString &nickname,
                                const QString &password, QString &user_id) {

  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << SIGN_IN << std::endl;

    client.stream << nickname.toStdString() << std::endl;
    client.stream << password.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);

    if (std::stoi(msg_from_server) == SERVER_OK) {

      std::string user_id_;
      std::getline(client.stream, user_id_);
      user_id = QString::fromStdString(user_id_);
      client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
      return SERVER_OK;
    } else if (std::stoi(msg_from_server) == SERVER_UNAVAILABLE_NICKNAME) {
      return SERVER_UNAVAILABLE_NICKNAME;
    }
    return SERVER_UNAVAILABLE_PASSWORD;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::sign_up(const QString &nickname,
                                const QString &password, QString &user_id,
                                int &size) {

  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << SIGN_UP << std::endl;

    client.stream << nickname.toStdString() << std::endl;
    client.stream << password.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);
    if (std::stoi(msg_from_server) == SERVER_OK) {

      std::string user_id_;
      std::getline(client.stream, user_id_);
      user_id = QString::fromStdString(user_id_);
      client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);

      return SERVER_OK;
    }

    return SERVER_NICKNAME_EXISTS;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::subscribe(const QString &nickname,
                                  const QString &user_id) {

  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << SUBSCRIBE << std::endl;
    client.stream << nickname.toStdString() << std::endl;
    client.stream << user_id.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);
    if (std::stoi(msg_from_server) == SERVER_OK) {
      client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
      return SERVER_OK;
    }

    return SERVER_WRONG_NICKNAME;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::search_account(const QString &nickname) {
  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << SEARCH_ACCOUNT << std::endl;
    client.stream << nickname.toStdString() << std::endl;

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);
    if (std::stoi(msg_from_server) == SERVER_OK) {
      client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);
      return SERVER_OK;
    }

    return SERVER_WRONG_NICKNAME;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::user_information(const QString &subscribe_name,
                                         QString &lables_size,
                                         QString &subscribes_size) {
  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << USER_INFORMATION << std::endl;
    client.stream << subscribe_name.toStdString() << std::endl;

    std::string lables_size_str, subscribes_size_str;
    std::getline(client.stream, lables_size_str);
    std::getline(client.stream, subscribes_size_str);

    lables_size = QString::fromStdString(lables_size_str);
    subscribes_size = QString::fromStdString(subscribes_size_str);

    std::string msg_from_server;
    std::getline(client.stream, msg_from_server);

    return SERVER_OK;

  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::log_out(const QString &user_id) {
  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << LOG_OUT << std::endl;
    client.stream << user_id.toStdString() << std::endl;
    return SERVER_OK;
  } catch (...) {
    return NO_CONNECTION;
  }
}

server_response Client::update_subscribes(const QString &user_id,
                                          std::vector<std::string> &users) {

  Client client;

  try {
    client.stream.socket().connect(client.ep);
    client.stream << UPDATE_SUBSCRIBES << std::endl;
    client.stream << user_id.toStdString() << std::endl;

    std::string size_;
    std::getline(client.stream, size_);
    int size = stoi(size_);

    users.clear();
    for (int i = 0; i < size; i++) {

      std::string nickname;
      std::getline(client.stream, nickname);
      users.emplace_back(nickname);
    }

    client.stream.socket().shutdown(ip::tcp::socket::shutdown_send);

    return SERVER_OK;
  } catch (...) {
    return NO_CONNECTION;
  }
}
