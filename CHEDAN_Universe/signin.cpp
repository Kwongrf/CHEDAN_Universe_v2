<<<<<<< HEAD
#include "signin.h"
#include "ui_signin.h"
#include "user.h"
#include "global.h"
#include <QMessageBox>
#include "signup.h"
SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->resize(594,492);
    this->setFixedSize(594,492);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_signInButton_clicked()
{
    User user;
    QString CurrentId = ui->lineEdit->text();
    QString CurrentPassWord = ui->lineEdit_2->text();
    bool* ok = NULL;
    int idInt = CurrentId.toInt(ok,10);
    qDebug()<<"idInt"<<idInt;
    user = Global::getUser(idInt);
    if(user.getId()!=-1)
    {
        if(user.getPassword()==CurrentPassWord)
        {

            accept();
            USER = user;
            qDebug()<<"USER.getId()"<<USER.getId();
            return;
        }
        else
        {
            ui->lineEdit_2->clear();
            QMessageBox fail(QMessageBox::NoIcon, "失败", "密码错误");
            fail.addButton("确定", QMessageBox::AcceptRole);
            fail.exec();
        }
    }
    else
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        QMessageBox fail(QMessageBox::NoIcon, "失败", "账户不存在");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}

void SignIn::on_signUpButton_clicked()
{
    SignUp signUpDlg;
    signUpDlg.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/527_511.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    signUpDlg.setPalette(palette);
    signUpDlg.exec();
}
=======
#include "signin.h"
#include "ui_signin.h"
#include "user.h"
#include "global.h"
#include <QMessageBox>
#include "signup.h"
SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->resize(594,492);
    this->setFixedSize(594,492);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_signInButton_clicked()
{
    User user;
    QString CurrentId = ui->lineEdit->text();
    QString CurrentPassWord = ui->lineEdit_2->text();
    bool* ok = NULL;
    int idInt = CurrentId.toInt(ok,10);
    qDebug()<<"idInt"<<idInt;
    user = Global::getUser(idInt);
    if(user.getId()!=-1)
    {
        if(user.getPassword()==CurrentPassWord)
        {

            accept();
            USER = user;
            qDebug()<<"USER.getId()"<<USER.getId();
            return;
        }
        else
        {
            ui->lineEdit_2->clear();
            QMessageBox fail(QMessageBox::NoIcon, "失败", "密码错误");
            fail.addButton("确定", QMessageBox::AcceptRole);
            fail.exec();
        }
    }
    else
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        QMessageBox fail(QMessageBox::NoIcon, "失败", "账户不存在");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}

void SignIn::on_signUpButton_clicked()
{
    SignUp signUpDlg;
    signUpDlg.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/527_511.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    signUpDlg.setPalette(palette);
    signUpDlg.exec();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
