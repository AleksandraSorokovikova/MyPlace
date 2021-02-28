#include "createrlabel.h"
#include "ui_createrlabel.h"
#include "client.h"
#include<QString>
#include<QMessageBox>
#include<QCloseEvent>


CreaterLabel::CreaterLabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreaterLabel)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

CreaterLabel::~CreaterLabel()
{
    delete ui;
}


void CreaterLabel::on_pushButton_clicked()
{
    if(ui->name->text() != "" &&  ui->description->toPlainText() != "" && ui->address->text() != "") {
        name = ui->name->text();
        nickname = "@nickname";
        type = "default";
        description = ui->description->toPlainText();
        address = ui->address->text();


        if (!add_label(name, nickname, type, description, address)){
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
        }

         hide();
    } else {
        QMessageBox::about(this, "Пустые поля", "Введите все данные");
    }
}

void CreaterLabel::on_pushButton_2_clicked()
{
    hide();
}
