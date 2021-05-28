/********************************************************************************
** Form generated from reading UI file 'searchaccounts.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHACCOUNTS_H
#define UI_SEARCHACCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchAccounts
{
public:
    QPushButton *subscribe;
    QLabel *nickname;
    QPushButton *cancel;
    QPushButton *photo;
    QLabel *label_size;
    QLabel *subscribes_size;

    void setupUi(QDialog *SearchAccounts)
    {
        if (SearchAccounts->objectName().isEmpty())
            SearchAccounts->setObjectName(QString::fromUtf8("SearchAccounts"));
        SearchAccounts->resize(250, 163);
        SearchAccounts->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255))"));
        subscribe = new QPushButton(SearchAccounts);
        subscribe->setObjectName(QString::fromUtf8("subscribe"));
        subscribe->setGeometry(QRect(160, 120, 71, 31));
        subscribe->setStyleSheet(QString::fromUtf8("color:rgb(42, 44, 42);\n"
"border: 1px solid rgb(85, 87, 83);\n"
"border-radius: 15px;\n"
"background:rgba(243,239,230, 200);\n"
"border: 1px solid gray;\n"
"font: 100 12pt \"Avenir next\";\n"
"border-color:rgb(183, 180, 200);"));
        nickname = new QLabel(SearchAccounts);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(120, 10, 151, 31));
        nickname->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(85, 87, 83);\n"
"font: 25pt \"Avenir next\";\n"
""));
        cancel = new QPushButton(SearchAccounts);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(80, 120, 71, 31));
        cancel->setStyleSheet(QString::fromUtf8("color:rgb(42, 44, 42);\n"
"border: 1px solid rgb(85, 87, 83);\n"
"border-radius: 15px;\n"
"background:rgba(243,239,230, 200);\n"
"border: 1px solid gray;\n"
"font: 100 12pt \"Avenir next\";\n"
"border-color:rgb(183, 180, 200);\n"
""));
        photo = new QPushButton(SearchAccounts);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(10, 10, 91, 91));
        photo->setStyleSheet(QString::fromUtf8("background: rgba(243, 239, 230,230);\n"
"border-radius:45px;\n"
"border: 1px solid rgba(136, 138, 133, 200);"));
        photo->setIconSize(QSize(91, 91));
        label_size = new QLabel(SearchAccounts);
        label_size->setObjectName(QString::fromUtf8("label_size"));
        label_size->setGeometry(QRect(120, 50, 91, 16));
        label_size->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(85, 87, 83);\n"
"font: 13pt \"Avenir next\";\n"
"border-bottom:1px solid rgba(85, 87, 83, 150);"));
        subscribes_size = new QLabel(SearchAccounts);
        subscribes_size->setObjectName(QString::fromUtf8("subscribes_size"));
        subscribes_size->setGeometry(QRect(120, 70, 91, 16));
        subscribes_size->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(85, 87, 83);\n"
"font: 13pt \"Avenir next\";\n"
"border-bottom:1px solid rgba(85, 87, 83, 150);"));

        retranslateUi(SearchAccounts);

        QMetaObject::connectSlotsByName(SearchAccounts);
    } // setupUi

    void retranslateUi(QDialog *SearchAccounts)
    {
        SearchAccounts->setWindowTitle(QCoreApplication::translate("SearchAccounts", "Dialog", nullptr));
        subscribe->setText(QCoreApplication::translate("SearchAccounts", "subscribe", nullptr));
        nickname->setText(QCoreApplication::translate("SearchAccounts", "name", nullptr));
        cancel->setText(QCoreApplication::translate("SearchAccounts", "cancel", nullptr));
        photo->setText(QString());
        label_size->setText(QCoreApplication::translate("SearchAccounts", "count labels: ", nullptr));
        subscribes_size->setText(QCoreApplication::translate("SearchAccounts", "subscribes:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchAccounts: public Ui_SearchAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHACCOUNTS_H
