<<<<<<< HEAD
#include "messagedialog.h"
#include "ui_messagedialog.h"
#include "global.h"
#include <QMessageBox>

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}
int MessageDialog::getReceiverId()
{
    return this->receiverId;
}
void MessageDialog::setReceiverId(int id)
{
    this->receiverId=id;
}

void MessageDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content!="")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->getReceiverId();
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

void MessageDialog::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "messagedialog.h"
#include "ui_messagedialog.h"
#include "global.h"
#include <QMessageBox>

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}
int MessageDialog::getReceiverId()
{
    return this->receiverId;
}
void MessageDialog::setReceiverId(int id)
{
    this->receiverId=id;
}

void MessageDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content!="")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->getReceiverId();
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

void MessageDialog::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
