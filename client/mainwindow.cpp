#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "Sign Up", "TODO");
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    window = new SecondWindow(this);
    window->show();
}
