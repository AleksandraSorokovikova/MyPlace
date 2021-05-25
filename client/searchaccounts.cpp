#include "searchaccounts.h"
#include "ui_searchaccounts.h"
#include"client.h"
#include <QMessageBox>

SearchAccounts::SearchAccounts(QWidget *parent, QString id, QString subscribe_, bool is_serach_) :
    QDialog(parent),
    ui(new Ui::SearchAccounts),
     user_id(id),
    subscribe_name(subscribe_),
    is_search(is_serach_)
{
    ui->setupUi(this);
       ui->nickname->setText(subscribe_name);
       QPixmap icon(":/img/img/user-3.png");
       ui->photo->setIcon(icon);
       QString lables_size, subscribes_size;
        int return_code = Client::user_information(subscribe_name, lables_size,  subscribes_size);
        switch (return_code) {
            case NO_CONNECTION:
                QMessageBox::warning(this, "Failed to connect", "No connection to server");
                break;
            case SERVER_OK:
               ui->label_size->setText(ui->label_size->text() + lables_size);
               ui->subscribes_size->setText(ui->subscribes_size->text() + subscribes_size);
                break;
            }
        if (!is_search) {
            ui->subscribe->hide();
        }

       setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

SearchAccounts::~SearchAccounts()
{
    delete ui;
}


void SearchAccounts::on_subscribe_clicked()
{
    QString nickname = ui->nickname->text();
    if (nickname != "") {
    int return_code = Client::subscribe(nickname, user_id);
    switch (return_code) {
        case NO_CONNECTION:
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
            break;
        case SERVER_WRONG_NICKNAME:
            QMessageBox::about(this, "Unavailable nickname", "Enter new nickname");
            break;
        case SERVER_OK:
            hide();
            break;
        }
    }
    else {
        QMessageBox::about(this, "Empty fields", "Enter all data");
    }
}

void SearchAccounts::on_cancel_clicked()
{
    hide();
}
