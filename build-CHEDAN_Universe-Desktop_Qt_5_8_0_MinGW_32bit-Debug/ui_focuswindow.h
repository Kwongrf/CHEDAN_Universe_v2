/********************************************************************************
** Form generated from reading UI file 'focuswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOCUSWINDOW_H
#define UI_FOCUSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusWindow
{
public:
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *FocusWindow)
    {
        if (FocusWindow->objectName().isEmpty())
            FocusWindow->setObjectName(QStringLiteral("FocusWindow"));
        FocusWindow->resize(1016, 545);
        tableWidget = new QTableWidget(FocusWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 70, 931, 401));
        tableWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(FocusWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 101, 31));
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));

        retranslateUi(FocusWindow);

        QMetaObject::connectSlotsByName(FocusWindow);
    } // setupUi

    void retranslateUi(QWidget *FocusWindow)
    {
        FocusWindow->setWindowTitle(QApplication::translate("FocusWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("FocusWindow", "\346\210\221\347\232\204\345\205\263\346\263\250\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FocusWindow: public Ui_FocusWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUSWINDOW_H
