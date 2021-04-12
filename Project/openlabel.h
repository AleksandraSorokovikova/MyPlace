#ifndef OPENLABEL_H
#define OPENLABEL_H

#include <QDialog>

namespace Ui {
class OpenLabel;
}

class OpenLabel : public QDialog
{
    Q_OBJECT

public:
    explicit OpenLabel(QString name_, QWidget *parent = nullptr);
    ~OpenLabel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OpenLabel *ui;
    void SetName(QString name_);
};

#endif // OPENLABEL_H
