/********************************************************************************
** Form generated from reading UI file 'changeprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPROFILE_H
#define UI_CHANGEPROFILE_H

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

class Ui_ChangeProfile
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *ChangeProfile)
    {
        if (ChangeProfile->objectName().isEmpty())
            ChangeProfile->setObjectName(QStringLiteral("ChangeProfile"));
        ChangeProfile->resize(400, 300);
        buttonBox = new QDialogButtonBox(ChangeProfile);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(ChangeProfile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 90, 191, 20));
        lineEdit_2 = new QLineEdit(ChangeProfile);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 130, 191, 20));
        lineEdit_3 = new QLineEdit(ChangeProfile);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 170, 191, 20));
        label = new QLabel(ChangeProfile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 92, 54, 20));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_2 = new QLabel(ChangeProfile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 130, 54, 20));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_3 = new QLabel(ChangeProfile);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 170, 71, 20));
        label_3->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));

        retranslateUi(ChangeProfile);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeProfile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeProfile, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeProfile);
    } // setupUi

    void retranslateUi(QDialog *ChangeProfile)
    {
        ChangeProfile->setWindowTitle(QApplication::translate("ChangeProfile", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeProfile", "\345\216\237\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeProfile", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeProfile", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeProfile: public Ui_ChangeProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPROFILE_H
