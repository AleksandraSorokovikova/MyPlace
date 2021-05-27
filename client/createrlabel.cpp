#include "createrlabel.h"
#include "ui_createrlabel.h"
#include "client.h"
#include<QString>
#include<QMessageBox>
#include<QCloseEvent>
#include "icons.h"

CreaterLabel::CreaterLabel(QString id, QGeoCoordinate coordinate, QString address, QWidget *parent) :
    QDialog(parent),
    user_id(id),
    coordinates(coordinate),
    ui(new Ui::CreaterLabel) {
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    type_icons icons_;
    ui->setupUi(this);
    ui->cafee->setIcon(icons_.cafee_icon);
    ui->hotels->setIcon(icons_.hotels_icon);
    ui->night_club->setIcon(icons_.club_icon);
    ui->cinema->setIcon(icons_.cinema_icon);
    ui->different->setIcon(icons_.different_icon);
    ui->entertainment->setIcon(icons_.entr_icon);
    if (address != "default") {
        ui->address->setText(address);
    }
}

CreaterLabel::~CreaterLabel()
{
    delete ui;
}


void CreaterLabel::on_create_clicked()
{
    if (ui->name->text() != "" &&  ui->description->toPlainText() != "" && ui->address->text() != "" && type != "default") {
        QString name = ui->name->text();
        QString description = ui->description->toPlainText();
        QString address = ui->address->text();
        if (Client::add_label(name, user_id, type, description, address, coordinates.latitude(), coordinates.longitude()) == NO_CONNECTION){
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
        }
         hide();
    } else {
        QMessageBox::about(this, "Empty fields", "Insert all data");
    }
}

void CreaterLabel::on_cancel_clicked()
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
