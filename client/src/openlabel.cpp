#include "include/openlabel.h"
#include "include/icons.h"
#include "ui_openlabel.h"

OpenLabel::OpenLabel(const Label &label, QWidget *parent)
    : QDialog(parent), ui(new Ui::OpenLabel) {
  setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
  ui->setupUi(this);
  Set_field(label);
}

OpenLabel::~OpenLabel() { delete ui; }

void OpenLabel::Set_field(const Label &label) {
  std::string field = (label.name.empty()) ? "empty" : label.name;
  ui->name->setText(QString::fromStdString(field));
  ui->address->setText(QString::fromStdString(label.address));
  ui->nickname->setText("@" + QString::fromStdString(label.nickname));
  ui->description->setReadOnly(true);
  ui->description->setText(QString::fromStdString(label.description));
  QPixmap icon;
  type_icons icons_;
  if (label.type == "cafee") {
    icon = icons_.cafee_icon;
  }
  if (label.type == "cinema") {
    icon = icons_.cinema_icon;
  }
  if (label.type == "club") {
    icon = icons_.club_icon;
  }
  if (label.type == "hotels") {
    icon = icons_.hotels_icon;
  }
  if (label.type == "entr") {
    icon = icons_.entr_icon;
  }
  if (label.type == "different") {
    icon = icons_.different_icon;
  }
  // icon = icons_.SET_ICON(label.type)
  ui->type->setIcon(icon);
}

void OpenLabel::on_exit_clicked() { hide(); }
