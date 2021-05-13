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
    QPixmap cafee_icon(":/img/img/fork 2.png");
    QPixmap cinema_icon(":/img/img/popcorn.png");
    QPixmap club_icon(":/img/img/dj-booth.png");
    QPixmap hotels_icon(":/img/img/bed.png");
    QPixmap entr_icon(":/img/img/confetti.png");
    QPixmap different_icon(":/img/img/more.png");
    ui->cafee->setIcon(cafee_icon);
    ui->hotels->setIcon(hotels_icon);
    ui->night_club->setIcon(club_icon);
    ui->cinema->setIcon(cinema_icon);
    ui->different->setIcon(different_icon);
    ui->entertainment->setIcon(entr_icon);
}

CreaterLabel::~CreaterLabel()
{
    delete ui;
}


void CreaterLabel::on_pushButton_clicked()
{
    if (ui->name->text() != "" &&  ui->description->toPlainText() != "" && ui->address->text() != "") {
        name = ui->name->text();
        //type = "default";
        description = ui->description->toPlainText();
        address = ui->address->text();

        if (Client::add_label(name, user_id, type, description, address) == NO_CONNECTION){
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

void CreaterLabel::on_cafee_pressed()
{
    type = "cafee";
}

void CreaterLabel::on_hotels_pressed()
{
    type = "hotels";
}

void CreaterLabel::on_night_club_pressed()
{
    type = "club";
}

void CreaterLabel::on_cinema_pressed()
{
    type = "cinema";
}

void CreaterLabel::on_entertainment_pressed()
{
    type = "entr";
}

void CreaterLabel::on_different_pressed()
{
    type = "different";
}
