#ifndef OPENLABEL_H
#define OPENLABEL_H

#include <QDialog>
#include"label.h"

namespace Ui {
class OpenLabel;
}

class OpenLabel : public QDialog
{
    Q_OBJECT

public:
    explicit OpenLabel(const Label &label, QWidget *parent = nullptr);
    ~OpenLabel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OpenLabel *ui;
    void Set_field(const Label &label);
};

#endif // OPENLABEL_H
