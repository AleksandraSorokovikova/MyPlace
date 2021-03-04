#include "menuwindow.h"
#include "ui_menuwindow.h"
#include"openlabel.h"
#include"createrlabel.h"
#include"client.h"
#include<QMessageBox>
#include<unistd.h>
#include<QPixmap>

Label_List labelList;

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
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
    CreaterLabel creater;
    creater.setModal(true);
    creater.exec();
    usleep(300'000);
    update();
}

void MenuWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    OpenLabel open(labelList.get_by_id(item->data(12).toString().toStdString().c_str()));
    open.setModal(true);
    open.exec();
}
