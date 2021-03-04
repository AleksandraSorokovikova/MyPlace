/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QFrame *frame;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(478, 601);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 15pt \"Gayathri\";\n"
"background-image: url(:/img/img/res.jpg)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 480, 251, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8(" font-weight:bold; \n"
" color:#3c3a3a; \n"
" background:transparent; \n"
"font: 20pt \"Gayathri\";\n"
"border-radius:30px;\n"
"border-bottom:1px solid #3c3a3a"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(50, 140, 391, 311));
        frame->setStyleSheet(QString::fromUtf8("background:rgba(243,239,230, 230);\n"
"border-radius:20px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 90, 351, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(136, 138, 133);\n"
"color: rgb(85, 87, 83);\n"
"font: 16pt \"Gayathri\";;\n"
"border-radius: 20px;\n"
"padding: 0 8px;\n"
"background: rgba(0,0,0,20);\n"
"selection-background-color: darkgray;"));
        lineEdit->setFrame(true);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setCursorPosition(0);
        lineEdit->setDragEnabled(false);
        lineEdit->setClearButtonEnabled(true);
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 160, 351, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(136, 138, 133);\n"
"color: rgb(85, 87, 83);\n"
"font: 16pt \"Gayathri\";;\n"
"border-radius: 20px;\n"
"padding: 0 8px;\n"
"background: rgba(0,0,0,20);\n"
"selection-background-color: darkgray;"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_2->setCursorPosition(0);
        lineEdit_2->setDragEnabled(false);
        lineEdit_2->setClearButtonEnabled(true);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 240, 161, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(85, 87, 83);\n"
"font: 22pt \"Gayathri\";\n"
" font-weight:bold; \n"
" color:#3c3a3a; \n"
" background:rgba(153, 173, 167,227);\n"
"border-radius:20px;\n"
"text-align: center;"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 20, 131, 61));
        label_2->setStyleSheet(QString::fromUtf8(" color:#3c3a3a; \n"
"font: 30pt \"Gayathri\";\n"
" background:transparent; "));
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        pushButton_2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Create new account", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Username:", nullptr));
        lineEdit_2->setInputMask(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "Password:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Sign in", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
