/********************************************************************************
** Form generated from reading UI file 'userdatawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDATAWINDOW_H
#define UI_USERDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserdataWindow
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *changePassButton;
    QPushButton *changeNameButton;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *messageButton;
    QLabel *label_14;
    QLabel *label_prs;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_id;
    QLabel *label_4;
    QLabel *label_name;
    QLabel *label_6;
    QLabel *label_ans;
    QLabel *label_8;
    QLabel *label_ask;
    QLabel *label_10;
    QLabel *label_focus;
    QLabel *label_12;
    QLabel *label_follow;

    void setupUi(QDialog *UserdataWindow)
    {
        if (UserdataWindow->objectName().isEmpty())
            UserdataWindow->setObjectName(QStringLiteral("UserdataWindow"));
        UserdataWindow->resize(833, 558);
        buttonBox = new QDialogButtonBox(UserdataWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(730, 50, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        changePassButton = new QPushButton(UserdataWindow);
        changePassButton->setObjectName(QStringLiteral("changePassButton"));
        changePassButton->setGeometry(QRect(740, 450, 75, 23));
        changeNameButton = new QPushButton(UserdataWindow);
        changeNameButton->setObjectName(QStringLiteral("changeNameButton"));
        changeNameButton->setGeometry(QRect(740, 490, 75, 23));
        tableWidget = new QTableWidget(UserdataWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 220, 311, 311));
        tableWidget_2 = new QTableWidget(UserdataWindow);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(410, 220, 311, 311));
        label_2 = new QLabel(UserdataWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 180, 131, 31));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));
        label_3 = new QLabel(UserdataWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 180, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));
        messageButton = new QPushButton(UserdataWindow);
        messageButton->setObjectName(QStringLiteral("messageButton"));
        messageButton->setGeometry(QRect(740, 400, 71, 31));
        messageButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        label_14 = new QLabel(UserdataWindow);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(580, 113, 39, 16));
        label_14->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));
        label_prs = new QLabel(UserdataWindow);
        label_prs->setObjectName(QStringLiteral("label_prs"));
        label_prs->setGeometry(QRect(670, 113, 63, 16));
        label_prs->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));
        layoutWidget = new QWidget(UserdataWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 481, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_id = new QLabel(layoutWidget);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        gridLayout->addWidget(label_id, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_4->setLineWidth(2);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        gridLayout->addWidget(label_name, 0, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_ans = new QLabel(layoutWidget);
        label_ans->setObjectName(QStringLiteral("label_ans"));
        label_ans->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        gridLayout->addWidget(label_ans, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_ask = new QLabel(layoutWidget);
        label_ask->setObjectName(QStringLiteral("label_ask"));
        label_ask->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_ask, 1, 3, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_focus = new QLabel(layoutWidget);
        label_focus->setObjectName(QStringLiteral("label_focus"));
        label_focus->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_focus, 2, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_12, 2, 2, 1, 1);

        label_follow = new QLabel(layoutWidget);
        label_follow->setObjectName(QStringLiteral("label_follow"));
        label_follow->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;"));

        gridLayout->addWidget(label_follow, 2, 3, 1, 1);


        retranslateUi(UserdataWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), UserdataWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UserdataWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(UserdataWindow);
    } // setupUi

    void retranslateUi(QDialog *UserdataWindow)
    {
        UserdataWindow->setWindowTitle(QApplication::translate("UserdataWindow", "Dialog", Q_NULLPTR));
        changePassButton->setText(QApplication::translate("UserdataWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        changeNameButton->setText(QApplication::translate("UserdataWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserdataWindow", "  \347\224\250\346\210\267\346\217\220\345\207\272\347\232\204\351\227\256\351\242\230", Q_NULLPTR));
        label_3->setText(QApplication::translate("UserdataWindow", "  \347\224\250\346\210\267\345\233\236\347\255\224\347\232\204\347\255\224\346\241\210", Q_NULLPTR));
        messageButton->setText(QApplication::translate("UserdataWindow", "\347\247\201\344\277\241", Q_NULLPTR));
        label_14->setText(QApplication::translate("UserdataWindow", "\350\216\267\345\276\227\350\265\236", Q_NULLPTR));
        label_prs->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("UserdataWindow", "ID", Q_NULLPTR));
        label_id->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("UserdataWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_name->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("UserdataWindow", "\345\233\236\347\255\224\346\225\260", Q_NULLPTR));
        label_ans->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("UserdataWindow", "\346\217\220\351\227\256\346\225\260", Q_NULLPTR));
        label_ask->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("UserdataWindow", "\345\205\263\346\263\250\346\225\260", Q_NULLPTR));
        label_focus->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
        label_12->setText(QApplication::translate("UserdataWindow", "\347\262\211\344\270\235\346\225\260", Q_NULLPTR));
        label_follow->setText(QApplication::translate("UserdataWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserdataWindow: public Ui_UserdataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDATAWINDOW_H
