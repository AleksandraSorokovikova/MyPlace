#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstdlib>
#include <string>
#include "label.h"
#include "users.h"
#include <vector>

struct DataBase {
public:
    DataBase() {
        last_saved = std::chrono::steady_clock::now();
    }
    void save_information(const Label_List& list, const User_List& users) {
        std::ofstream file(FILE_PATH);
        file << "LABEL_LIST_START\n";
        file << list;
        file << "LABEL_LIST_END\n";
        file << "USER_LIST_START\n";
        file << users;
        file << "USER_LIST_END\n";
        file.close();
    }

    bool clock() {
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - last_saved).count() > 300) {
            last_saved = now;
            return true;
        }
        return false;
    }

    void upload_information(Label_List& list, User_List& users) {
        std::ifstream file(FILE_PATH);
        std::string comment;
        getline(file, comment);
        if (comment == "LABEL_LIST_START") {
            while (comment != "LABEL_LIST_END") {
                getline(file, comment);
                list.add(read_label(file));
            }
        }
        getline(file, comment);
        if (comment == "USER_LIST_END") {
            while (comment != "LABEL_LIST_END") {
                getline(file, comment);
                list.add(read_label(file));
                std::vector<std::string> user_field(3);
                for (auto& x : user_field) {
                    getline(file, x);
                }
                getline(file, comment);
                std::set<std::string> subscribes;
                while (comment != "Labels:") {
                    getline(file, comment);
                    if (!comment.empty()) {
                        subscribes.insert(comment);
                    }
                }
                std::vector<std::string> labels;
                while (comment != "EndLabels" ) {
                    getline(file, comment);
                    if (!comment.empty()) {
                        labels.push_back(comment);
                    }
                }
                users.add_user(user_field[1], user_field[0], user_field[2], labels, subscribes);
            }
        }
        file.close();
    }

private:
    const std::string FILE_PATH = "information.txt";
    std::chrono::time_point<std::chrono::steady_clock> last_saved;
    Label read_label(std::ifstream& file) {
        std::vector<std::string> label_field(8);
        for (auto& x : label_field) {
            getline(file, x);
        }
        return Label(label_field[0], label_field[1], label_field[2], label_field[3],
                     label_field[4], label_field[5], label_field[6], label_field[7]);
    };

};


#endif //DATABASE_DATABASE_H
