/********************************************************************************
** Form generated from reading UI file 'changename.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGENAME_H
#define UI_CHANGENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ChangeName
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *ChangeName)
    {
        if (ChangeName->objectName().isEmpty())
            ChangeName->setObjectName(QStringLiteral("ChangeName"));
        ChangeName->resize(338, 234);
        buttonBox = new QDialogButtonBox(ChangeName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(240, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(ChangeName);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 110, 141, 20));
        label = new QLabel(ChangeName);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 110, 54, 21));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_2 = new QLabel(ChangeName);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 90, 54, 12));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_3 = new QLabel(ChangeName);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 90, 141, 16));
        label_3->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        retranslateUi(ChangeName);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeName, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeName);
    } // setupUi

    void retranslateUi(QDialog *ChangeName)
    {
        ChangeName->setWindowTitle(QApplication::translate("ChangeName", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeName", "\346\226\260\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeName", "\345\216\237\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeName", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeName: public Ui_ChangeName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGENAME_H
