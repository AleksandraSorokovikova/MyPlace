#ifndef USERS_H
#define USERS_H


#include <string>
#include <map>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

struct User;
struct User_List;

struct User {

    // конструктор создания нового аккаунта
    User (std::string nickname_, std::string password_, const User_List &userList)
    : nickname(std::move(nickname_)), password(std::move(password_)) {
        id = create_id(userList);
    }

    [[nodiscard]] std::string create_id(const User_List &userList) const;
    void subscribe(const std::string &nickname);
    void add_label(const std::string &id);
    std::string nickname;
    std::string password;
    std::string id;
    std::vector<std::string> subscribes{};
    std::vector<std::string> labels{};


    friend User_List;
};


struct User_List {

    [[nodiscard]] bool id_in_list(const std::string &id) const;
    [[nodiscard]] bool nickname_in_list(const std::string &nickname) const;
    [[nodiscard]] bool right_password(const std::string &nickname, const std::string &password) const;

    //ключ - никнейм
    std::map<std::string, User> data;
    std::set<std::string> id_list;
    std::set<std::string> nickname_list;
    void add(const User &user);
};
#endif // USERS_H
