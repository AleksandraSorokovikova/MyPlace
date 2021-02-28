#include "secondwindow.h"
#include "ui_secondwindow.h"
#include<QPixmap>
#include"createrlabel.h"
#include"openlabel.h"
#include"client.h"
#include<QMessageBox>
#include<unistd.h>

Label_List labelList;

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/Карта-2.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui-> image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->update->setIconSize(QSize(35, 35));

    update();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::update(){
    ui->listWidget->clear();
    if (!update_label_list(labelList)) {
        QMessageBox::warning(this, "Failed to connect", "No connection to server");
    } else {
        for(auto x : labelList.id_list) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(labelList.get_by_id(x).name));
            QVariant item_(QString::fromStdString(x));
            item->setData(12, item_);
            ui->listWidget->addItem(item);
        }
    }
}

void SecondWindow::on_pushButton_clicked()
{

    CreaterLabel creater;
    creater.setModal(true);
    creater.exec();
    usleep(300'000);
    update();
}

void SecondWindow::on_update_clicked()
{
    update();
}


void SecondWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
     OpenLabel open(labelList.get_by_id(item->data(12).toString().toStdString().c_str()));
     open.setModal(true);
     open.exec();
}
