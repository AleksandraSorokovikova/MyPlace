#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "menuwindow.h"
#include "client.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    new_accoount = new newaccount(this);
    new_accoount->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString nickname = ui->nickname->text();
    QString password = ui->password->text();
    if (nickname != "" &&  password != "") {
    int return_code = Client::sing_in(nickname, password);
    switch (return_code) {
        case 0:
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
            break;
        case 1:
            QMessageBox::about(this, "Unavailable nickname", "Enter another nickname");
            break;
        case 2:
            QMessageBox::about(this, "Unavailable password", "Enter another password");
            break;
        case 3:
            hide();
            win = new MenuWindow(this, nickname);
            win->show();
        break;
        }
    }
    else {
        QMessageBox::about(this, "Empty fields", "Insert all data");
    }
}
