#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct User;
struct User_List;

struct User {

  User(std::string nickname_, std::string password_, std::string id_)
      : nickname(std::move(nickname_)), password(std::move(password_)),
        id(std::move(id_)) {}

  void subscribe(const std::string &nickname);
  void add_label(const std::string &id);
  [[nodiscard]] size_t number_of_own_labels() const;
  [[nodiscard]] size_t number_of_subscribes() const;
  [[nodiscard]] bool is_subscribed(const std::string &other_nickname) const;

  std::set<std::string> subscribes{};
  std::vector<std::string> labels{};
  std::string nickname;
  friend User_List;

private:
  std::string password;
  std::string id;
  mutable std::mutex mutex;
};

struct User_List {

  [[nodiscard]] bool id_in_list(const std::string &id) const;
  [[nodiscard]] bool nickname_in_list(const std::string &nickname) const;
  [[nodiscard]] bool check_password(const std::string &nickname,
                                    const std::string &password) const;
  [[nodiscard]] User &get_user_by_nickname(const std::string &nickname);
  [[nodiscard]] std::string create_id() const;
  void add_label_for_current_user(const std::string &nickname,
                                  const std::string &label_id);
  void subscribe_user(const std::string &nickname,
                      const std::string &other_nickname);
  void add(std::string nickname_, std::string password_);

private:
  std::map<std::string, User> data;
  std::set<std::string> nickname_list;
  std::set<std::string> id_list;
};

struct Active_Users {

  [[nodiscard]] std::string get_nickname(const std::string &id) const;
  [[nodiscard]] bool id_exists(const std::string &id) const;
  std::string activate(const std::string &nickname);
  void deactivate(const std::string &id);
  std::string create_id();

private:
  std::map<std::string, std::string> active_users{};
  std::set<std::string> id_list{};
};

#endif // USERS_H
