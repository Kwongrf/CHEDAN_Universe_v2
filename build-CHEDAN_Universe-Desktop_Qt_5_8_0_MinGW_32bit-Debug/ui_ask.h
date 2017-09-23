/********************************************************************************
** Form generated from reading UI file 'ask.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASK_H
#define UI_ASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Ask
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *Ask)
    {
        if (Ask->objectName().isEmpty())
            Ask->setObjectName(QStringLiteral("Ask"));
        Ask->resize(473, 477);
        buttonBox = new QDialogButtonBox(Ask);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 420, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Ask);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 401, 21));
        textEdit = new QTextEdit(Ask);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 90, 401, 311));
        label = new QLabel(Ask);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 54, 12));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        retranslateUi(Ask);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ask, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ask, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ask);
    } // setupUi

    void retranslateUi(QDialog *Ask)
    {
        Ask->setWindowTitle(QApplication::translate("Ask", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Ask", "\346\217\220\351\227\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ask: public Ui_Ask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASK_H
