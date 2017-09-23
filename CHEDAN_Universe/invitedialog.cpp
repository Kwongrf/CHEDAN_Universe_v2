<<<<<<< HEAD
#include "invitedialog.h"
#include "ui_invitedialog.h"
#include "global.h"

#include <QMessageBox>

InviteDialog::InviteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InviteDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("名称")<<tr("回答数")<<tr("获赞数");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    this->showFocus();
}

InviteDialog::~InviteDialog()
{
    delete ui;
}
int InviteDialog::getQuestionId()
{
    return this->questionId;
}
void InviteDialog::setQuestionId(int id)
{
    this->questionId=id;
}

void InviteDialog::showFocus()
{
    std::vector<int> focuslist = USER.getFocusList();
    int row=0;
    for(std::vector<int>::iterator it = focuslist.begin();it!=focuslist.end();++it)
    {
        User user = Global::getUser(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }

}

void InviteDialog::showFollowed()
{
    std::vector<int> followedlist = USER.getFollowedList();
    int row=0;
    for(std::vector<int>::iterator it = followedlist.begin();it!=followedlist.end();++it)
    {
        User user = Global::getUser(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void InviteDialog::showAll()
{
    int row=0;
    for(std::vector<User>::iterator it = Users.begin();it!=Users.end();++it)
    {
        User user = *it;

        if(USER.getId()!=user.getId())
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
}

void InviteDialog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    Notification notif;
    bool* ok = NULL;
    int id = Notifications.size()+1;
    int userId =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
    int senderId = USER.getId();
    int questionId = this->getQuestionId();
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    QString title = QString("%1 邀请你回答问题").arg(USER.getName());
    QString content = Global::getQuestion(questionId).getTitle();
    notif.created(id,userId,content,timestr);
    notif.setQuestionId(questionId);
    notif.setAnswerId(0);
    notif.setSenderId(senderId);
    notif.setType(1);
    notif.setTitle(title);

    Global::insert(notif);

    QMessageBox fail(QMessageBox::NoIcon, "成功", "邀请已发送");
    fail.addButton("确定", QMessageBox::AcceptRole);
    fail.exec();
    this->close();
}


void InviteDialog::on_radioButton_clicked()
{
    this->showFocus();

}

void InviteDialog::on_radioButton_2_clicked()
{
    this->showFollowed();
}

void InviteDialog::on_radioButton_3_clicked()
{
    this->showAll();
}

=======
#include "invitedialog.h"
#include "ui_invitedialog.h"
#include "global.h"

#include <QMessageBox>

InviteDialog::InviteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InviteDialog)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("名称")<<tr("回答数")<<tr("获赞数");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    this->showFocus();
}

InviteDialog::~InviteDialog()
{
    delete ui;
}
int InviteDialog::getQuestionId()
{
    return this->questionId;
}
void InviteDialog::setQuestionId(int id)
{
    this->questionId=id;
}

void InviteDialog::showFocus()
{
    std::vector<int> focuslist = USER.getFocusList();
    int row=0;
    for(std::vector<int>::iterator it = focuslist.begin();it!=focuslist.end();++it)
    {
        User user = Global::getUser(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }

}

void InviteDialog::showFollowed()
{
    std::vector<int> followedlist = USER.getFollowedList();
    int row=0;
    for(std::vector<int>::iterator it = followedlist.begin();it!=followedlist.end();++it)
    {
        User user = Global::getUser(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void InviteDialog::showAll()
{
    int row=0;
    for(std::vector<User>::iterator it = Users.begin();it!=Users.end();++it)
    {
        User user = *it;

        if(USER.getId()!=user.getId())
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(user.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(user.getPraisedNum()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
}

void InviteDialog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    Notification notif;
    bool* ok = NULL;
    int id = Notifications.size()+1;
    int userId =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
    int senderId = USER.getId();
    int questionId = this->getQuestionId();
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    QString title = QString("%1 邀请你回答问题").arg(USER.getName());
    QString content = Global::getQuestion(questionId).getTitle();
    notif.created(id,userId,content,timestr);
    notif.setQuestionId(questionId);
    notif.setAnswerId(0);
    notif.setSenderId(senderId);
    notif.setType(1);
    notif.setTitle(title);

    Global::insert(notif);

    QMessageBox fail(QMessageBox::NoIcon, "成功", "邀请已发送");
    fail.addButton("确定", QMessageBox::AcceptRole);
    fail.exec();
    this->close();
}


void InviteDialog::on_radioButton_clicked()
{
    this->showFocus();

}

void InviteDialog::on_radioButton_2_clicked()
{
    this->showFollowed();
}

void InviteDialog::on_radioButton_3_clicked()
{
    this->showAll();
}

>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
