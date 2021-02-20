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
    explicit OpenLabel(QWidget *parent = nullptr);
    ~OpenLabel();

private:
    Ui::OpenLabel *ui;
};

#endif // OPENLABEL_H
