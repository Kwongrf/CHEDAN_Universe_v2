/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_SignUp
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_5;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QStringLiteral("SignUp"));
        SignUp->resize(521, 511);
        buttonBox = new QDialogButtonBox(SignUp);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SignUp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 160, 54, 12));
        label->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_3 = new QLabel(SignUp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 240, 54, 12));
        label_3->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        label_2 = new QLabel(SignUp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 200, 54, 12));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        lineEdit_3 = new QLineEdit(SignUp);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 240, 201, 21));
        lineEdit_4 = new QLineEdit(SignUp);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 280, 201, 16));
        label_4 = new QLabel(SignUp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 280, 54, 12));
        label_4->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        lineEdit = new QLineEdit(SignUp);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 160, 201, 21));
        lineEdit_2 = new QLineEdit(SignUp);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 200, 201, 21));
        label_5 = new QLabel(SignUp);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 30, 191, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(36);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:rgb(100,100,100)"));

        retranslateUi(SignUp);
        QObject::connect(buttonBox, SIGNAL(accepted()), SignUp, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SignUp, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SignUp", "\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("SignUp", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignUp", "\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("SignUp", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("SignUp", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
