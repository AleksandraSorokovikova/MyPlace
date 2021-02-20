#include "secondwindow.h"
#include "ui_secondwindow.h"
#include<QPixmap>
#include"createrlabel.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
     //Qpixmap pix(":/img/img/Карта-2.png");
     //int w = ui->image->width();
     //int h = ui->image->height();
     //ui-> image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
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
    QString name = creater.on_pushButton_clicked();
    ui->listWidget->addItem(name);
}
