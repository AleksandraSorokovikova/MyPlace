#include "menuwindow.h"
#include "ui_menuwindow.h"
#include"openlabel.h"
#include"createrlabel.h"
#include"client.h"
#include"searchaccounts.h"
#include<QMessageBox>
#include<unistd.h>
#include<QPixmap>
#include "mainwindow.h"
#include <QGeoCoordinate>
#include "icons.h"

Label_List labelList;
std::vector<std::string> users;

MenuWindow::MenuWindow(QWidget *parent, QString id, QString nickname_) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow), user_id(id), nickname(nickname_)
{
    ui->setupUi(this);
    menu_icons icons;
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(icons.pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->search_button->setIcon(icons.search_icon);
    ui->update->setIcon(icons.update_icon);
    ui->logout->setIcon(icons.logout_icon);
    ui->my_account_2->setIcon(icons.edit_icon);
    ui->add_label->setIcon(icons.add_icon);
    model = new MarkerModel();
    model->set_user(user_id);
    map = new QQuickWidget(this);
    map->rootContext()->setContextProperty("markerModel", model);
    map->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    ui->gridLayout->addWidget(map, 1, 0);
    update();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::update() {
    if(type == typeListWidget::LABELS) {
        if (Client::update_label_list(labelList, user_id) == NO_CONNECTION) {
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
        } else {
         ui->listWidget->clear();
         model->m_coordinates.clear();
         model->labels_on_coordinate.clear();
            for(const auto &x : labelList.id_list) {
                Label label = labelList.get_by_id(x);
                QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(label.name));
                if (std::stod(label.longitude) == 0) {
                    model->address = QString::fromStdString(label.address);
                    model->changeGeocode();
                    model->insertMarker(model->coordinate);
                    model->address = "default";
                } else {
                    model->insertMarker(QGeoCoordinate(std::stod(label.longitude), std::stod(label.latitude)));
                }
                model->labels_on_coordinate[QString::fromStdString(label.address)] = label;
                QVariant item_(QString::fromStdString(x));
                item->setData(12, item_);
                ui->listWidget->addItem(item);
            }
        }
    } else {
        if (Client::update_subscribes(user_id, users) == NO_CONNECTION) {
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
        } else {
            ui->listWidget->clear();
            for (const auto &user : users) {
                QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(user));
                 ui->listWidget->addItem(item);
            }
        }
    }
}

void MenuWindow::on_add_label_clicked()
{
    model->addMarker();
    update();
}

void MenuWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (type == typeListWidget::LABELS) {
        OpenLabel open(labelList.get_by_id(item->data(12).toString().toStdString()));
        open.setModal(true);
        open.exec();
    } else {
        SearchAccounts search(nullptr, user_id, item->text(), false);
        search.setModal(true);
        search.exec();
    }
}


void MenuWindow::on_update_clicked()
{
    update();
}

void MenuWindow::on_search_button_pressed()
{
    QString nickname(ui->search->text());
        if (nickname != "") {
        int return_code = Client::search_account(nickname);
        switch (return_code) {
            case NO_CONNECTION:
                QMessageBox::warning(this, "Failed to connect", "No connection to server");
                break;
            case SERVER_WRONG_NICKNAME:
                QMessageBox::about(this, "Unavailable nickname", "Enter new nickname");
                break;
            case SERVER_OK:
                SearchAccounts search(nullptr, user_id, nickname);
                search.setModal(true);
                search.exec();
                update();
            }
        }
        else {
            QMessageBox::about(this, "Empty fields", "Enter all data");
        }
}


void MenuWindow::on_search_returnPressed()
{
    on_search_button_pressed();
}

void MenuWindow::on_my_account_2_clicked()
{
    SearchAccounts search(nullptr, user_id, nickname, false);
    search.setModal(true);
    search.exec();
}

void MenuWindow::on_logout_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Log out", "Sign out of account?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {

          [[maybe_unused]] int return_code = Client::log_out(user_id);

          hide();
          MainWindow* log_out = new MainWindow(this);
          log_out->show();
      }
}

void MenuWindow::on_subscribes_clicked() {
    type = typeListWidget::SUBSCRIBES;
    update();
}

void MenuWindow::on_labels_clicked()
{
    type = typeListWidget::LABELS;
    update();
}
