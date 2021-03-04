/********************************************************************************
** Form generated from reading UI file 'openlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENLABEL_H
#define UI_OPENLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_OpenLabel
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *nickname;
    QTextEdit *description;
    QLineEdit *address;
    QLineEdit *name;
    QFrame *frame;
    QLabel *type;

    void setupUi(QDialog *OpenLabel)
    {
        if (OpenLabel->objectName().isEmpty())
            OpenLabel->setObjectName(QString::fromUtf8("OpenLabel"));
        OpenLabel->resize(395, 395);
        OpenLabel->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(142, 208, 186, 255), stop:1 rgba(255, 173, 173, 255))"));
        label_2 = new QLabel(OpenLabel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 50, 67, 17));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Gayathri\";"));
        label_3 = new QLabel(OpenLabel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Gayathri\";"));
        pushButton = new QPushButton(OpenLabel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 350, 71, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background: rgb(128,221,190);\n"
"font: 75 14pt \"Gayathri\";"));
        nickname = new QLabel(OpenLabel);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(20, 340, 111, 21));
        nickname->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Gayathri\";"));
        description = new QTextEdit(OpenLabel);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(10, 150, 371, 181));
        description->setStyleSheet(QString::fromUtf8("background: rgba(243, 239, 230);\n"
"color: rgb(110, 109, 111);\n"
"border-radius: 30px;"));
        description->setReadOnly(true);
        address = new QLineEdit(OpenLabel);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(110, 80, 281, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Gayathri"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        address->setFont(font);
        address->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: gray;\n"
"font: 75 9pt \"Gayathri\";\n"
""));
        address->setReadOnly(true);
        name = new QLineEdit(OpenLabel);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(110, 10, 281, 41));
        name->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(85, 87, 83);\n"
"font: 75 16pt \"Gayathri\";\n"
""));
        name->setFrame(false);
        name->setReadOnly(true);
        frame = new QFrame(OpenLabel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 91, 91));
        frame->setStyleSheet(QString::fromUtf8("background:rgba(243, 239, 230, 200);\n"
"border-radius:40px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        type = new QLabel(frame);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(10, 30, 81, 21));

        retranslateUi(OpenLabel);

        QMetaObject::connectSlotsByName(OpenLabel);
    } // setupUi

    void retranslateUi(QDialog *OpenLabel)
    {
        OpenLabel->setWindowTitle(QApplication::translate("OpenLabel", "Dialog", nullptr));
        label_2->setText(QApplication::translate("OpenLabel", "address:", nullptr));
        label_3->setText(QApplication::translate("OpenLabel", "description:", nullptr));
        pushButton->setText(QApplication::translate("OpenLabel", "exit", nullptr));
        nickname->setText(QApplication::translate("OpenLabel", "TextLabel", nullptr));
        address->setText(QApplication::translate("OpenLabel", "\320\260\320\264\321\200\320\265\321\201\321\201", nullptr));
        name->setText(QApplication::translate("OpenLabel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\202\320\272\320\270", nullptr));
        type->setText(QApplication::translate("OpenLabel", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenLabel: public Ui_OpenLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENLABEL_H
