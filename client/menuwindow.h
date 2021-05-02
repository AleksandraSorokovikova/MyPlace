#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include<QListWidget>
#include<QMessageBox>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr, QString id = "", QString nickname_ = "");
    ~MenuWindow();

private slots:
    void on_add_label_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_update_clicked();

    void on_search_button_pressed();

    void on_my_account_clicked();

private:
    Ui::MenuWindow *ui;
    void update();
    QString user_id;
    QString nickname;
};

#endif // MENUWINDOW_H
