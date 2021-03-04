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
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_add_label_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MenuWindow *ui;
    void update();
};

#endif // MENUWINDOW_H
