/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(1043, 615);
        label = new QLabel(SecondWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 751, 601));
        label->setPixmap(QPixmap(QString::fromUtf8("../\320\232\320\260\321\200\321\202\320\260-2.png")));
        listWidget = new QListWidget(SecondWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 291, 581));
        pushButton = new QPushButton(SecondWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(975, 563, 61, 41));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("SecondWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
