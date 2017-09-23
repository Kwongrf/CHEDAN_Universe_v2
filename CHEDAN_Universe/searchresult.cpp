<<<<<<< HEAD
#include "searchresult.h"
#include "ui_searchresult.h"
#include "global.h"

SearchResult::SearchResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);

    this->resize(1024,576);
    this->setFixedSize(1024,576);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg7.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    qDebug()<<"1";
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("回答数")<<tr("题主")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget_2->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header2;
    header2<<tr("ID")<<tr("回答")<<tr("问题")<<tr("获赞数")<<tr("答主")<<tr("时间");;
    ui->tableWidget_2->setHorizontalHeaderLabels(header2);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_2->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_3->setRowCount(0);
    ui->tableWidget_3->setColumnCount(5);
    ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget_3->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header3;
    header3<<tr("ID")<<tr("用户名")<<tr("回答数")<<tr("提问数")<<tr("获赞数");
    ui->tableWidget_3->setHorizontalHeaderLabels(header3);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->setShowGrid(false);
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_3->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_3->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
}

SearchResult::~SearchResult()
{
    delete ui;
}

bool SearchResult::search(QString str)
{
    Question q;
    q.setTitle(str);
    this->search(q);
    qDebug()<<"search question";
    Answer a;
    a.setContent(str);
    this->search(a);
    qDebug()<<"search answer";
    User u;
    u.setName(str);
    this->search(u);
    qDebug()<<"search user";

}

bool SearchResult::search(Question q)
{
    int row=0;
    for(vector<Question>::iterator it = Questions.begin(); it!=Questions.end(); ++it)
    {
        Question que=*it;
        if(que.getTitle().contains(q.getTitle()))
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(que.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(que.getTitle()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(Global::getUser(que.getUserId()).getName()));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(que.getTime()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            row++;

        }
    }
    if(row == 0)
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("未找到相关问题")));
}

bool SearchResult::search(Answer a)
{
    int row=0;
    for(vector<Answer>::iterator it = Answers.begin(); it!=Answers.end(); ++it)
    {
        Answer ans=*it;
        if(ans.getContent().contains(a.getContent()))
        {
            ui->tableWidget_2->setRowCount(row+1);
            ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
            ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
            ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
            ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
            ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
            ui->tableWidget_2->setItem(row,5,new QTableWidgetItem(ans.getTime()));
            for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(QString("未找到相关回答")));
}

bool SearchResult::search(User u)
{
    int row=0;
    for(vector<User>::iterator it = Users.begin(); it!=Users.end(); ++it)
    {
        User user=*it;
        if(user.getName().contains(u.getName()))
        {
            ui->tableWidget_3->setRowCount(row+1);
            ui->tableWidget_3->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
            ui->tableWidget_3->setItem(row,1,new QTableWidgetItem(user.getName()));
            ui->tableWidget_3->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
            ui->tableWidget_3->setItem(row,3,new QTableWidgetItem(user.getAskList().size()));
            ui->tableWidget_3->setItem(row,4,new QTableWidgetItem(user.getPraisedNum()));
            for(int col = 0;col<ui->tableWidget_3->columnCount();col++)
                ui->tableWidget_3->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(QString("未找到相关用户")));
}

bool SearchResult::search(QDate d)
{
    qDebug()<<"search question by time";
    QString timestr = d.toString("yyyy-MM-dd");
    ui->tableWidget_3->setVisible(false);
    ui->label_3->setVisible(false);
    this->resize(720,612);
    int row1=0;
    for(vector<Question>::iterator it = Questions.begin(); it!=Questions.end(); ++it)
    {
        Question que=*it;
        if(que.getTime().contains(timestr))
        {
            ui->tableWidget->setRowCount(row1+1);
            ui->tableWidget->setItem(row1,0,new QTableWidgetItem(QString::number(que.getId())));
            ui->tableWidget->setItem(row1,1,new QTableWidgetItem(que.getTitle()));
            ui->tableWidget->setItem(row1,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
            ui->tableWidget->setItem(row1,3,new QTableWidgetItem(Global::getUser(que.getUserId()).getName()));
            ui->tableWidget->setItem(row1,4,new QTableWidgetItem(que.getTime()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row1,col)->setTextColor(QColor(220,220,220));
            row1++;

        }
    }
    if(row1 == 0)
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("未找到相关问题")));
    qDebug()<<"search answer by time";
    int row=0;
    for(vector<Answer>::iterator it = Answers.begin(); it!=Answers.end(); ++it)
    {
        Answer ans=*it;
        if(ans.getTime().contains(timestr))
        {
            ui->tableWidget_2->setRowCount(row+1);
            ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
            ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
            ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
            ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
            ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
            ui->tableWidget_2->setItem(row,5,new QTableWidgetItem(ans.getTime()));
            for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(QString("未找到相关回答")));
    qDebug()<<"end search by time";
}
=======
#include "searchresult.h"
#include "ui_searchresult.h"
#include "global.h"

SearchResult::SearchResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);

    this->resize(1024,576);
    this->setFixedSize(1024,576);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg7.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    qDebug()<<"1";
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("回答数")<<tr("题主")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget_2->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header2;
    header2<<tr("ID")<<tr("回答")<<tr("问题")<<tr("获赞数")<<tr("答主")<<tr("时间");;
    ui->tableWidget_2->setHorizontalHeaderLabels(header2);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_2->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_3->setRowCount(0);
    ui->tableWidget_3->setColumnCount(5);
    ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget_3->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header3;
    header3<<tr("ID")<<tr("用户名")<<tr("回答数")<<tr("提问数")<<tr("获赞数");
    ui->tableWidget_3->setHorizontalHeaderLabels(header3);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->setShowGrid(false);
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_3->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_3->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
}

SearchResult::~SearchResult()
{
    delete ui;
}

bool SearchResult::search(QString str)
{
    Question q;
    q.setTitle(str);
    this->search(q);
    qDebug()<<"search question";
    Answer a;
    a.setContent(str);
    this->search(a);
    qDebug()<<"search answer";
    User u;
    u.setName(str);
    this->search(u);
    qDebug()<<"search user";

}

bool SearchResult::search(Question q)
{
    int row=0;
    for(vector<Question>::iterator it = Questions.begin(); it!=Questions.end(); ++it)
    {
        Question que=*it;
        if(que.getTitle().contains(q.getTitle()))
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(que.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(que.getTitle()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(Global::getUser(que.getUserId()).getName()));
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(que.getTime()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            row++;

        }
    }
    if(row == 0)
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("未找到相关问题")));
}

bool SearchResult::search(Answer a)
{
    int row=0;
    for(vector<Answer>::iterator it = Answers.begin(); it!=Answers.end(); ++it)
    {
        Answer ans=*it;
        if(ans.getContent().contains(a.getContent()))
        {
            ui->tableWidget_2->setRowCount(row+1);
            ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
            ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
            ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
            ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
            ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
            ui->tableWidget_2->setItem(row,5,new QTableWidgetItem(ans.getTime()));
            for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(QString("未找到相关回答")));
}

bool SearchResult::search(User u)
{
    int row=0;
    for(vector<User>::iterator it = Users.begin(); it!=Users.end(); ++it)
    {
        User user=*it;
        if(user.getName().contains(u.getName()))
        {
            ui->tableWidget_3->setRowCount(row+1);
            ui->tableWidget_3->setItem(row,0,new QTableWidgetItem(QString::number(user.getId())));
            ui->tableWidget_3->setItem(row,1,new QTableWidgetItem(user.getName()));
            ui->tableWidget_3->setItem(row,2,new QTableWidgetItem(user.getAnswerList().size()));
            ui->tableWidget_3->setItem(row,3,new QTableWidgetItem(user.getAskList().size()));
            ui->tableWidget_3->setItem(row,4,new QTableWidgetItem(user.getPraisedNum()));
            for(int col = 0;col<ui->tableWidget_3->columnCount();col++)
                ui->tableWidget_3->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(QString("未找到相关用户")));
}

bool SearchResult::search(QDate d)
{
    qDebug()<<"search question by time";
    QString timestr = d.toString("yyyy-MM-dd");
    ui->tableWidget_3->setVisible(false);
    ui->label_3->setVisible(false);
    this->resize(720,612);
    int row1=0;
    for(vector<Question>::iterator it = Questions.begin(); it!=Questions.end(); ++it)
    {
        Question que=*it;
        if(que.getTime().contains(timestr))
        {
            ui->tableWidget->setRowCount(row1+1);
            ui->tableWidget->setItem(row1,0,new QTableWidgetItem(QString::number(que.getId())));
            ui->tableWidget->setItem(row1,1,new QTableWidgetItem(que.getTitle()));
            ui->tableWidget->setItem(row1,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
            ui->tableWidget->setItem(row1,3,new QTableWidgetItem(Global::getUser(que.getUserId()).getName()));
            ui->tableWidget->setItem(row1,4,new QTableWidgetItem(que.getTime()));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row1,col)->setTextColor(QColor(220,220,220));
            row1++;

        }
    }
    if(row1 == 0)
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("未找到相关问题")));
    qDebug()<<"search answer by time";
    int row=0;
    for(vector<Answer>::iterator it = Answers.begin(); it!=Answers.end(); ++it)
    {
        Answer ans=*it;
        if(ans.getTime().contains(timestr))
        {
            ui->tableWidget_2->setRowCount(row+1);
            ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
            ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
            ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
            ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
            ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
            ui->tableWidget_2->setItem(row,5,new QTableWidgetItem(ans.getTime()));
            for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
            row++;
        }
    }
    if(row == 0)
        ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(QString("未找到相关回答")));
    qDebug()<<"end search by time";
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
