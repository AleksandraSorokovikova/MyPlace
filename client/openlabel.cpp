#include "openlabel.h"
#include "ui_openlabel.h"

OpenLabel::OpenLabel(const Label &label, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenLabel)
{
    ui->setupUi(this);
    Set_field(label);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    QPixmap pix(":/img/img/cafee.png");
    ui->image->setPixmap(pix.scaled(80, 80, Qt::KeepAspectRatio));
}

OpenLabel::~OpenLabel()
{
    delete ui;
}

void OpenLabel::Set_field(const Label &label) {
    ui->name->setText(QString::fromStdString(label.name));
    ui->address->setText(QString::fromStdString(label.address));
    ui->nickname->setText(QString::fromStdString(label.nickname));
    ui->type->setText(QString::fromStdString(label.type));
    ui->description->setReadOnly(true);
    ui->description->setText(QString::fromStdString(label.description));
}

void OpenLabel::on_pushButton_clicked()
{
     hide();
}
