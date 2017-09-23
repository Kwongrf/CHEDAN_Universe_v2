/********************************************************************************
** Form generated from reading UI file 'replydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYDIALOG_H
#define UI_REPLYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ReplyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ReplyDialog)
    {
        if (ReplyDialog->objectName().isEmpty())
            ReplyDialog->setObjectName(QStringLiteral("ReplyDialog"));
        ReplyDialog->resize(509, 350);
        buttonBox = new QDialogButtonBox(ReplyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(420, 240, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(ReplyDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 30, 371, 121));
        textEdit = new QTextEdit(ReplyDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 190, 371, 141));
        label = new QLabel(ReplyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 30, 54, 12));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_2 = new QLabel(ReplyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 190, 54, 12));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        retranslateUi(ReplyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReplyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReplyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReplyDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplyDialog)
    {
        ReplyDialog->setWindowTitle(QApplication::translate("ReplyDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReplyDialog", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReplyDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReplyDialog: public Ui_ReplyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYDIALOG_H
