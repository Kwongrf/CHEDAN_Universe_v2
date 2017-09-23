<<<<<<< HEAD
#include "signup.h"
#include "ui_signup.h"
#include "global.h"

#include <QMessageBox>
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->resize(527,511);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_buttonBox_accepted()
{
    QString id = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString cfpassword = ui->lineEdit_3->text();
    QString name = ui->lineEdit_4->text();
    bool* ok = NULL;
    User user=Global::getUser(id.toInt(ok,10));
    if(user.getId()!=-1)
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "该账号已存在");
        ui->lineEdit->clear();
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    else if(password == cfpassword)
    {
        user.setId(id.toInt());
        user.setPassword(password);
        user.setName(name);
        user.setPraisedNum(0);
        vector<int> ls;
        user.setFocusList(ls);
        user.setFollowedList(ls);
        user.setPraiseList(ls);
        user.setAnswerList(ls);
        user.setAskList(ls);
        Global::insert(user);
        this->close();

    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "两次密码不一致");
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}



void SignUp::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "signup.h"
#include "ui_signup.h"
#include "global.h"

#include <QMessageBox>
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->resize(527,511);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_buttonBox_accepted()
{
    QString id = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString cfpassword = ui->lineEdit_3->text();
    QString name = ui->lineEdit_4->text();
    bool* ok = NULL;
    User user=Global::getUser(id.toInt(ok,10));
    if(user.getId()!=-1)
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "该账号已存在");
        ui->lineEdit->clear();
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    else if(password == cfpassword)
    {
        user.setId(id.toInt());
        user.setPassword(password);
        user.setName(name);
        user.setPraisedNum(0);
        vector<int> ls;
        user.setFocusList(ls);
        user.setFollowedList(ls);
        user.setPraiseList(ls);
        user.setAnswerList(ls);
        user.setAskList(ls);
        Global::insert(user);
        this->close();

    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "两次密码不一致");
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}



void SignUp::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
