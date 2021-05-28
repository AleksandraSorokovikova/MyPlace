/********************************************************************************
** Form generated from reading UI file 'createrlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
    QLabel *name_line;
    QLabel *description_line;
    QLineEdit *name;
    QLabel *address_2;
    QLineEdit *address;
    QLabel *type;
    QPushButton *create;
    QLabel *createLabel_line;
    QPushButton *cancel;
    QTextEdit *description;
    QPushButton *cafee;
    QPushButton *hotels;
    QPushButton *night_club;
    QPushButton *cinema;
    QPushButton *entertainment;
    QPushButton *different;

    void setupUi(QDialog *CreaterLabel)
    {
        if (CreaterLabel->objectName().isEmpty())
            CreaterLabel->setObjectName(QString::fromUtf8("CreaterLabel"));
        CreaterLabel->resize(484, 594);
        CreaterLabel->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255))"));
        name_line = new QLabel(CreaterLabel);
        name_line->setObjectName(QString::fromUtf8("name_line"));
        name_line->setGeometry(QRect(10, 50, 191, 51));
        name_line->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Avenir next\";\n"
"color:rgb(47, 46, 44);\n"
"font: 16pt \"Avenir next\";"));
        description_line = new QLabel(CreaterLabel);
        description_line->setObjectName(QString::fromUtf8("description_line"));
        description_line->setGeometry(QRect(10, 300, 111, 31));
        description_line->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Avenir next\";\n"
"color:rgb(47, 46, 44);\n"
"font: 17pt \"Avenir next\";"));
        name = new QLineEdit(CreaterLabel);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 90, 461, 41));
        name->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 15px;\n"
"padding: 0 8px;\n"
"background: rgba(243, 239, 230,230);\n"
"border-color:transparent;\n"
""));
        name->setMaxLength(24);
        address_2 = new QLabel(CreaterLabel);
        address_2->setObjectName(QString::fromUtf8("address_2"));
        address_2->setGeometry(QRect(10, 140, 81, 21));
        address_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Avenir next\";\n"
"color:rgb(47, 46, 44);\n"
"font: 16pt \"Avenir next\";"));
        address = new QLineEdit(CreaterLabel);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(10, 160, 461, 41));
        address->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 15px;\n"
"padding: 0 8px;\n"
"background: rgba(243, 239, 230,230);\n"
"border-color:transparent;\n"
""));
        type = new QLabel(CreaterLabel);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(10, 210, 161, 21));
        type->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Avenir next\";\n"
"color:rgb(47, 46, 44);\n"
"font: 17pt \"Avenir next\";"));
        create = new QPushButton(CreaterLabel);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(380, 530, 91, 31));
        create->setStyleSheet(QString::fromUtf8("color:rgb(42, 44, 42);\n"
"border: 1px solid rgb(85, 87, 83);\n"
"border-radius: 15px;\n"
"background:rgba(243,239,230, 200);\n"
"border: 1px solid gray;\n"
"font: 100 19pt \"Avenir next\";\n"
"border-color:rgb(183, 180, 200);\n"
""));
        createLabel_line = new QLabel(CreaterLabel);
        createLabel_line->setObjectName(QString::fromUtf8("createLabel_line"));
        createLabel_line->setGeometry(QRect(10, 10, 251, 41));
        createLabel_line->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 14pt \"Avenir next\";\n"
"color:rgb(47, 46, 44);\n"
"font: 120 30pt \"Avenir next\";"));
        cancel = new QPushButton(CreaterLabel);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(10, 530, 91, 32));
        cancel->setStyleSheet(QString::fromUtf8("color:rgb(42, 44, 42);\n"
"border: 1px solid rgb(85, 87, 83);\n"
"border-radius: 15px;\n"
"background:rgba(243,239,230, 200);\n"
"border: 1px solid gray;\n"
"font: 100 19pt \"Avenir next\";\n"
"border-color:rgb(183, 180, 200);\n"
""));
        description = new QTextEdit(CreaterLabel);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(10, 340, 461, 171));
        description->setStyleSheet(QString::fromUtf8("border: 2px solid  #3c3a3a; \n"
"color: #3c3a3a;\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 30px;\n"
"padding: 0 8px;\n"
"background: rgb(243, 239, 230);\n"
"border-color:rgb(243, 239, 230);"));
        cafee = new QPushButton(CreaterLabel);
        cafee->setObjectName(QString::fromUtf8("cafee"));
        cafee->setGeometry(QRect(10, 240, 60, 60));
        cafee->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        cafee->setIconSize(QSize(35, 35));
        hotels = new QPushButton(CreaterLabel);
        hotels->setObjectName(QString::fromUtf8("hotels"));
        hotels->setGeometry(QRect(88, 240, 60, 60));
        hotels->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        hotels->setIconSize(QSize(35, 35));
        night_club = new QPushButton(CreaterLabel);
        night_club->setObjectName(QString::fromUtf8("night_club"));
        night_club->setGeometry(QRect(166, 240, 60, 60));
        night_club->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        night_club->setIconSize(QSize(35, 35));
        cinema = new QPushButton(CreaterLabel);
        cinema->setObjectName(QString::fromUtf8("cinema"));
        cinema->setGeometry(QRect(244, 240, 60, 60));
        cinema->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        cinema->setText(QString::fromUtf8(""));
        cinema->setIconSize(QSize(35, 35));
        entertainment = new QPushButton(CreaterLabel);
        entertainment->setObjectName(QString::fromUtf8("entertainment"));
        entertainment->setGeometry(QRect(322, 240, 60, 60));
        entertainment->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        entertainment->setIconSize(QSize(35, 35));
        different = new QPushButton(CreaterLabel);
        different->setObjectName(QString::fromUtf8("different"));
        different->setGeometry(QRect(400, 240, 60, 60));
        different->setStyleSheet(QString::fromUtf8("*{ \n"
"border: 1px solid rgba(136, 138, 133, 200);\n"
"background: rgba(243, 239, 230,230);\n"
"border-radius:30px;\n"
"}\n"
"QPushButton:pressed  {\n"
"    background: rgba(136, 138, 133, 200);\n"
"}"));
        different->setIconSize(QSize(35, 35));

        retranslateUi(CreaterLabel);

        QMetaObject::connectSlotsByName(CreaterLabel);
    } // setupUi

    void retranslateUi(QDialog *CreaterLabel)
    {
        CreaterLabel->setWindowTitle(QCoreApplication::translate("CreaterLabel", "Dialog", nullptr));
        name_line->setText(QCoreApplication::translate("CreaterLabel", "name:", nullptr));
        description_line->setText(QCoreApplication::translate("CreaterLabel", "description:", nullptr));
        address_2->setText(QCoreApplication::translate("CreaterLabel", "address:", nullptr));
        type->setText(QCoreApplication::translate("CreaterLabel", "type:", nullptr));
        create->setText(QCoreApplication::translate("CreaterLabel", "create", nullptr));
        createLabel_line->setText(QCoreApplication::translate("CreaterLabel", "Create label", nullptr));
        cancel->setText(QCoreApplication::translate("CreaterLabel", "cancel", nullptr));
        cafee->setText(QString());
        hotels->setText(QString());
        night_club->setText(QString());
        entertainment->setText(QString());
        different->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreaterLabel: public Ui_CreaterLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERLABEL_H
