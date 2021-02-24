#include "createrlabel.h"
#include "ui_createrlabel.h"
#include "client.h"
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


void CreaterLabel::on_pushButton_clicked()
{
    name = ui->name->text();
    nickname = "@nickname";
    type = "default";
    description = ui->description->text();
    address = ui->address->text();


    add_label(name, nickname, type, description, address);

    hide();
}
