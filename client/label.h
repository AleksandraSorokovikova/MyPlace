#ifndef LABEL_LABEL_H
#define LABEL_LABEL_H

#include <string>
#include <map>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

struct Label;
struct Label_List;

struct Label {


    Label() = default;
    //конструктор для создания новых меток
    Label(std::string name_, std::string nickname_, std::string type_,
          std::string description_, std::string address_, const Label_List &label_list)
            : name(std::move(name_)), nickname(std::move(nickname_)), type(std::move(type_)),
              description(std::move(description_)), address(std::move(address_)) {
        id  = create_id(label_list);
    }

    //конструктор для создания уже существующих меток (у которых есть id)
    Label(std::string id_, std::string name_, std::string nickname_, std::string type_,
          std::string description_, std::string address_) :
            id(std::move(id_)), name(std::move(name_)), nickname(std::move(nickname_)),
            type(std::move(type_)), description(std::move(description_)), address(std::move(address_)) {}

    [[nodiscard]] std::string create_id(const Label_List &label_list) const;
    void print_label();

    friend Label_List;

    std::string id;
    std::string name;
    std::string nickname;
    std::string type;
    std::string description;
    std::string address;
};

struct Label_List {

   [[nodiscard]] bool id_in_list(const std::string &id) const;
   void add(const Label &label);
   void reset();
   void print_labels();

   Label get_by_id(const std::string &id);
    size_t size();

    std::map<std::string, Label> data;
    std::set<std::string> id_list;
};


#endif //LABEL_LABEL_H
