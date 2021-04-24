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
    explicit MenuWindow(QWidget *parent = nullptr, QString nickname = "");
    ~MenuWindow();

private slots:
    void on_add_label_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_search_account_clicked();

private:
    Ui::MenuWindow *ui;
    void update();
    QString user_id;
};

#endif // MENUWINDOW_H
