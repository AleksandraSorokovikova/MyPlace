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
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QLineEdit *address;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QTextEdit *description;

    void setupUi(QDialog *CreaterLabel)
    {
        if (CreaterLabel->objectName().isEmpty())
            CreaterLabel->setObjectName(QString::fromUtf8("CreaterLabel"));
        CreaterLabel->resize(484, 570);
        CreaterLabel->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255));"));
        label = new QLabel(CreaterLabel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 191, 51));
        label->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Gayathri\";"));
        label_2 = new QLabel(CreaterLabel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 290, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Gayathri\";"));
        name = new QLineEdit(CreaterLabel);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 90, 431, 41));
        name->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Gayathri\";;\n"
"border-radius: 15px;\n"
"padding: 0 8px;\n"
"background: rgba(0,0,0,20);\n"
"selection-background-color: darkgray;"));
        label_3 = new QLabel(CreaterLabel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 140, 81, 21));
        label_3->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Gayathri\";"));
        address = new QLineEdit(CreaterLabel);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(10, 160, 431, 41));
        address->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Gayathri\";;\n"
"border-radius: 15px;\n"
"padding: 0 8px;\n"
"background: rgba(0,0,0,20);\n"
"selection-background-color: darkgray;"));
        label_4 = new QLabel(CreaterLabel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 210, 161, 21));
        label_4->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Gayathri\";"));
        pushButton = new QPushButton(CreaterLabel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 530, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background: rgba(128,221,190, 240);\n"
"border: 1px solid gray;\n"
"font: 75 14pt \"Gayathri\";"));
        label_5 = new QLabel(CreaterLabel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 251, 41));
        label_5->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 75 24pt \"Gayathri\";"));
        pushButton_2 = new QPushButton(CreaterLabel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 530, 91, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background: rgba(128,221,190, 240);\n"
"border: 1px solid gray;\n"
"font: 75 14pt \"Gayathri\";"));
        description = new QTextEdit(CreaterLabel);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(10, 320, 461, 191));
        description->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Gayathri\";;\n"
"border-radius: 30px;\n"
"padding: 0 8px;\n"
"background: rgba(0,0,0,20);\n"
"selection-background-color: darkgray;"));

        retranslateUi(CreaterLabel);

        QMetaObject::connectSlotsByName(CreaterLabel);
    } // setupUi

    void retranslateUi(QDialog *CreaterLabel)
    {
        CreaterLabel->setWindowTitle(QApplication::translate("CreaterLabel", "Dialog", nullptr));
        label->setText(QApplication::translate("CreaterLabel", "name:", nullptr));
        label_2->setText(QApplication::translate("CreaterLabel", "description:", nullptr));
        label_3->setText(QApplication::translate("CreaterLabel", "address:", nullptr));
        label_4->setText(QApplication::translate("CreaterLabel", "type:", nullptr));
        pushButton->setText(QApplication::translate("CreaterLabel", "create", nullptr));
        label_5->setText(QApplication::translate("CreaterLabel", "Create label", nullptr));
        pushButton_2->setText(QApplication::translate("CreaterLabel", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreaterLabel: public Ui_CreaterLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERLABEL_H
