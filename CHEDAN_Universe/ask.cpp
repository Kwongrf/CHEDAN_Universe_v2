<<<<<<< HEAD
#include "ask.h"
#include "ui_ask.h"
#include "question.h"
#include "global.h"

#include <QMessageBox>
Ask::Ask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ask)
{
    ui->setupUi(this);
}

Ask::~Ask()
{
    delete ui;
}

void Ask::on_buttonBox_accepted()
{
    Question ques;

    int id=Questions.size()+1;
    int userId=USER.getId();

    QString currentTitle = ui->lineEdit->text();
    QString currentContent = ui->textEdit->toPlainText();
    if(currentTitle!=""&&currentContent!="")
    {
        //ques.setContent(currentContent);
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        //ques.setTime(timestr);


        ques.created(id,userId,currentContent,timestr);
        ques.setTitle(currentTitle);

        USER.handleAskList(ques.getId(),1);
        Global::update(USER);
        Global::insert(ques);

        qDebug()<<"ask success";
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入完整的标题和内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}

void Ask::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "ask.h"
#include "ui_ask.h"
#include "question.h"
#include "global.h"

#include <QMessageBox>
Ask::Ask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ask)
{
    ui->setupUi(this);
}

Ask::~Ask()
{
    delete ui;
}

void Ask::on_buttonBox_accepted()
{
    Question ques;

    int id=Questions.size()+1;
    int userId=USER.getId();

    QString currentTitle = ui->lineEdit->text();
    QString currentContent = ui->textEdit->toPlainText();
    if(currentTitle!=""&&currentContent!="")
    {
        //ques.setContent(currentContent);
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        //ques.setTime(timestr);


        ques.created(id,userId,currentContent,timestr);
        ques.setTitle(currentTitle);

        USER.handleAskList(ques.getId(),1);
        Global::update(USER);
        Global::insert(ques);

        qDebug()<<"ask success";
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入完整的标题和内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
}

void Ask::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
