#ifndef CREATERLABEL_H
#define CREATERLABEL_H

#include <QDialog>
#include<QString>
#include<QGeoCoordinate>

namespace Ui {
class CreaterLabel;

}

class CreaterLabel : public QDialog
{
    Q_OBJECT

public:
    explicit CreaterLabel(QString user_nickname, QGeoCoordinate coordinate = QGeoCoordinate(0, 0),
                          QString address = "default", QWidget *parent = nullptr);
    ~CreaterLabel();
    QString user_id;
    QString type = "default";
    QGeoCoordinate coordinates;

private slots:
    void on_create_clicked();

    void on_cancel_clicked();

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
