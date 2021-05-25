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

//структура с конкретным пользователем
struct User {

    // конструктор создания нового аккаунта
    User (std::string nickname_, std::string password_, const User_List &userList)
    : nickname(std::move(nickname_)), password(std::move(password_)) {
        id = create_id(userList);
    }

    [[nodiscard]] std::string create_id(const User_List &userList) const;
    void subscribe(const std::string &nickname, size_t size);
    void add_label(const std::string &id);
    [[nodiscard]] size_t own_labels() const;
    [[nodiscard]] bool is_subscribed(const std::string &other_nickname) const;
    std::string nickname;
    std::string password;
    std::string id;
    std::set<std::string> subscribes{};
    std::vector<std::string> labels{};
    size_t number_of_labels;

    friend User_List;
};


//структура со всееееми пользователями, создавшими аккаунт
struct User_List {

    [[nodiscard]] bool id_in_list(const std::string &id) const;
    [[nodiscard]] bool nickname_in_list(const std::string &nickname) const;
    [[nodiscard]] bool right_password(const std::string &nickname, const std::string &password) const;
    void add_label_for_current_user(const std::string &nickname, const std::string &label_id);
    [[nodiscard]] User get_user_by_nickname(const std::string &nickname) const;

    //ключ - никнейм
    std::map<std::string, User> data;
    std::set<std::string> id_list;
    std::set<std::string> nickname_list;
    void add(const User &user);
};

//структура активных пользователей (пользователь входит - добавляется, выходит - удаляется)
struct Active_Users {

    //ключ - id, который генерирует сервер при каждом входе пользователя
    //значение - его никнейм
    std::map<std::string, std::string> active_users{};
    std::set<std::string> id_list{};

    //возвращает количество подключенных пользователей
    int number_of_active_users() const;

    //возвращает true, если такой id уже существует
    bool id_in_list(const std::string &id) const;

    //добавляет в список нового пользователя, возвращает сгенерированный id
    std::string activate(const std::string &nickname);

    //удаляет из списка пользователя
    void deactivate(const std::string &id);

    //генерирует id для подключившегося пользователя
    std::string create_id();

    std::string get_nickname(const std::string &id) const;

    void print_active_users() {
        int cnt = 1;
        for (auto x : active_users) {
            std::cout << cnt << ": {" << x.first << ", " << x.second << "}" << '\n';
        }
    }
};

#endif // USERS_H
