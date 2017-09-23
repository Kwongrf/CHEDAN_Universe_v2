<<<<<<< HEAD
#include "focuswindow.h"
#include "ui_focuswindow.h"
#include "global.h"
#include "userdatawindow.h"

#include <QPushButton>
FocusWindow::FocusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FocusWindow)
{
    ui->setupUi(this);
    this->resize(1024,576);
    this->setFixedSize(1024,576);
    qDebug()<<"1";
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("用户名")<<tr("回答数")<<tr("提问数")<<tr("获赞数")<<tr("关注数")<<tr("粉丝数")<<tr("操作");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->show();
    qDebug()<<"2";
    //vector<Question> questions = Db.queryAllQues();

}

FocusWindow::~FocusWindow()
{
    delete ui;
}
void FocusWindow::showTable(bool type)
{
    if(type)//查看我的关注
    {
        ui->label->setText("我的关注列表");
        int flag=0;
        int row = 0;
        qDebug()<<"24";
        for(int i = USER.getFocusList().size()-1;i>=0;i--)
        {
            int id = USER.getFocusList().at(i);
            User u = Global::getUser(id);
            if(u.getId()==-1)
                break;
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(u.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(u.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(u.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(u.getAskList().size())));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(u.getPraisedNum())));
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(u.getFocusList().size())));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(QString::number(u.getFollowedList().size())));
            QPushButton * pBtn = new QPushButton();
            pBtn->setText("取消关注");
            pBtn->setStyleSheet("color:rgb(255,255,255)");
            connect(pBtn, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
            ui->tableWidget->setCellWidget(row,7,pBtn);
            qDebug()<<QString::number(u.getId())<<" "<<u.getName()<<row<<" "<<i<<" "<<USER.getFocusList().size();
            row++;
            flag=1;
        }
        for(int row = 0;row < USER.getFocusList().size();row++)
        {
            for(int col = 0;col<7;col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        }
        if(flag==0)
             ui->tableWidget->setRowCount(0);
        ui->tableWidget->show();
         qDebug()<<"3";
    }
    else
    {
        ui->label->setText("我的粉丝列表");
        int flag=0;
        int row = 0;
        qDebug()<<"24";
        for(int i = USER.getFollowedList().size()-1;i>=0;i--)
        {
            int id = USER.getFollowedList().at(i);
            User u = Global::getUser(id);
            if(u.getId()==-1)
                break;
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(u.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(u.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(u.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(u.getAskList().size())));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(u.getPraisedNum())));
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(u.getFocusList().size())));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(QString::number(u.getFollowedList().size())));

            qDebug()<<QString::number(u.getId())<<" "<<u.getName()<<row<<" "<<i<<" "<<USER.getFocusList().size();
            row++;
            flag=1;
        }
        for(int row = 0;row < USER.getFollowedList().size();row++)
        {
            for(int col = 0;col<7;col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        }
        if(flag==0)
             ui->tableWidget->setRowCount(0);
        ui->tableWidget->show();
         qDebug()<<"3";
    }

}
void FocusWindow::onBtnClicked(void)
{
    QPushButton * senderObj=qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=index.row();
    qDebug()<<"row:"<<row;
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
    User user = Global::getUser(id);
    USER.handleFocusList(id,0);
    user.handleFollowedList(USER.getId(),0);
    Global::update(USER);
    Global::update(user);
    qDebug()<<"取消关注成功";
    this->showTable(1);
}

void FocusWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(id);
    uw->show();
    uw->showAllDatas();
    this->close();
}
=======
#include "focuswindow.h"
#include "ui_focuswindow.h"
#include "global.h"
#include "userdatawindow.h"

#include <QPushButton>
FocusWindow::FocusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FocusWindow)
{
    ui->setupUi(this);
    this->resize(1024,576);
    this->setFixedSize(1024,576);
    qDebug()<<"1";
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("用户名")<<tr("回答数")<<tr("提问数")<<tr("获赞数")<<tr("关注数")<<tr("粉丝数")<<tr("操作");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->show();
    qDebug()<<"2";
    //vector<Question> questions = Db.queryAllQues();

}

FocusWindow::~FocusWindow()
{
    delete ui;
}
void FocusWindow::showTable(bool type)
{
    if(type)//查看我的关注
    {
        ui->label->setText("我的关注列表");
        int flag=0;
        int row = 0;
        qDebug()<<"24";
        for(int i = USER.getFocusList().size()-1;i>=0;i--)
        {
            int id = USER.getFocusList().at(i);
            User u = Global::getUser(id);
            if(u.getId()==-1)
                break;
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(u.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(u.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(u.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(u.getAskList().size())));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(u.getPraisedNum())));
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(u.getFocusList().size())));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(QString::number(u.getFollowedList().size())));
            QPushButton * pBtn = new QPushButton();
            pBtn->setText("取消关注");
            pBtn->setStyleSheet("color:rgb(255,255,255)");
            connect(pBtn, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
            ui->tableWidget->setCellWidget(row,7,pBtn);
            qDebug()<<QString::number(u.getId())<<" "<<u.getName()<<row<<" "<<i<<" "<<USER.getFocusList().size();
            row++;
            flag=1;
        }
        for(int row = 0;row < USER.getFocusList().size();row++)
        {
            for(int col = 0;col<7;col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        }
        if(flag==0)
             ui->tableWidget->setRowCount(0);
        ui->tableWidget->show();
         qDebug()<<"3";
    }
    else
    {
        ui->label->setText("我的粉丝列表");
        int flag=0;
        int row = 0;
        qDebug()<<"24";
        for(int i = USER.getFollowedList().size()-1;i>=0;i--)
        {
            int id = USER.getFollowedList().at(i);
            User u = Global::getUser(id);
            if(u.getId()==-1)
                break;
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(u.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(u.getName()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(u.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(u.getAskList().size())));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(u.getPraisedNum())));
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(u.getFocusList().size())));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(QString::number(u.getFollowedList().size())));

            qDebug()<<QString::number(u.getId())<<" "<<u.getName()<<row<<" "<<i<<" "<<USER.getFocusList().size();
            row++;
            flag=1;
        }
        for(int row = 0;row < USER.getFollowedList().size();row++)
        {
            for(int col = 0;col<7;col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        }
        if(flag==0)
             ui->tableWidget->setRowCount(0);
        ui->tableWidget->show();
         qDebug()<<"3";
    }

}
void FocusWindow::onBtnClicked(void)
{
    QPushButton * senderObj=qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=index.row();
    qDebug()<<"row:"<<row;
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
    User user = Global::getUser(id);
    USER.handleFocusList(id,0);
    user.handleFollowedList(USER.getId(),0);
    Global::update(USER);
    Global::update(user);
    qDebug()<<"取消关注成功";
    this->showTable(1);
}

void FocusWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(id);
    uw->show();
    uw->showAllDatas();
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
