#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include<QMenuBar>
#include<QListWidget>
#include<QPixmap>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SecondWindow *ui;
    //QListWidget *list;
};

#endif // SECONDWINDOW_H
