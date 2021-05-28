#ifndef USERS_H
#define USERS_H

#include <string>
#include <map>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <mutex>


struct User;
struct User_List;

struct User {

    User (std::string nickname_, std::string password_, std::string id_)
    : nickname(std::move(nickname_)), password(std::move(password_)), id(std::move(id_)) {}
    User() = default;

    User (std::string  id_, std::string  nickname_, std::string  password_,
          std::vector<std::string>  labels_, std::set<std::string>  subscribes_)
            : nickname(std::move(nickname_)), password(std::move(password_)), id(std::move(id_)), subscribes(std::move(subscribes_)), labels(std::move(labels_)) {}

    void subscribe(const std::string &nickname);
    void add_label(const std::string &id);
    [[nodiscard]] size_t number_of_own_labels() const;
    [[nodiscard]] size_t number_of_subscribes() const;
    [[nodiscard]] bool is_subscribed(const std::string &other_nickname) const;

    std::set<std::string> subscribes{};
    std::vector<std::string> labels{};
    std::string nickname;
    friend User_List;
    friend std::ostream& operator<< (std::ostream &out, const User &user);

private:
    std::string password;
    std::string id;
    mutable std::mutex mutex;

};

std::ostream& operator<< (std::ostream &out, const User &user);

struct User_List {

    [[nodiscard]] bool id_in_list(const std::string &id) const;
    [[nodiscard]] bool nickname_in_list(const std::string &nickname) const;
    [[nodiscard]] bool check_password(const std::string &nickname, const std::string &password) const;
    [[nodiscard]] User & get_user_by_nickname(const std::string &nickname);
    [[nodiscard]] std::string create_id() const;
    void add_label_for_current_user(const std::string &nickname, const std::string &label_id);
    void subscribe_user(const std::string &nickname, const std::string &other_nickname);
    void add(std::string nickname_, std::string password_);
    void add_user(const std::string& id, const std::string& nickname, const std::string& password,
                             const std::vector<std::string>& labels, const std::set<std::string>& subscribes);
    friend std::ostream& operator<< (std::ostream &out, const User_List &users);

private:
    std::map<std::string, User> data;
    std::set<std::string> nickname_list;
    std::set<std::string> id_list;

};

std::ostream& operator<< (std::ostream &out, const User_List &users);

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
