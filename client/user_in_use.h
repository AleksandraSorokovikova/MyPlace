#ifndef USER_IN_USE_H
#define USER_IN_USE_H

#include <string>

struct User_in_use {

    User_in_use (std::string nickname_, std::string subscribes_, std::string labels_) :
        nickname(std::move(nickname_)), subscribes(std::move(subscribes_)), labels(std::move(labels_)) {}

    std::string nickname;
    std::string subscribes;
    std::string labels;
};




#endif // USER_IN_USE_H
