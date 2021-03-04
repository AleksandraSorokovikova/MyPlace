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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QLabel *image;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QToolButton *update;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(1043, 617);
        image = new QLabel(SecondWindow);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(290, -10, 761, 661));
        image->setPixmap(QPixmap(QString::fromUtf8("img/\320\232\320\260\321\200\321\202\320\260-2.png")));
        listWidget = new QListWidget(SecondWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 291, 591));
        pushButton = new QPushButton(SecondWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(975, 563, 61, 41));
        update = new QToolButton(SecondWindow);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(10, 575, 41, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        update->setIcon(icon);

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "Dialog", nullptr));
        image->setText(QString());
        pushButton->setText(QApplication::translate("SecondWindow", "...", nullptr));
        update->setText(QApplication::translate("SecondWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
