#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    if(ui->sign_in->text() == "Sign in") {
        ui->sign_in->setText("Sign up");
        ui->pushButton_2->setText("Already have account");
        ui->pushButton->setText("Sign up");
    } else {
        ui->sign_in->setText("Sign in");
        ui->pushButton_2->setText("Create new account");
        ui->pushButton->setText("Sign in");
    }
    ui->nickname->clear();
    ui->password->clear();
}

void MainWindow::on_pushButton_clicked()
{
    QString nickname = ui->nickname->text();
    QString password = ui->password->text();
    QString user_id{};
    if (nickname != "" &&  password != "") {
        if (ui->sign_in->text() == "Sign in") {
            int return_code = Client::sing_in(nickname, password, user_id);
            switch (return_code) {
            case NO_CONNECTION:
                QMessageBox::warning(this, "Failed to connect", "No connection to server");
                break;
            case SERVER_UNAVAILABLE_NICKNAME:
                ui->statusBar->showMessage("Enter another nickname");
                ui->nickname->clear();
                ui->password->clear();
                break;
            case SERVER_UNAVAILABLE_PASSWORD:
                ui->statusBar->showMessage("Enter another password");
                ui->password->clear();
                break;
            case SERVER_OK:
                hide();
                win = new MenuWindow(this, user_id, nickname);
                win->show();
            break;
            }
        }
            else {
                QString user_id{};
                int size;
                int return_code = Client::sing_up(nickname, password, user_id, size);
                switch (return_code) {
                    case NO_CONNECTION:
                        QMessageBox::warning(this, "Failed to connect", "No connection to server");
                        break;
                    case SERVER_NICKNAME_EXISTS:
                        ui->statusBar->showMessage("Nickname is already in use");
                        break;
                    case SERVER_OK:
                        hide();
                        win = new MenuWindow(this, user_id, nickname);
                        win->show();
                    break;
                }
            }
    }
    else {
        ui->statusBar->showMessage("Insert all data");
    }
}
