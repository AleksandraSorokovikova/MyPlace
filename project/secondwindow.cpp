#include "secondwindow.h"
#include "ui_secondwindow.h"
#include<QPixmap>
#include"createrlabel.h"
#include"openlabel.h"
#include"client.h"
#include<QMessageBox>

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
    //list = new QListWidget(this);
    //ui->listWidget->addItem("Meтка");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    CreaterLabel creater;
    creater.setModal(true);
    creater.exec();
    //QString name = creater.name;
    //ui->listWidget->addItem(name);
}

void SecondWindow::on_pushButton_2_clicked()
{
     OpenLabel open(labelList.get_by_id(ui->listWidget->currentItem()->text().toStdString().c_str()));
     open.setModal(true);
     open.exec();
}

void SecondWindow::on_toolButton_clicked()
{
    ui->listWidget->clear();
    update_label_list(labelList);
    for(auto x : labelList.id_list) {
        ui->listWidget->addItem(QString::fromStdString(x));
    }
}
