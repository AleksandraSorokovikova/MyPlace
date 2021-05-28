/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QLabel *image;
    QListWidget *listWidget;
    QPushButton *add_label;
    QFrame *frame;
    QLineEdit *search;
    QPushButton *search_button;
    QPushButton *subscribes;
    QPushButton *labels;
    QPushButton *update;
    QPushButton *my_account_2;
    QPushButton *logout;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QString::fromUtf8("MenuWindow"));
        MenuWindow->resize(891, 629);
        MenuWindow->setMinimumSize(QSize(891, 629));
        MenuWindow->setMaximumSize(QSize(891, 629));
        MenuWindow->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"text-align: right;\n"
"background: gray;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"     spacing: 3px; /* \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\320\265\320\266\320\264\321\203 \320\277\321\203\320\275\320\272\321\202\320\260\320\274\320\270 \320\274\320\265\320\275\321\216 */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
"	color: white;\n"
"    text-align: right;\n"
"	font: 0 9pt \"Gayathri\";\n"
" }\n"
"\n"
" QMenuBar::item:selected { /* \320\272\320\276\320\263\320\264\320\260 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\276 \321\201 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\274\321\213\321\210\320\270 \320\270\320\273\320\270 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213 */\n"
"     background: #a8a8a8;\n"
" }\n"
"\n"
" QMenuBar::item:pressed {\n"
"     background: #888888;\n"
" }\n"
"\n"
""));
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(20, -50, 961, 731));
        image->setStyleSheet(QString::fromUtf8(""));
        image->setPixmap(QPixmap(QString::fromUtf8(":/img/img/mapss.png")));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 80, 261, 561));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setSizeIncrement(QSize(10, 10));
        listWidget->setStyleSheet(QString::fromUtf8("*{\n"
"	background:rgb(243,239,230);\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"     border: 1px solid rgba(243,239,230,100);\n"
"	background:rgb(227, 223, 216);\n"
" }\n"
"\n"
"QListWidget::item {\n"
"    color:rgb(85, 87, 83);\n"
"	font: 14pt \"Avenir next\";\n"
"}\n"
"\n"
""));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setBatchSize(150);
        listWidget->setSortingEnabled(false);
        add_label = new QPushButton(centralwidget);
        add_label->setObjectName(QString::fromUtf8("add_label"));
        add_label->setGeometry(QRect(847, 494, 40, 40));
        add_label->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(85, 87, 83);\n"
"font: 40pt \"Avenir next\";\n"
"color: rgba(60, 58, 59, 181);\n"
"background:rgba(153, 173, 167,120);\n"
"border-radius:20px;\n"
"text-align: center;"));
        add_label->setIconSize(QSize(27, 27));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 261, 81));
        frame->setStyleSheet(QString::fromUtf8("background:rgb(243,239,230);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        search = new QLineEdit(frame);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(10, 10, 211, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir next"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        search->setFont(font);
        search->setFocusPolicy(Qt::WheelFocus);
        search->setContextMenuPolicy(Qt::NoContextMenu);
        search->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(136, 138, 133, 150);\n"
"color: rgb(85, 87, 83);\n"
"font: 16pt \"Avenir next\";\n"
"border-radius: 10px;\n"
"background: rgba(0,0,0,20);"));
        search_button = new QPushButton(frame);
        search_button->setObjectName(QString::fromUtf8("search_button"));
        search_button->setGeometry(QRect(220, 5, 41, 41));
        search_button->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"color:#3c3a3a; \n"
"background:transparent; \n"
"font: 19pt \"Avenir next\";\n"
"border-radius:30px;\n"
"border-bottom:0px solid #3c3a3a\n"
""));
        subscribes = new QPushButton(frame);
        subscribes->setObjectName(QString::fromUtf8("subscribes"));
        subscribes->setGeometry(QRect(120, 50, 101, 32));
        subscribes->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"color:#3c3a3a; \n"
"background:transparent; \n"
"font: 18pt \"Avenir next\";\n"
"border-radius:30px;\n"
"border-bottom:1px solid #3c3a3a"));
        labels = new QPushButton(frame);
        labels->setObjectName(QString::fromUtf8("labels"));
        labels->setGeometry(QRect(50, 50, 61, 32));
        labels->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"color:#3c3a3a; \n"
"background:transparent; \n"
"font: 18pt \"Avenir next\";\n"
"border-radius:30px;\n"
"border-bottom:1px solid #3c3a3a"));
        update = new QPushButton(frame);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(10, 50, 31, 31));
        update->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"color:#3c3a3a; \n"
"background:transparent; \n"
"font: 19pt \"Avenir next\";\n"
"border-radius:30px;\n"
"border-bottom:0px solid #3c3a3a"));
        update->setIconSize(QSize(20, 20));
        my_account_2 = new QPushButton(centralwidget);
        my_account_2->setObjectName(QString::fromUtf8("my_account_2"));
        my_account_2->setGeometry(QRect(847, 540, 40, 40));
        my_account_2->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(85, 87, 83);\n"
"font: 15pt \"Avenir next\";\n"
"color: rgba(60, 58, 59, 181);\n"
"background:rgba(153, 173, 167,120);\n"
"border-radius:20px;\n"
"text-align: center;"));
        my_account_2->setIconSize(QSize(27, 27));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(847, 586, 40, 40));
        logout->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(85, 87, 83);\n"
"font: 40pt \"Avenir next\";\n"
"color: rgba(60, 58, 59, 181);\n"
"background:rgba(153, 173, 167,120);\n"
"border-radius:20px;\n"
"text-align: center;"));
        logout->setIconSize(QSize(27, 27));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(260, 0, 681, 771));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MenuWindow->setCentralWidget(centralwidget);
        image->raise();
        listWidget->raise();
        frame->raise();
        gridLayoutWidget->raise();
        logout->raise();
        my_account_2->raise();
        add_label->raise();
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 891, 22));
        MenuWindow->setMenuBar(menubar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "MainWindow", nullptr));
        image->setText(QString());
        add_label->setText(QString());
        search->setPlaceholderText(QCoreApplication::translate("MenuWindow", "Search", nullptr));
        search_button->setText(QString());
        subscribes->setText(QCoreApplication::translate("MenuWindow", "subscribes", nullptr));
        labels->setText(QCoreApplication::translate("MenuWindow", "labels", nullptr));
        update->setText(QString());
        my_account_2->setText(QString());
        logout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
