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
    explicit CreaterLabel(QWidget *parent = nullptr);
    ~CreaterLabel();
    QString name;

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreaterLabel *ui;
};

#endif // CREATERLABEL_H
