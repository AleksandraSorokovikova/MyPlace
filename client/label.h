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

    Label(std::string name_, std::string nickname_, std::string type_,
          std::string description_, std::string address_, std::string latitude_, std::string longitude_, const Label_List &label_list)
            : name(std::move(name_)), nickname(std::move(nickname_)), type(std::move(type_)),
              description(std::move(description_)), address(std::move(address_)), latitude(std::move(latitude_)), longitude(std::move(longitude_)) {
        id  = create_id(label_list);
    }

    Label(std::string id_, std::string name_, std::string nickname_, std::string type_,
          std::string description_, std::string address_,  std::string latitude_, std::string longitude_) :
            id(std::move(id_)), name(std::move(name_)), nickname(std::move(nickname_)),
            type(std::move(type_)), description(std::move(description_)), address(std::move(address_)),
            latitude(std::move(latitude_)), longitude(std::move(longitude_)){}

    Label() = default;

    [[nodiscard]] std::string create_id(const Label_List &label_list) const;

    friend Label_List;

    std::string id;
    std::string name;
    std::string nickname;
    std::string type;
    std::string description;
    std::string address;

    std::string latitude;
    std::string longitude;
};

struct Label_List {

   [[nodiscard]] bool id_in_list(const std::string &id) const;
   void add(const Label &label);
   void reset();
   Label get_by_id(const std::string &id);

   size_t size();
   std::set<std::string> id_list;

private:
   std::map<std::string, Label> data;

};


#endif //LABEL_LABEL_H
