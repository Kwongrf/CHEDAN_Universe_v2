/********************************************************************************
** Form generated from reading UI file 'searchresult.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULT_H
#define UI_SEARCHRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchResult
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *SearchResult)
    {
        if (SearchResult->objectName().isEmpty())
            SearchResult->setObjectName(QStringLiteral("SearchResult"));
        SearchResult->resize(1045, 513);
        tableWidget = new QTableWidget(SearchResult);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 90, 311, 401));
        label = new QLabel(SearchResult);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 50, 101, 31));
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));
        tableWidget_2 = new QTableWidget(SearchResult);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(370, 90, 301, 401));
        tableWidget_3 = new QTableWidget(SearchResult);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(700, 90, 311, 401));
        label_2 = new QLabel(SearchResult);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 50, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));
        label_3 = new QLabel(SearchResult);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(810, 50, 101, 31));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));

        retranslateUi(SearchResult);

        QMetaObject::connectSlotsByName(SearchResult);
    } // setupUi

    void retranslateUi(QDialog *SearchResult)
    {
        SearchResult->setWindowTitle(QApplication::translate("SearchResult", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SearchResult", "    \347\233\270\345\205\263\351\227\256\351\242\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("SearchResult", "    \347\233\270\345\205\263\345\233\236\347\255\224", Q_NULLPTR));
        label_3->setText(QApplication::translate("SearchResult", "    \347\233\270\345\205\263\347\224\250\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchResult: public Ui_SearchResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULT_H
