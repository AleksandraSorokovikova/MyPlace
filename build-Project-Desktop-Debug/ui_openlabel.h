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

QT_BEGIN_NAMESPACE

class Ui_OpenLabel
{
public:

    void setupUi(QDialog *OpenLabel)
    {
        if (OpenLabel->objectName().isEmpty())
            OpenLabel->setObjectName(QString::fromUtf8("OpenLabel"));
        OpenLabel->resize(385, 346);

        retranslateUi(OpenLabel);

        QMetaObject::connectSlotsByName(OpenLabel);
    } // setupUi

    void retranslateUi(QDialog *OpenLabel)
    {
        OpenLabel->setWindowTitle(QApplication::translate("OpenLabel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenLabel: public Ui_OpenLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENLABEL_H
