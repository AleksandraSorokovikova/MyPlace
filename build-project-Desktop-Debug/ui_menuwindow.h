/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QLabel *image;
    QListWidget *listWidget;
    QPushButton *add_label;
    QMenuBar *menubar;
    QMenu *menuggjj;
    QMenu *menuLog_Out;
    QMenu *menuUpdate;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QString::fromUtf8("MenuWindow"));
        MenuWindow->resize(891, 652);
        MenuWindow->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"text-align: right;\n"
"background: gray;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"     spacing: 3px; /* \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\320\265\320\266\320\264\321\203 \320\277\321\203\320\275\320\272\321\202\320\260\320\274\320\270 \320\274\320\265\320\275\321\216 */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
"	color: white;\n"
"text-align: right;\n"
"	font: 0 9pt \"Gayathri\";\n"
" }\n"
"\n"
" QMenuBar::item:selected { /* \320\272\320\276\320\263\320\264\320\260 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\276 \321\201 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\274\321\213\321\210\320\270 \320\270\320\273\320\270 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213 */\n"
"     background: #a8a8a8;\n"
" }\n"
"\n"
" QMenuBar::item:pressed {\n"
"     background: #888888;\n"
" }\n"
"\n"
"*{\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1"
                        ", y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255))\n"
"}\n"
""));
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(60, 0, 911, 641));
        image->setPixmap(QPixmap(QString::fromUtf8(":/img/img/mapss.png")));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 261, 641));
        listWidget->setStyleSheet(QString::fromUtf8(" QListWidget::item:selected {\n"
"     border: 1px solid rgb(243,239,230);\n"
" }\n"
"\n"
"QListWidget::item {\n"
"color:rgb(243,239,230);\n"
"	font: 14pt \"Gayathri\";\n"
"}\n"
"\n"
""));
        add_label = new QPushButton(centralwidget);
        add_label->setObjectName(QString::fromUtf8("add_label"));
        add_label->setGeometry(QRect(830, 570, 51, 51));
        add_label->setStyleSheet(QString::fromUtf8("border-radius: 25px;\n"
"border: 1px solid gray;\n"
"color: rgb(46, 52, 54);\n"
"background: rgba(128,221,190, 200);\n"
"font: 40pt \"Ubuntu\";"));
        MenuWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 891, 19));
        menuggjj = new QMenu(menubar);
        menuggjj->setObjectName(QString::fromUtf8("menuggjj"));
        menuLog_Out = new QMenu(menubar);
        menuLog_Out->setObjectName(QString::fromUtf8("menuLog_Out"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        MenuWindow->setMenuBar(menubar);

        menubar->addAction(menuggjj->menuAction());
        menubar->addAction(menuLog_Out->menuAction());
        menubar->addAction(menuUpdate->menuAction());

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MainWindow", nullptr));
        image->setText(QString());
        add_label->setText(QApplication::translate("MenuWindow", "+", nullptr));
        menuggjj->setTitle(QApplication::translate("MenuWindow", "Update", nullptr));
        menuLog_Out->setTitle(QApplication::translate("MenuWindow", "Edit Profile", nullptr));
        menuUpdate->setTitle(QApplication::translate("MenuWindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
