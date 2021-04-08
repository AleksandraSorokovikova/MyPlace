#include "label.h"

[[nodiscard]] std::string Label::create_id(const Label_List &label_list) const{
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

void Label::print_label() {
    std::cout << '\n';
    std::cout << "    id: " << id << '\n';
    std::cout << "    name: " << name << '\n';
    std::cout << "    nickname: " << nickname << '\n';
    std::cout << "    type: " << type << '\n';
    std::cout << "    description: " << description<< '\n';
    std::cout << "    address: " << address << '\n';
    std::cout << '\n';
}


Label Label_List::get_by_id(const std::string &id){
    return data[id];
}


[[nodiscard]] bool Label_List::id_in_list(const std::string &id) const{
    return id_list.find(id) != id_list.end();
}

void Label_List::add(const Label &label) {
    data.insert({label.id, label});
    id_list.insert(label.id);
}

void Label_List::reset() {
    data.clear();
    id_list.clear();
}

void Label_List::print_labels() {
    for (auto x : data) {
        x.second.print_label();
    }
}

size_t Label_List::size() {
    return data.size();
}

