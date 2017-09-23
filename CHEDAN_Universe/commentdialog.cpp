<<<<<<< HEAD
#include "commentdialog.h"
#include "ui_commentdialog.h"
#include "global.h"

#include <QMessageBox>
CommentDialog::CommentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommentDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

CommentDialog::~CommentDialog()
{
    delete ui;
}

void CommentDialog::showComments()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("评论")<<tr("用户")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setColumnWidth(0,400);
    int row=0;
    for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
        Notification notif = *it;

        if(notif.getType()==Type::Notice && notif.getAnswerId() == this->getAnswerId())
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(notif.getContent()));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(notif.getSenderId()).getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));

            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
            row++;
        }
    }
}

void CommentDialog::setAnswerId(int id)
{
    this->answerId = id;
}

int CommentDialog::getAnswerId()
{
    return this->answerId;
}
void CommentDialog::setAnswererId(int id)
{
    this->answererId = id;
}

int CommentDialog::getAnswererId()
{
    return this->answererId;
}
void CommentDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content!="")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->getAnswererId();
        int senderId = USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        QString title = QString("%1 评论了你的回答 ").arg(USER.getName());
        notif.created(id,userId,content,timestr);

        notif.setQuestionId(Global::getAnswer(this->getAnswerId()).getQuestionId());
        notif.setAnswerId(this->getAnswerId());
        notif.setSenderId(senderId);
        notif.setType(1);
        notif.setTitle(title);

        Global::insert(notif);
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入评论内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }

}

void CommentDialog::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "commentdialog.h"
#include "ui_commentdialog.h"
#include "global.h"

#include <QMessageBox>
CommentDialog::CommentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommentDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

CommentDialog::~CommentDialog()
{
    delete ui;
}

void CommentDialog::showComments()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("评论")<<tr("用户")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setColumnWidth(0,400);
    int row=0;
    for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
        Notification notif = *it;

        if(notif.getType()==Type::Notice && notif.getAnswerId() == this->getAnswerId())
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(notif.getContent()));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(notif.getSenderId()).getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));

            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
            row++;
        }
    }
}

void CommentDialog::setAnswerId(int id)
{
    this->answerId = id;
}

int CommentDialog::getAnswerId()
{
    return this->answerId;
}
void CommentDialog::setAnswererId(int id)
{
    this->answererId = id;
}

int CommentDialog::getAnswererId()
{
    return this->answererId;
}
void CommentDialog::on_buttonBox_accepted()
{
    QString content = ui->textEdit->toPlainText();
    if(content!="")
    {
        Notification notif;

        int id = Notifications.size()+1;
        int userId = this->getAnswererId();
        int senderId = USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        QString title = QString("%1 评论了你的回答 ").arg(USER.getName());
        notif.created(id,userId,content,timestr);

        notif.setQuestionId(Global::getAnswer(this->getAnswerId()).getQuestionId());
        notif.setAnswerId(this->getAnswerId());
        notif.setSenderId(senderId);
        notif.setType(1);
        notif.setTitle(title);

        Global::insert(notif);
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入评论内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }

}

void CommentDialog::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
