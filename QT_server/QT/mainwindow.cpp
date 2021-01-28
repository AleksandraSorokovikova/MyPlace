#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

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


void MainWindow::on_pushButton_clicked()
{

    std::string out = output();
    char a[out.length()+1];
    for (unsigned long i = 0; i < out.length()+1; i++) {
        char x = out[i];
        a[i] = x;
    }

    ui->label->setText(a);
}

