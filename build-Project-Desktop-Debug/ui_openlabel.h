/********************************************************************************
** Form generated from reading UI file 'openlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENLABEL_H
#define UI_OPENLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenLabel
{
public:
    QLabel *name;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QPushButton *pushButton;

    void setupUi(QDialog *OpenLabel)
    {
        if (OpenLabel->objectName().isEmpty())
            OpenLabel->setObjectName(QString::fromUtf8("OpenLabel"));
        OpenLabel->resize(385, 346);
        name = new QLabel(OpenLabel);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(110, 0, 221, 51));
        label_2 = new QLabel(OpenLabel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 40, 67, 17));
        label_3 = new QLabel(OpenLabel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 91, 21));
        widget = new QWidget(OpenLabel);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 120, 281, 121));
        pushButton = new QPushButton(OpenLabel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 310, 89, 25));

        retranslateUi(OpenLabel);

        QMetaObject::connectSlotsByName(OpenLabel);
    } // setupUi

    void retranslateUi(QDialog *OpenLabel)
    {
        OpenLabel->setWindowTitle(QCoreApplication::translate("OpenLabel", "Dialog", nullptr));
        name->setText(QCoreApplication::translate("OpenLabel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\202\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("OpenLabel", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("OpenLabel", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("OpenLabel", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenLabel: public Ui_OpenLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENLABEL_H
