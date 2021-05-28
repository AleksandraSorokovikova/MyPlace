/********************************************************************************
** Form generated from reading UI file 'openlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENLABEL_H
#define UI_OPENLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_OpenLabel
{
public:
    QLabel *address_line;
    QLabel *description_line;
    QPushButton *exit;
    QLabel *nickname;
    QTextEdit *description;
    QLineEdit *address;
    QLineEdit *name;
    QLabel *dackground_description;
    QPushButton *type;

    void setupUi(QDialog *OpenLabel)
    {
        if (OpenLabel->objectName().isEmpty())
            OpenLabel->setObjectName(QString::fromUtf8("OpenLabel"));
        OpenLabel->resize(395, 395);
        OpenLabel->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255))"));
        address_line = new QLabel(OpenLabel);
        address_line->setObjectName(QString::fromUtf8("address_line"));
        address_line->setGeometry(QRect(110, 60, 67, 17));
        address_line->setStyleSheet(QString::fromUtf8("font: 13pt \"Avenir next\";\n"
"color:rgb(85, 87, 83);\n"
"background:transparent;"));
        description_line = new QLabel(OpenLabel);
        description_line->setObjectName(QString::fromUtf8("description_line"));
        description_line->setGeometry(QRect(20, 130, 91, 21));
        description_line->setStyleSheet(QString::fromUtf8("color:rgb(85, 87, 83);\n"
"font: 14pt \"Avenir next\";\n"
"background:transparent;"));
        exit = new QPushButton(OpenLabel);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(300, 350, 71, 31));
        exit->setStyleSheet(QString::fromUtf8("color:rgb(42, 44, 42);\n"
"border: 1px solid rgb(85, 87, 83);\n"
"border-radius: 15px;\n"
"background:rgba(243,239,230, 200);\n"
"border: 1px solid gray;\n"
"font: 100 19pt \"Avenir next\";\n"
"border-color:rgb(183, 180, 200);"));
        nickname = new QLabel(OpenLabel);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(20, 340, 111, 21));
        nickname->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);\n"
"font: 75 14pt \"Avenir next\";\n"
"background:transparent;"));
        description = new QTextEdit(OpenLabel);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(20, 170, 351, 151));
        description->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(110, 109, 111);"));
        description->setReadOnly(true);
        address = new QLineEdit(OpenLabel);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(110, 80, 261, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir next"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        address->setFont(font);
        address->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: gray;\n"
"font: 13pt \"Avenir next\";\n"
""));
        address->setReadOnly(true);
        name = new QLineEdit(OpenLabel);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(110, 20, 271, 41));
        name->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(85, 87, 83);\n"
"font: 18pt \"Avenir next\";\n"
""));
        name->setFrame(false);
        name->setReadOnly(true);
        dackground_description = new QLabel(OpenLabel);
        dackground_description->setObjectName(QString::fromUtf8("dackground_description"));
        dackground_description->setGeometry(QRect(10, 160, 371, 171));
        dackground_description->setStyleSheet(QString::fromUtf8("background: rgba(243, 239, 230,230);\n"
"border-color:transparent;\n"
"color: rgb(110, 109, 111);\n"
"border-radius: 30px;\n"
""));
        type = new QPushButton(OpenLabel);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(10, 20, 91, 91));
        type->setStyleSheet(QString::fromUtf8("background: rgba(243, 239, 230,230);\n"
"border-radius:45px;\n"
"border: 1px solid rgba(136, 138, 133, 200);"));
        type->setIconSize(QSize(65, 65));
#if QT_CONFIG(shortcut)
        type->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        address_line->raise();
        description_line->raise();
        exit->raise();
        nickname->raise();
        address->raise();
        name->raise();
        dackground_description->raise();
        description->raise();
        type->raise();

        retranslateUi(OpenLabel);

        QMetaObject::connectSlotsByName(OpenLabel);
    } // setupUi

    void retranslateUi(QDialog *OpenLabel)
    {
        OpenLabel->setWindowTitle(QCoreApplication::translate("OpenLabel", "Dialog", nullptr));
        address_line->setText(QCoreApplication::translate("OpenLabel", "address:", nullptr));
        description_line->setText(QCoreApplication::translate("OpenLabel", "description:", nullptr));
        exit->setText(QCoreApplication::translate("OpenLabel", "exit", nullptr));
        nickname->setText(QCoreApplication::translate("OpenLabel", "TextLabel", nullptr));
        address->setText(QCoreApplication::translate("OpenLabel", "address", nullptr));
        name->setText(QCoreApplication::translate("OpenLabel", "Lable's name", nullptr));
        dackground_description->setText(QString());
        type->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenLabel: public Ui_OpenLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENLABEL_H
