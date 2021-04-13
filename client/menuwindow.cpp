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

MenuWindow::MenuWindow(QWidget *parent, QString id) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow), user_id(id)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/mapss.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    update();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::update(){
    if (!Client::update_label_list(labelList)) {
        QMessageBox::warning(this, "Failed to connect", "No connection to server");
    } else {
        ui->listWidget->clear();
        for(auto x : labelList.id_list) {
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
    //usleep(300'000);
    update();
}

void MenuWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    OpenLabel open(labelList.get_by_id(item->data(12).toString().toStdString().c_str()));
    open.setModal(true);
    open.exec();
}

void MenuWindow::on_search_account_clicked()
{
    SearchAccounts search(nullptr, user_id);
    search.setModal(true);
    search.exec();
}

void MenuWindow::on_pushButton_clicked()
{
    QMessageBox::about(this, "My id", user_id);
}
