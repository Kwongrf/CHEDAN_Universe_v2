/********************************************************************************
** Form generated from reading UI file 'quesanswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESANSWINDOW_H
#define UI_QUESANSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuesAnsWindow
{
public:
    QLabel *label_title;
    QPushButton *answerQuesButton;
    QTableWidget *tableWidget;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *praiseButton;
    QLabel *label_prsnum;
    QLabel *label_dazhu;
    QLabel *label_time;
    QPushButton *focusDZButton;
    QPushButton *focusTZButton;
    QLabel *label_tizhu;
    QTextBrowser *textBrowser_2;
    QPushButton *freshButton;
    QPushButton *inviteButton;
    QPushButton *aboutTZButton;
    QPushButton *aboutDZButton;
    QPushButton *commentButton;

    void setupUi(QWidget *QuesAnsWindow)
    {
        if (QuesAnsWindow->objectName().isEmpty())
            QuesAnsWindow->setObjectName(QStringLiteral("QuesAnsWindow"));
        QuesAnsWindow->resize(785, 610);
        label_title = new QLabel(QuesAnsWindow);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(10, 20, 341, 21));
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        answerQuesButton = new QPushButton(QuesAnsWindow);
        answerQuesButton->setObjectName(QStringLiteral("answerQuesButton"));
        answerQuesButton->setGeometry(QRect(340, 550, 411, 31));
        answerQuesButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        tableWidget = new QTableWidget(QuesAnsWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 260, 281, 281));
        tableWidget->setStyleSheet(QStringLiteral(""));
        textBrowser = new QTextBrowser(QuesAnsWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(310, 40, 461, 281));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:10pt;\n"
"border-radius:15px;\n"
"width:65%;\n"
"height:45%;"));
        textEdit = new QTextEdit(QuesAnsWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(310, 380, 461, 161));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        textEdit->setFont(font1);
        praiseButton = new QPushButton(QuesAnsWindow);
        praiseButton->setObjectName(QStringLiteral("praiseButton"));
        praiseButton->setGeometry(QRect(650, 340, 61, 31));
        praiseButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0,200,250);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        praiseButton->setCheckable(false);
        label_prsnum = new QLabel(QuesAnsWindow);
        label_prsnum->setObjectName(QStringLiteral("label_prsnum"));
        label_prsnum->setGeometry(QRect(580, 350, 54, 12));
        label_prsnum->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_dazhu = new QLabel(QuesAnsWindow);
        label_dazhu->setObjectName(QStringLiteral("label_dazhu"));
        label_dazhu->setGeometry(QRect(310, 350, 81, 21));
        label_dazhu->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_time = new QLabel(QuesAnsWindow);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(540, 20, 191, 21));
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        focusDZButton = new QPushButton(QuesAnsWindow);
        focusDZButton->setObjectName(QStringLiteral("focusDZButton"));
        focusDZButton->setGeometry(QRect(400, 340, 81, 31));
        focusDZButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        focusDZButton->setCheckable(true);
        focusTZButton = new QPushButton(QuesAnsWindow);
        focusTZButton->setObjectName(QStringLiteral("focusTZButton"));
        focusTZButton->setGeometry(QRect(80, 220, 81, 31));
        focusTZButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        focusTZButton->setCheckable(true);
        label_tizhu = new QLabel(QuesAnsWindow);
        label_tizhu->setObjectName(QStringLiteral("label_tizhu"));
        label_tizhu->setGeometry(QRect(3, 222, 81, 21));
        label_tizhu->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        textBrowser_2 = new QTextBrowser(QuesAnsWindow);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 40, 281, 171));
        textBrowser_2->setFont(font1);
        freshButton = new QPushButton(QuesAnsWindow);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setGeometry(QRect(20, 550, 101, 31));
        freshButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        inviteButton = new QPushButton(QuesAnsWindow);
        inviteButton->setObjectName(QStringLiteral("inviteButton"));
        inviteButton->setGeometry(QRect(180, 550, 101, 31));
        inviteButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        aboutTZButton = new QPushButton(QuesAnsWindow);
        aboutTZButton->setObjectName(QStringLiteral("aboutTZButton"));
        aboutTZButton->setGeometry(QRect(170, 220, 81, 31));
        aboutTZButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        aboutTZButton->setCheckable(true);
        aboutDZButton = new QPushButton(QuesAnsWindow);
        aboutDZButton->setObjectName(QStringLiteral("aboutDZButton"));
        aboutDZButton->setGeometry(QRect(490, 340, 81, 31));
        aboutDZButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        aboutDZButton->setCheckable(true);
        commentButton = new QPushButton(QuesAnsWindow);
        commentButton->setObjectName(QStringLiteral("commentButton"));
        commentButton->setGeometry(QRect(720, 340, 51, 31));
        commentButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0,200,250);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        commentButton->setCheckable(false);

        retranslateUi(QuesAnsWindow);

        QMetaObject::connectSlotsByName(QuesAnsWindow);
    } // setupUi

    void retranslateUi(QWidget *QuesAnsWindow)
    {
        QuesAnsWindow->setWindowTitle(QApplication::translate("QuesAnsWindow", "Form", Q_NULLPTR));
        label_title->setText(QApplication::translate("QuesAnsWindow", "TextLabel", Q_NULLPTR));
        answerQuesButton->setText(QApplication::translate("QuesAnsWindow", "\346\210\221\346\235\245\345\233\236\347\255\224", Q_NULLPTR));
        praiseButton->setText(QApplication::translate("QuesAnsWindow", "\350\265\236", Q_NULLPTR));
        label_prsnum->setText(QString());
        label_dazhu->setText(QString());
        label_time->setText(QString());
        focusDZButton->setText(QApplication::translate("QuesAnsWindow", "\345\205\263\346\263\250", Q_NULLPTR));
        focusTZButton->setText(QApplication::translate("QuesAnsWindow", "\345\205\263\346\263\250", Q_NULLPTR));
        label_tizhu->setText(QApplication::translate("QuesAnsWindow", "TextLabel", Q_NULLPTR));
        freshButton->setText(QApplication::translate("QuesAnsWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", Q_NULLPTR));
        inviteButton->setText(QApplication::translate("QuesAnsWindow", "\351\202\200\350\257\267\345\233\236\347\255\224", Q_NULLPTR));
        aboutTZButton->setText(QApplication::translate("QuesAnsWindow", "\345\205\263\344\272\216\351\242\230\344\270\273", Q_NULLPTR));
        aboutDZButton->setText(QApplication::translate("QuesAnsWindow", "\345\205\263\344\272\216\347\255\224\344\270\273", Q_NULLPTR));
        commentButton->setText(QApplication::translate("QuesAnsWindow", "\350\257\204\350\256\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QuesAnsWindow: public Ui_QuesAnsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESANSWINDOW_H
