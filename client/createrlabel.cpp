#include "createrlabel.h"
#include "ui_createrlabel.h"
#include "client.h"
#include<QString>
#include<QMessageBox>
#include<QCloseEvent>


CreaterLabel::CreaterLabel(QString id, QWidget *parent) :
    QDialog(parent),
    user_id(id),
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
    if (ui->name->text() != "" &&  ui->description->toPlainText() != "" && ui->address->text() != "") {
        name = ui->name->text();
        type = "default";
        description = ui->description->toPlainText();
        address = ui->address->text();


        if (!Client::add_label(name, user_id, type, description, address)){
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
        }

         hide();
    } else {
        QMessageBox::about(this, "Empty fields", "Insert all data");
    }
}

void CreaterLabel::on_pushButton_2_clicked()
{
    hide();
}
