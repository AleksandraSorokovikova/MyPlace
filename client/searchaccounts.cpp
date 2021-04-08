#include "searchaccounts.h"
#include "ui_searchaccounts.h"
#include"client.h"
#include <QMessageBox>

SearchAccounts::SearchAccounts(QWidget *parent, QString nickname) :
    QDialog(parent),
    ui(new Ui::SearchAccounts),
     user_nickname(nickname)
{
    ui->setupUi(this);
}

SearchAccounts::~SearchAccounts()
{
    delete ui;
}

void SearchAccounts::on_subscribe_clicked()
{
    QString nickname = ui->nickname->text();
    if (nickname != "") {
    int return_code = Client::subscribe(nickname, user_nickname);
    switch (return_code) {
        case 0:
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
            break;
        case 1:
            QMessageBox::about(this, "Unavailable nickname", "Enter new nickname");
            break;
        case 2:
            hide();
            break;
        }
    }
    else {
        QMessageBox::about(this, "Empty fields", "Enter all data");
    }
}
