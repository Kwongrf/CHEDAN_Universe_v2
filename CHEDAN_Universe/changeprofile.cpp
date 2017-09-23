<<<<<<< HEAD
#include "changeprofile.h"
#include "ui_changeprofile.h"
#include "global.h"

#include <QMessageBox>
ChangeProfile::ChangeProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeProfile)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ChangeProfile::~ChangeProfile()
{
    delete ui;
}

void ChangeProfile::on_buttonBox_accepted()
{
    QString oldPass = ui->lineEdit->text();
    if(oldPass != USER.getPassword())
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "原密码错误");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    else
    {
        QString newPass = ui->lineEdit_2->text();
        QString newPassCf = ui->lineEdit_3->text();
        if (newPass != newPassCf)
        {
            QMessageBox fail(QMessageBox::NoIcon, "失败", "两次密码不一致");
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            fail.addButton("确定", QMessageBox::AcceptRole);
            fail.exec();
        }
        else
        {
            USER.setPassword(newPass);
            Global::update(USER);
        }
    }
}

void ChangeProfile::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "changeprofile.h"
#include "ui_changeprofile.h"
#include "global.h"

#include <QMessageBox>
ChangeProfile::ChangeProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeProfile)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ChangeProfile::~ChangeProfile()
{
    delete ui;
}

void ChangeProfile::on_buttonBox_accepted()
{
    QString oldPass = ui->lineEdit->text();
    if(oldPass != USER.getPassword())
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "原密码错误");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    else
    {
        QString newPass = ui->lineEdit_2->text();
        QString newPassCf = ui->lineEdit_3->text();
        if (newPass != newPassCf)
        {
            QMessageBox fail(QMessageBox::NoIcon, "失败", "两次密码不一致");
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            fail.addButton("确定", QMessageBox::AcceptRole);
            fail.exec();
        }
        else
        {
            USER.setPassword(newPass);
            Global::update(USER);
        }
    }
}

void ChangeProfile::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
