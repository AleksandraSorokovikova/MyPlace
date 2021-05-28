#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menuwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_create_clicked();

  void on_signButton_clicked();

private:
  Ui::MainWindow *ui;
  // SecondWindow *window;
  MenuWindow *win;
};
#endif // MAINWINDOW_H
