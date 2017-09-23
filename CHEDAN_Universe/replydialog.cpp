<<<<<<< HEAD
#include "replydialog.h"
#include "ui_replydialog.h"
#include "global.h"

#include <QMessageBox>
ReplyDialog::ReplyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplyDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ReplyDialog::~ReplyDialog()
{
    delete ui;
}
void ReplyDialog::setNotif(Notification notif)
{
    this->notif=notif;
}

Notification ReplyDialog::getNotif()
{
    return this->notif;
}
void ReplyDialog::showMessage()
{//原本把这部分放在构造函数里了，但是老师出错，原因是这里面用到了成员变量，而构造时还没有赋值，所以一直是金疙瘩，应该赋值notif后在show
    ui->textBrowser->setText(this->notif.getContent());
    ui->label->setText(Global::getUser(this->notif.getSenderId()).getName());
    ui->label_2->setText(USER.getName());
}

void ReplyDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content != "")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->notif.getSenderId();
        int senderId = USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        QString title = QString("%1 给你发了一条私信").arg(USER.getName());
        notif.created(id,userId,content,timestr);
        notif.setQuestionId(0);
        notif.setAnswerId(0);
        notif.setSenderId(senderId);
        notif.setType(4);
        notif.setTitle(title);

        Global::insert(notif);
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}
=======
#include "replydialog.h"
#include "ui_replydialog.h"
#include "global.h"

#include <QMessageBox>
ReplyDialog::ReplyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplyDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ReplyDialog::~ReplyDialog()
{
    delete ui;
}
void ReplyDialog::setNotif(Notification notif)
{
    this->notif=notif;
}

Notification ReplyDialog::getNotif()
{
    return this->notif;
}
void ReplyDialog::showMessage()
{//原本把这部分放在构造函数里了，但是老师出错，原因是这里面用到了成员变量，而构造时还没有赋值，所以一直是金疙瘩，应该赋值notif后在show
    ui->textBrowser->setText(this->notif.getContent());
    ui->label->setText(Global::getUser(this->notif.getSenderId()).getName());
    ui->label_2->setText(USER.getName());
}

void ReplyDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content != "")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->notif.getSenderId();
        int senderId = USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        QString title = QString("%1 给你发了一条私信").arg(USER.getName());
        notif.created(id,userId,content,timestr);
        notif.setQuestionId(0);
        notif.setAnswerId(0);
        notif.setSenderId(senderId);
        notif.setType(4);
        notif.setTitle(title);

        Global::insert(notif);
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
