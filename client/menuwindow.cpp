#include "menuwindow.h"
#include "ui_menuwindow.h"
#include"openlabel.h"
#include"createrlabel.h"
#include"client.h"
#include"searchaccounts.h"
#include<QMessageBox>
#include<unistd.h>
#include<QPixmap>
#include "mainwindow.h"

Label_List labelList;

MenuWindow::MenuWindow(QWidget *parent, QString id, QString nickname_) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow), user_id(id), nickname(nickname_)
{
    ui->setupUi(this);
        QPixmap pix(":/img/img/mapss.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        QPixmap search_icon(":/img/img/search.png");
        ui->search_button->setIcon(search_icon);
        QPixmap update_icon(":/img/img/refresh.png");
        ui->update->setIcon(update_icon);
        QPixmap logout_icon(":/img/img/log-out.png");
        ui->logout->setIcon(logout_icon);
        QPixmap edit_icon(":/img/img/edit.png");
        ui->my_account_2->setIcon(edit_icon);
        QPixmap add_icon(":/img/img/add.png");
        ui->add_label->setIcon(add_icon);
        update();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::update(){
    if (Client::update_label_list(labelList, user_id) == NO_CONNECTION) {
        QMessageBox::warning(this, "Failed to connect", "No connection to server");
    } else {
        ui->listWidget->clear();
        for(const auto &x : labelList.id_list) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(labelList.get_by_id(x).name));
            QVariant item_(QString::fromStdString(x));
            item->setData(12, item_);

            ui->listWidget->addItem(item);
        }
    }
}

void MenuWindow::on_add_label_clicked()
{
    CreaterLabel creater(user_id);
    creater.setModal(true);
    creater.exec();
    update();
}

void MenuWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {

    OpenLabel open(labelList.get_by_id(item->data(12).toString().toStdString()));
    open.setModal(true);
    open.exec();
}


void MenuWindow::on_update_clicked()
{
    update();
}

void MenuWindow::on_search_button_pressed()
{
    QString nickname(ui->search->text());
        if (nickname != "") {
        int return_code = Client::search_account(nickname);
        switch (return_code) {
            case NO_CONNECTION:
                QMessageBox::warning(this, "Failed to connect", "No connection to server");
                break;
            case SERVER_WRONG_NICKNAME:
                QMessageBox::about(this, "Unavailable nickname", "Enter new nickname");
                break;
            case SERVER_OK:
                SearchAccounts search(nullptr, user_id, nickname);
                search.setModal(true);
                search.exec();
                update();
            }
        }
        else {
            QMessageBox::about(this, "Empty fields", "Enter all data");
        }
}


void MenuWindow::on_search_returnPressed()
{
    on_search_button_pressed();
}

void MenuWindow::on_my_account_2_clicked()
{
     QMessageBox::about(this, "nickname", nickname);
}

void MenuWindow::on_logout_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Log out", "Sign out of account?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          /* Тут часть Саши с Выходом из аккаунта*/
          hide();
          MainWindow* log_out = new MainWindow(this);
          log_out->show();
      }
}
