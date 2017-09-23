/********************************************************************************
** Form generated from reading UI file 'noticewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICEWINDOW_H
#define UI_NOTICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoticeWindow
{
public:
    QPushButton *noticeButton;
    QPushButton *praiseButton;
    QPushButton *focusButton;
    QPushButton *messageButton;
    QTableWidget *tableWidget;
    QLabel *label_2;

    void setupUi(QWidget *NoticeWindow)
    {
        if (NoticeWindow->objectName().isEmpty())
            NoticeWindow->setObjectName(QStringLiteral("NoticeWindow"));
        NoticeWindow->resize(849, 471);
        noticeButton = new QPushButton(NoticeWindow);
        noticeButton->setObjectName(QStringLiteral("noticeButton"));
        noticeButton->setGeometry(QRect(70, 80, 121, 23));
        noticeButton->setCheckable(true);
        noticeButton->setChecked(true);
        praiseButton = new QPushButton(NoticeWindow);
        praiseButton->setObjectName(QStringLiteral("praiseButton"));
        praiseButton->setGeometry(QRect(190, 80, 111, 23));
        praiseButton->setCheckable(true);
        focusButton = new QPushButton(NoticeWindow);
        focusButton->setObjectName(QStringLiteral("focusButton"));
        focusButton->setGeometry(QRect(300, 80, 111, 23));
        focusButton->setCheckable(true);
        messageButton = new QPushButton(NoticeWindow);
        messageButton->setObjectName(QStringLiteral("messageButton"));
        messageButton->setGeometry(QRect(410, 80, 111, 23));
        messageButton->setCheckable(true);
        tableWidget = new QTableWidget(NoticeWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 100, 701, 351));
        label_2 = new QLabel(NoticeWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 20, 221, 41));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"font: 22pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 185,0);\n"
"border-radius:15px;\n"
""));

        retranslateUi(NoticeWindow);

        QMetaObject::connectSlotsByName(NoticeWindow);
    } // setupUi

    void retranslateUi(QWidget *NoticeWindow)
    {
        NoticeWindow->setWindowTitle(QApplication::translate("NoticeWindow", "Form", Q_NULLPTR));
        noticeButton->setText(QApplication::translate("NoticeWindow", "\351\200\232\347\237\245", Q_NULLPTR));
        praiseButton->setText(QApplication::translate("NoticeWindow", "\350\265\236", Q_NULLPTR));
        focusButton->setText(QApplication::translate("NoticeWindow", "\345\205\263\346\263\250", Q_NULLPTR));
        messageButton->setText(QApplication::translate("NoticeWindow", "\347\247\201\344\277\241", Q_NULLPTR));
        label_2->setText(QApplication::translate("NoticeWindow", "       \346\266\210\346\201\257\344\270\255\345\277\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoticeWindow: public Ui_NoticeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICEWINDOW_H
