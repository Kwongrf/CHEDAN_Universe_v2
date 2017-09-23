/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *searchEdit;
    QLabel *label_2;
    QPushButton *askQuesButton;
    QPushButton *userDataButton;
    QTableWidget *tableWidget;
    QPushButton *searchButton;
    QPushButton *freshButton;
    QPushButton *signoutButton;
    QPushButton *focusButton;
    QPushButton *lastpageButton;
    QPushButton *nextpageButton;
    QPushButton *homepageButton;
    QPushButton *endpageButton;
    QLineEdit *pageNum;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *gotopageButton;
    QPushButton *searchButton_2;
    QDateEdit *dateEdit;
    QPushButton *followedButton;
    QPushButton *noticeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1141, 643);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 71, 21));
        label->setStyleSheet(QLatin1String("font:13pt;\n"
"color:rgb(255,255,255)"));
        searchEdit = new QLineEdit(centralWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setGeometry(QRect(190, 20, 551, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 31, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 180,0);\n"
"border-radius:15px;\n"
""));
        askQuesButton = new QPushButton(centralWidget);
        askQuesButton->setObjectName(QStringLiteral("askQuesButton"));
        askQuesButton->setGeometry(QRect(780, 180, 91, 91));
        askQuesButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        userDataButton = new QPushButton(centralWidget);
        userDataButton->setObjectName(QStringLiteral("userDataButton"));
        userDataButton->setGeometry(QRect(930, 340, 91, 41));
        userDataButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 70, 701, 481));
        tableWidget->setStyleSheet(QStringLiteral(""));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(780, 20, 91, 41));
        searchButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        freshButton = new QPushButton(centralWidget);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setGeometry(QRect(780, 340, 91, 41));
        freshButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        signoutButton = new QPushButton(centralWidget);
        signoutButton->setObjectName(QStringLiteral("signoutButton"));
        signoutButton->setGeometry(QRect(930, 390, 91, 41));
        signoutButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 50, 50);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        focusButton = new QPushButton(centralWidget);
        focusButton->setObjectName(QStringLiteral("focusButton"));
        focusButton->setGeometry(QRect(930, 180, 91, 41));
        focusButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        lastpageButton = new QPushButton(centralWidget);
        lastpageButton->setObjectName(QStringLiteral("lastpageButton"));
        lastpageButton->setGeometry(QRect(220, 560, 75, 23));
        nextpageButton = new QPushButton(centralWidget);
        nextpageButton->setObjectName(QStringLiteral("nextpageButton"));
        nextpageButton->setGeometry(QRect(490, 560, 75, 23));
        homepageButton = new QPushButton(centralWidget);
        homepageButton->setObjectName(QStringLiteral("homepageButton"));
        homepageButton->setGeometry(QRect(120, 560, 75, 23));
        endpageButton = new QPushButton(centralWidget);
        endpageButton->setObjectName(QStringLiteral("endpageButton"));
        endpageButton->setGeometry(QRect(590, 560, 75, 23));
        pageNum = new QLineEdit(centralWidget);
        pageNum->setObjectName(QStringLiteral("pageNum"));
        pageNum->setGeometry(QRect(350, 560, 31, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 560, 16, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 562, 54, 20));
        gotopageButton = new QPushButton(centralWidget);
        gotopageButton->setObjectName(QStringLiteral("gotopageButton"));
        gotopageButton->setGeometry(QRect(410, 560, 31, 23));
        searchButton_2 = new QPushButton(centralWidget);
        searchButton_2->setObjectName(QStringLiteral("searchButton_2"));
        searchButton_2->setGeometry(QRect(1030, 20, 91, 41));
        searchButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(900, 30, 110, 22));
        followedButton = new QPushButton(centralWidget);
        followedButton->setObjectName(QStringLiteral("followedButton"));
        followedButton->setGeometry(QRect(930, 230, 91, 41));
        followedButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        noticeButton = new QPushButton(centralWidget);
        noticeButton->setObjectName(QStringLiteral("noticeButton"));
        noticeButton->setGeometry(QRect(780, 390, 91, 41));
        noticeButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1141, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\346\220\234\347\264\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", " \346\234\200\346\226\260\351\227\256\351\242\230", Q_NULLPTR));
        askQuesButton->setText(QApplication::translate("MainWindow", "\346\217\220\351\227\256", Q_NULLPTR));
        userDataButton->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        freshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\225\214\351\235\242", Q_NULLPTR));
        signoutButton->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", Q_NULLPTR));
        focusButton->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\205\263\346\263\250", Q_NULLPTR));
        lastpageButton->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextpageButton->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        homepageButton->setText(QApplication::translate("MainWindow", "\351\246\226\351\241\265", Q_NULLPTR));
        endpageButton->setText(QApplication::translate("MainWindow", "\345\260\276\351\241\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\254\254", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\351\241\265", Q_NULLPTR));
        gotopageButton->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        searchButton_2->setText(QApplication::translate("MainWindow", "\346\214\211\346\227\266\351\227\264\346\220\234\347\264\242", Q_NULLPTR));
        followedButton->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\347\262\211\344\270\235", Q_NULLPTR));
        noticeButton->setText(QApplication::translate("MainWindow", "\351\200\232\347\237\245\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
