#include "label.h"

[[nodiscard]] std::string Label::create_id(const Label_List &label_list) const{
    std::string id_(16, '0');
    const char symbols[37] = { "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"};
    srand(time(NULL));

    for (int i = 0 ; i < 16; i++) {
        char symbol = symbols[rand() % 38];
        id_[i] = symbol;
    }

    while(label_list.id_in_list(id_)) {
        int index = rand()%16;
        char symbol = symbols[rand() % 38];
        id_[index] = symbol;
    }
    return id_;
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


size_t Label_List::size() {
    return data.size();
}

Label Label_List::get_by_id(const std::string &id){
    return data.find(id)->second;
}



