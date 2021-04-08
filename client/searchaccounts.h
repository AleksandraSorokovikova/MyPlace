#ifndef SEARCHACCOUNTS_H
#define SEARCHACCOUNTS_H

#include <QDialog>
#include<QString>

namespace Ui {
class SearchAccounts;
}

class SearchAccounts : public QDialog
{
    Q_OBJECT

public:
    explicit SearchAccounts(QWidget *parent = nullptr, QString nickname = "");
    ~SearchAccounts();

private slots:
    void on_subscribe_clicked();

private:
    Ui::SearchAccounts *ui;
    QString user_nickname;
};

#endif // SEARCHACCOUNTS_H
