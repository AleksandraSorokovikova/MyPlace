#include "openlabel.h"
#include "ui_openlabel.h"

OpenLabel::OpenLabel(QString name_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenLabel)
{
    ui->setupUi(this);
    ui->name->setText(name_);
}

OpenLabel::~OpenLabel()
{
    delete ui;
}

void OpenLabel::on_pushButton_clicked()
{
     hide();
}
