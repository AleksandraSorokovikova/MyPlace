#include "openlabel.h"
#include "ui_openlabel.h"

OpenLabel::OpenLabel(const Label &label, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenLabel)
{
    ui->setupUi(this);
    Set_field(label);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

OpenLabel::~OpenLabel()
{
    delete ui;
}

void OpenLabel::Set_field(const Label &label) {
    std::string field = (label.name.empty()) ? "empty" : label.name;
    ui->name->setText(QString::fromStdString(field));
    ui->address->setText(QString::fromStdString(label.address));
    ui->nickname->setText("@" + QString::fromStdString(label.nickname));
    ui->description->setReadOnly(true);
    ui->description->setText(QString::fromStdString(label.description));
    QPixmap icon;
    if(label.type == "cafee") {
        icon = QPixmap(":/img/img/fork 2.png");
    }
    if(label.type == "cinema") {
        icon = QPixmap(":/img/img/popcorn.png");
    }
    if(label.type == "club") {
        icon = QPixmap(":/img/img/dj-booth.png");
    }
    if(label.type == "hotels") {
        icon = QPixmap(":/img/img/bed.png");
    }
    if(label.type == "entr") {
        icon = QPixmap(":/img/img/confetti.png");
    }
    if(label.type == "different") {
        icon = QPixmap(":/img/img/more.png");
    }
    ui->type->setIcon(icon);
}

void OpenLabel::on_pushButton_clicked()
{
     hide();
}
