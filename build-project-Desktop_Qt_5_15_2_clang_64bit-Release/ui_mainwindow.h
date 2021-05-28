/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *create;
    QFrame *frame;
    QLineEdit *nickname;
    QLineEdit *password;
    QPushButton *signButton;
    QLabel *sign_in;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(470, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/res.jpg)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        create = new QPushButton(centralwidget);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(150, 460, 201, 31));
        create->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"color:#3c3a3a; \n"
"background:transparent; \n"
"font: 19pt \"Avenir next\";\n"
"border-radius:30px;\n"
"border-bottom:1px solid #3c3a3a"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 140, 391, 311));
        frame->setStyleSheet(QString::fromUtf8("background:rgba(243,239,230, 230);\n"
"border-radius:20px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        nickname = new QLineEdit(frame);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(20, 90, 351, 51));
        nickname->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(136, 138, 133, 150);\n"
"color: rgb(85, 87, 83);\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 20px;\n"
"background: rgba(0,0,0,20);"));
        nickname->setFrame(true);
        nickname->setEchoMode(QLineEdit::Normal);
        nickname->setCursorPosition(0);
        nickname->setDragEnabled(false);
        nickname->setClearButtonEnabled(true);
        password = new QLineEdit(frame);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(20, 160, 351, 51));
        password->setMouseTracking(true);
        password->setFocusPolicy(Qt::StrongFocus);
        password->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(136, 138, 133, 150);\n"
"color: rgb(85, 87, 83);\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 20px;\n"
"background: rgba(0,0,0,20);"));
        password->setFrame(true);
        password->setEchoMode(QLineEdit::Password);
        password->setCursorPosition(0);
        password->setDragEnabled(false);
        password->setClearButtonEnabled(true);
        signButton = new QPushButton(frame);
        signButton->setObjectName(QString::fromUtf8("signButton"));
        signButton->setGeometry(QRect(120, 240, 161, 51));
        signButton->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(85, 87, 83);\n"
"font: 24pt \"Avenir next\";\n"
" color:#3c3a3a; \n"
" background:rgba(153, 173, 167,120);\n"
"border-radius:20px;\n"
"text-align: center;"));
        sign_in = new QLabel(frame);
        sign_in->setObjectName(QString::fromUtf8("sign_in"));
        sign_in->setGeometry(QRect(140, 20, 131, 61));
        sign_in->setStyleSheet(QString::fromUtf8(" color:#3c3a3a; \n"
"font: 30pt \"Avenir next\";\n"
" background:transparent; "));
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        create->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "Create new account", nullptr));
        nickname->setInputMask(QString());
        nickname->setText(QString());
        nickname->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
#if QT_CONFIG(statustip)
        password->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        password->setInputMask(QString());
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        signButton->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        sign_in->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
