#include "createrlabel.h"
#include "ui_createrlabel.h"
#include<QString>

CreaterLabel::CreaterLabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreaterLabel)
{
    ui->setupUi(this);
}

CreaterLabel::~CreaterLabel()
{
    delete ui;
}

QString CreaterLabel::on_pushButton_clicked()
{
    QString name = ui->login->text();
    QString ad = ui->address->text();
    return name;
}
