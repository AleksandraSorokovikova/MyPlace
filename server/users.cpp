#include "users.h"

[[nodiscard]] std::string User_List::create_id() const{
    std::string id_(16, '0');
    const char symbols[37] = { "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"};
    srand(time(NULL));

    for (int i = 0 ; i < 16; i++) {
        char symbol = symbols[rand() % 37];
        id_[i] = symbol;
    }

    while(id_in_list(id_)) {
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

void User_List::add(std::string nickname_, std::string password_) {
    std::string id_ = create_id();
    data.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(nickname_),
            std::forward_as_tuple(nickname_, password_, id_)
            );
    nickname_list.insert(nickname_);
    id_list.insert(id_);
}
[[nodiscard]] bool User_List::check_password(const std::string &nickname, const std::string &password) const {
    return data.find(nickname)->second.password == password;
}

void User_List::add_label_for_current_user(const std::string &nickname, const std::string &label_id) {
    data.find(nickname)->second.add_label(label_id);
}

User & User_List::get_user_by_nickname(const std::string &nickname) {
    return data.find(nickname)->second;
}

void User_List::subscribe_user(const std::string &nickname, const std::string &other_nickname) {
    data.find(nickname)->second.subscribe(other_nickname);
}

void User::subscribe(const std::string &nickname_) {
    std::unique_lock uniqueLock(mutex);
    subscribes.insert(nickname_);
}

void User::add_label(const std::string &id_) {
    std::unique_lock uniqueLock(mutex);
    labels.push_back(id_);
}

size_t User::number_of_own_labels() const {
    std::unique_lock uniqueLock(mutex);
    return labels.size();
}

size_t User::number_of_subscribes() const {
    std::unique_lock uniqueLock(mutex);
    return subscribes.size();
}

bool User::is_subscribed(const std::string &other_nickname) const {
    std::unique_lock uniqueLock(mutex);
    return subscribes.find(other_nickname) != subscribes.end();
}

bool Active_Users::id_exists(const std::string &id) const {
    return id_list.find(id) != id_list.end();
}

std::string Active_Users::create_id() {
    std::string id_(16, '0');
    const char symbols[37] = { "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"};
    srand(time(NULL));

    for (int i = 0 ; i < 16; i++) {
        char symbol = symbols[rand() % 37];
        id_[i] = symbol;
    }

    while(id_exists(id_)) {
        int index = rand()%16;
        char symbol = symbols[rand() % 37];
        id_[index] = symbol;
    }
    return id_;
}

std::string Active_Users::activate(const std::string &nickname) {
    std::string id = create_id();
    active_users.insert({id, nickname});
    return id;
}

void Active_Users::deactivate(const std::string &id) {
    auto user = active_users.find(id);
    active_users.erase(user);
}

std::string Active_Users::get_nickname(const std::string &id) const {
    return active_users.find(id)->second;
}