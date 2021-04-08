#include "users.h"

[[nodiscard]] std::string User::create_id(const User_List &label_list) const{
    std::string id_(16, '0');
    const char symbols[37] = { "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"};
    srand(time(NULL));

    for (int i = 0 ; i < 16; i++) {
        char symbol = symbols[rand() % 37];
        id_[i] = symbol;
    }

    while(label_list.id_in_list(id)) {
        int index = rand()%16;
        char symbol = symbols[rand() % 37];
        id_[index] = symbol;
    }
    return id_;
}

[[nodiscard]] bool User_List::id_in_list(const std::string &id) const{
    return id_list.find(id) != id_list.end();
}

[[nodiscard]] bool User_List::nickname_in_list(const std::string &nickname) const {
    return nickname_list.find(nickname) != nickname_list.end();
}

void User_List::add(const User &user) {
    data.insert({user.nickname, user});
    nickname_list.insert(user.nickname);
    id_list.insert(user.id);
}
[[nodiscard]] bool User_List::right_password(const std::string &nickname, const std::string &password) const {
    return data.find(nickname)->second.password == password;
}

void User::subscribe(const std::string &nickname_) {
    subscribes.push_back(nickname_);
}

void User::add_label(const std::string &id_) {
    labels.push_back(id_);
}
