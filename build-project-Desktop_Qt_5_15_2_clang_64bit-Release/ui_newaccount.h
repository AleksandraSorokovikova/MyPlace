/********************************************************************************
** Form generated from reading UI file 'newaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWACCOUNT_H
#define UI_NEWACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newaccount
{
public:
    QPushButton *pushButton;
    QLineEdit *nickname;
    QLineEdit *password;

    void setupUi(QDialog *newaccount)
    {
        if (newaccount->objectName().isEmpty())
            newaccount->setObjectName(QString::fromUtf8("newaccount"));
        newaccount->resize(376, 449);
        pushButton = new QPushButton(newaccount);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 370, 113, 32));
        nickname = new QLineEdit(newaccount);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(40, 120, 291, 41));
        password = new QLineEdit(newaccount);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(40, 170, 291, 41));
        password->setEchoMode(QLineEdit::Password);

        retranslateUi(newaccount);

        QMetaObject::connectSlotsByName(newaccount);
    } // setupUi

    void retranslateUi(QDialog *newaccount)
    {
        newaccount->setWindowTitle(QCoreApplication::translate("newaccount", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("newaccount", "\302\240\321\201\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newaccount: public Ui_newaccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWACCOUNT_H
