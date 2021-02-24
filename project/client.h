#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include<QString>
#include"label.h"
#define BUFFER_SIZE 1024

void convert(std::vector<char> &c, const std::string &s);
void convert(std::vector<char> &c, const QString &qs);
void add_label(const QString &name, const QString &nickname, const QString &type, const QString &description, const QString &address);
void update_label_list(Label_List &labelList);

#endif // CLIENT_H

