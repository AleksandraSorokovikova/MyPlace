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
    //QString nickname;
    QString type;
    QString description;
    QString address;
    QString user_id;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_cafee_pressed();

    void on_hotels_pressed();

    void on_night_club_pressed();

    void on_cinema_pressed();

    void on_entertainment_pressed();

    void on_different_pressed();

private:
    Ui::CreaterLabel *ui;
};

#endif // CREATERLABEL_H
