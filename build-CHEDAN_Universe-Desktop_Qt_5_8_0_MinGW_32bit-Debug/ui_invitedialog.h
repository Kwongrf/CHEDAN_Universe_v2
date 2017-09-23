/********************************************************************************
** Form generated from reading UI file 'invitedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITEDIALOG_H
#define UI_INVITEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_InviteDialog
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *InviteDialog)
    {
        if (InviteDialog->objectName().isEmpty())
            InviteDialog->setObjectName(QStringLiteral("InviteDialog"));
        InviteDialog->resize(495, 472);
        radioButton = new QRadioButton(InviteDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(180, 30, 89, 16));
        radioButton->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(InviteDialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(280, 30, 89, 16));
        radioButton_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        radioButton_3 = new QRadioButton(InviteDialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(370, 30, 89, 16));
        radioButton_3->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label = new QLabel(InviteDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 111, 16));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        tableWidget = new QTableWidget(InviteDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 60, 431, 381));

        retranslateUi(InviteDialog);

        QMetaObject::connectSlotsByName(InviteDialog);
    } // setupUi

    void retranslateUi(QDialog *InviteDialog)
    {
        InviteDialog->setWindowTitle(QApplication::translate("InviteDialog", "Dialog", Q_NULLPTR));
        radioButton->setText(QApplication::translate("InviteDialog", "\346\210\221\347\232\204\345\205\263\346\263\250", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("InviteDialog", "\346\210\221\347\232\204\347\262\211\344\270\235", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("InviteDialog", "\346\211\200\346\234\211\344\272\272", Q_NULLPTR));
        label->setText(QApplication::translate("InviteDialog", "\351\200\211\346\213\251\344\275\240\350\246\201\351\202\200\350\257\267\347\232\204\344\272\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InviteDialog: public Ui_InviteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITEDIALOG_H
