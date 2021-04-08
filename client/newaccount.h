#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>
#include<QString>
#include"menuwindow.h"

namespace Ui {
class newaccount;
}

class newaccount : public QDialog
{
    Q_OBJECT

public:
    explicit newaccount(QWidget *parent = nullptr);
    ~newaccount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newaccount *ui;
    MenuWindow *win;
};

#endif // NEWACCOUNT_H
