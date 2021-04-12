/********************************************************************************
** Form generated from reading UI file 'createrlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERLABEL_H
#define UI_CREATERLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreaterLabel
{
public:
    QLabel *label;
    QTextEdit *description;
    QLabel *label_2;
    QLineEdit *login;
    QLabel *label_3;
    QLineEdit *address;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QDialog *CreaterLabel)
    {
        if (CreaterLabel->objectName().isEmpty())
            CreaterLabel->setObjectName(QString::fromUtf8("CreaterLabel"));
        CreaterLabel->resize(433, 464);
        label = new QLabel(CreaterLabel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 191, 51));
        description = new QTextEdit(CreaterLabel);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(10, 300, 411, 121));
        label_2 = new QLabel(CreaterLabel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 270, 101, 21));
        login = new QLineEdit(CreaterLabel);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(10, 70, 401, 25));
        label_3 = new QLabel(CreaterLabel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 81, 17));
        address = new QLineEdit(CreaterLabel);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(10, 130, 401, 25));
        label_4 = new QLabel(CreaterLabel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 111, 17));
        pushButton = new QPushButton(CreaterLabel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 430, 89, 25));
        label_5 = new QLabel(CreaterLabel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 0, 241, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";"));

        retranslateUi(CreaterLabel);

        QMetaObject::connectSlotsByName(CreaterLabel);
    } // setupUi

    void retranslateUi(QDialog *CreaterLabel)
    {
        CreaterLabel->setWindowTitle(QApplication::translate("CreaterLabel", "Dialog", nullptr));
        label->setText(QApplication::translate("CreaterLabel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\262\320\265\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QApplication::translate("CreaterLabel", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        label_3->setText(QApplication::translate("CreaterLabel", "\320\220\320\264\321\200\320\265\321\201:", nullptr));
        label_4->setText(QApplication::translate("CreaterLabel", "\320\242\320\270\320\277 \320\267\320\260\320\262\320\265\320\264\320\265\320\275\320\270\321\217:", nullptr));
        pushButton->setText(QApplication::translate("CreaterLabel", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        label_5->setText(QApplication::translate("CreaterLabel", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\274\320\265\321\202\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreaterLabel: public Ui_CreaterLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERLABEL_H
