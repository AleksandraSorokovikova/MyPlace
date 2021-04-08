#ifndef CREATERLABEL_H
#define CREATERLABEL_H

#include <QDialog>
#include<QString>

namespace Ui {
class CreaterLabel;

}

class CreaterLabel : public QDialog
{
    Q_OBJECT

public:
    explicit CreaterLabel(QString user_nickname, QWidget *parent = nullptr);
    ~CreaterLabel();
    QString name;
    QString nickname;
    QString type;
    QString description;
    QString address;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreaterLabel *ui;
};

#endif // CREATERLABEL_H
