#include "secondwindow.h"
#include "ui_secondwindow.h"
#include<QPixmap>
#include"createrlabel.h"
#include"openlabel.h"

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
    ui->listWidget->addItem("Meтка");
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
    QString name = creater.name;
    ui->listWidget->addItem(name);
}

void SecondWindow::on_pushButton_2_clicked()
{
     OpenLabel open(ui->listWidget->currentItem()->text());
     open.setModal(true);
     open.exec();
}
