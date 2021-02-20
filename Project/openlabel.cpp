#include "openlabel.h"
#include "ui_openlabel.h"

OpenLabel::OpenLabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenLabel)
{
    ui->setupUi(this);
}

OpenLabel::~OpenLabel()
{
    delete ui;
}
