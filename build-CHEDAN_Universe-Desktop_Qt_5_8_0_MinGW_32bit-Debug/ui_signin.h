/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *signInButton;
    QLabel *label;
    QPushButton *signUpButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName(QStringLiteral("SignIn"));
        SignIn->resize(596, 498);
        lineEdit_2 = new QLineEdit(SignIn);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 330, 241, 21));
        label_2 = new QLabel(SignIn);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 320, 71, 31));
        label_2->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:13pt;"));
        signInButton = new QPushButton(SignIn);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        signInButton->setGeometry(QRect(170, 390, 81, 31));
        signInButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 185, 227);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        label = new QLabel(SignIn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 280, 54, 21));
        label->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"font:13pt;"));
        signUpButton = new QPushButton(SignIn);
        signUpButton->setObjectName(QStringLiteral("signUpButton"));
        signUpButton->setGeometry(QRect(330, 390, 81, 31));
        signUpButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(100,100,100);\n"
"border-radius:15px;\n"
"width:130px;\n"
"height:70px;"));
        lineEdit = new QLineEdit(SignIn);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 280, 241, 21));

        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QDialog *SignIn)
    {
        SignIn->setWindowTitle(QApplication::translate("SignIn", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignIn", "\345\257\206\347\240\201", Q_NULLPTR));
        signInButton->setText(QApplication::translate("SignIn", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("SignIn", "\350\264\246\345\217\267", Q_NULLPTR));
        signUpButton->setText(QApplication::translate("SignIn", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
