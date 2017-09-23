/********************************************************************************
** Form generated from reading UI file 'commentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTDIALOG_H
#define UI_COMMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CommentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *CommentDialog)
    {
        if (CommentDialog->objectName().isEmpty())
            CommentDialog->setObjectName(QStringLiteral("CommentDialog"));
        CommentDialog->resize(495, 484);
        buttonBox = new QDialogButtonBox(CommentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(120, 440, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(CommentDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 50, 431, 331));
        textEdit = new QTextEdit(CommentDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 390, 431, 51));
        label = new QLabel(CommentDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 54, 12));

        retranslateUi(CommentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommentDialog);
    } // setupUi

    void retranslateUi(QDialog *CommentDialog)
    {
        CommentDialog->setWindowTitle(QApplication::translate("CommentDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CommentDialog", "\350\257\204\350\256\272\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommentDialog: public Ui_CommentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTDIALOG_H
