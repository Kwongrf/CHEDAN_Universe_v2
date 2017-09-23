<<<<<<< HEAD
#include "userdatawindow.h"
#include "ui_userdatawindow.h"
#include "global.h"
#include "signin.h"
#include "changeprofile.h"
#include "changename.h"
#include "quesanswindow.h"
#include "messagedialog.h"

#include <QMessageBox>

UserdataWindow::UserdataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserdataWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg7.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->resize(833,547);
    this->setFixedSize(833,547);


    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("回答数")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(5);
    ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget_2->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header2;
    header2<<tr("ID")<<tr("答案")<<tr("问题")<<tr("问题ID")<<tr("时间");
    ui->tableWidget_2->setHorizontalHeaderLabels(header2);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_2->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");


}

UserdataWindow::~UserdataWindow()
{
    delete ui;
}
void UserdataWindow::showAllDatas()
{
    this->showUserDatas();
    this->showAnswers();
    this->showQuestions();
}

void UserdataWindow::showUserDatas()
{
    User u = Global::getUser(this->userId);
    if(u.getId()!=USER.getId())
    {
        ui->changePassButton->setVisible(false);
        ui->changeNameButton->setVisible(false);
    }
    else
        ui->messageButton->setVisible(false);


    ui->label_id->setText(QString::number(u.getId()));
    ui->label_name->setText(u.getName());
    ui->label_ans->setText(QString::number(u.getAnswerList().size()));
    ui->label_ask->setText(QString::number(u.getAskList().size()));
    ui->label_focus->setText(QString::number(u.getFocusList().size()));
    ui->label_follow->setText(QString::number(u.getFollowedList().size()));
    ui->label_prs->setText(QString::number(u.getPraisedNum()));
}

void UserdataWindow::showQuestions()
{
    User u = Global::getUser(this->userId);
    vector<int> asklist = u.getAskList();
    int row=0;
    for(vector<int>::iterator it = asklist.begin();it!=asklist.end();++it)
    {
        Question que = Global::getQuestion(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(que.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(que.getTitle()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(que.getTime()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void UserdataWindow::showAnswers()
{
    User u = Global::getUser(this->userId);
    vector<int> answerlist = u.getAnswerList();
    int row=0;
    for(vector<int>::iterator it = answerlist.begin();it!=answerlist.end();++it)
    {
        Answer ans = Global::getAnswer(*it);
        ui->tableWidget_2->setRowCount(row+1);
        ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
        ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
        ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getQuestionId())));
        ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(ans.getTime()));

        for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void UserdataWindow::on_changePassButton_clicked()
{

    ChangeProfile *cp = new ChangeProfile;
    cp->exec();
}

void UserdataWindow::on_changeNameButton_clicked()
{
    ChangeName *cn = new ChangeName;
    cn->exec();
}


void UserdataWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    QuesAnsWindow *quesansWindow = new QuesAnsWindow;
    quesansWindow->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    quesansWindow->setPalette(palette);
    quesansWindow->show();
    quesansWindow->showQuesAnswers(id);
    this->hide();
}

void UserdataWindow::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget_2->item(index.row(),0)->text().toInt(ok,10);
    int quesId = ui->tableWidget_2->item(index.row(),3)->text().toInt(ok,10);
    QuesAnsWindow *quesansWindow = new QuesAnsWindow;
    quesansWindow->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    quesansWindow->setPalette(palette);
    quesansWindow->show();
    quesansWindow->showQuesAnswers(quesId);
    quesansWindow->showAnswer(id);
    this->hide();
}

int UserdataWindow::getUserId()
{
    return this->userId;
}
void UserdataWindow::setUserId(int id)
{
    this->userId=id;
}

void UserdataWindow::on_messageButton_clicked()
{
    MessageDialog *msgDlg = new MessageDialog;
    msgDlg->setReceiverId(this->getUserId());
    msgDlg->exec();
}
=======
#include "userdatawindow.h"
#include "ui_userdatawindow.h"
#include "global.h"
#include "signin.h"
#include "changeprofile.h"
#include "changename.h"
#include "quesanswindow.h"
#include "messagedialog.h"

#include <QMessageBox>

UserdataWindow::UserdataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserdataWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg7.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->resize(833,547);
    this->setFixedSize(833,547);


    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("回答数")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(5);
    ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget_2->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header2;
    header2<<tr("ID")<<tr("答案")<<tr("问题")<<tr("问题ID")<<tr("时间");
    ui->tableWidget_2->setHorizontalHeaderLabels(header2);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget_2->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");


}

UserdataWindow::~UserdataWindow()
{
    delete ui;
}
void UserdataWindow::showAllDatas()
{
    this->showUserDatas();
    this->showAnswers();
    this->showQuestions();
}

void UserdataWindow::showUserDatas()
{
    User u = Global::getUser(this->userId);
    if(u.getId()!=USER.getId())
    {
        ui->changePassButton->setVisible(false);
        ui->changeNameButton->setVisible(false);
    }
    else
        ui->messageButton->setVisible(false);


    ui->label_id->setText(QString::number(u.getId()));
    ui->label_name->setText(u.getName());
    ui->label_ans->setText(QString::number(u.getAnswerList().size()));
    ui->label_ask->setText(QString::number(u.getAskList().size()));
    ui->label_focus->setText(QString::number(u.getFocusList().size()));
    ui->label_follow->setText(QString::number(u.getFollowedList().size()));
    ui->label_prs->setText(QString::number(u.getPraisedNum()));
}

void UserdataWindow::showQuestions()
{
    User u = Global::getUser(this->userId);
    vector<int> asklist = u.getAskList();
    int row=0;
    for(vector<int>::iterator it = asklist.begin();it!=asklist.end();++it)
    {
        Question que = Global::getQuestion(*it);
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(que.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(que.getTitle()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(que.getAnswerList().size())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(que.getTime()));
        for(int col = 0;col<ui->tableWidget->columnCount();col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void UserdataWindow::showAnswers()
{
    User u = Global::getUser(this->userId);
    vector<int> answerlist = u.getAnswerList();
    int row=0;
    for(vector<int>::iterator it = answerlist.begin();it!=answerlist.end();++it)
    {
        Answer ans = Global::getAnswer(*it);
        ui->tableWidget_2->setRowCount(row+1);
        ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(ans.getContent()));
        ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(Global::getQuestion(ans.getQuestionId()).getTitle()));
        ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(QString::number(ans.getQuestionId())));
        ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(ans.getTime()));

        for(int col = 0;col<ui->tableWidget_2->columnCount();col++)
                ui->tableWidget_2->item(row,col)->setTextColor(QColor(220,220,220));
        row++;
    }
}

void UserdataWindow::on_changePassButton_clicked()
{

    ChangeProfile *cp = new ChangeProfile;
    cp->exec();
}

void UserdataWindow::on_changeNameButton_clicked()
{
    ChangeName *cn = new ChangeName;
    cn->exec();
}


void UserdataWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    QuesAnsWindow *quesansWindow = new QuesAnsWindow;
    quesansWindow->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    quesansWindow->setPalette(palette);
    quesansWindow->show();
    quesansWindow->showQuesAnswers(id);
    this->hide();
}

void UserdataWindow::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget_2->item(index.row(),0)->text().toInt(ok,10);
    int quesId = ui->tableWidget_2->item(index.row(),3)->text().toInt(ok,10);
    QuesAnsWindow *quesansWindow = new QuesAnsWindow;
    quesansWindow->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    quesansWindow->setPalette(palette);
    quesansWindow->show();
    quesansWindow->showQuesAnswers(quesId);
    quesansWindow->showAnswer(id);
    this->hide();
}

int UserdataWindow::getUserId()
{
    return this->userId;
}
void UserdataWindow::setUserId(int id)
{
    this->userId=id;
}

void UserdataWindow::on_messageButton_clicked()
{
    MessageDialog *msgDlg = new MessageDialog;
    msgDlg->setReceiverId(this->getUserId());
    msgDlg->exec();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
