#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include<QListWidget>
#include<QMessageBox>

enum class typeListWidget {
    LABELS,
    SUBSCRIBES
};

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

        void on_search_returnPressed();

        void on_my_account_2_clicked();

        void on_logout_clicked();

        void on_subscribes_clicked();

        void on_labels_clicked();

private:
    Ui::MenuWindow *ui;
    void update();
    QString user_id;
    QString nickname;
    typeListWidget type = typeListWidget::LABELS;
};

#endif // MENUWINDOW_H
