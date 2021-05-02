#include "menuwindow.h"
#include "ui_menuwindow.h"
#include"openlabel.h"
#include"createrlabel.h"
#include"client.h"
#include"searchaccounts.h"
#include<QMessageBox>
#include<unistd.h>
#include<QPixmap>

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
    QPixmap folderbutt(":/img/img/search.png");
    ui->search_button->setIcon(folderbutt);
    QPixmap folderbut(":/img/img/refresh.png");
    ui->update->setIcon(folderbut);
    update();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::update(){
    if (Client::update_label_list(labelList, user_id) == 0) {
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
    SearchAccounts search(nullptr, user_id, ui->search->text());
    search.setModal(true);
    search.exec();
    update();
}

void MenuWindow::on_my_account_clicked()
{
    QMessageBox::about(this, "nickname", nickname);
}

void MenuWindow::on_search_returnPressed()
{
    on_search_button_pressed();
}
