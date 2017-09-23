<<<<<<< HEAD
#include "noticewindow.h"
#include "ui_noticewindow.h"
#include "global.h"
#include "quesanswindow.h"
#include "replydialog.h"
#include "userdatawindow.h"
#include "commentdialog.h"
NoticeWindow::NoticeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticeWindow)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/bg7.jpg");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
    ui->noticeButton->setChecked(true);
    this->showNotice();
}

NoticeWindow::~NoticeWindow()
{
    delete ui;
}

void NoticeWindow::on_noticeButton_toggled(bool checked)
{
    if(checked)
    {
        this->showNotice();
    }

}
void  NoticeWindow::showNotice()
{
    ui->focusButton->setChecked(false);
    ui->praiseButton->setChecked(false);
    ui->messageButton->setChecked(false);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("标题")<<tr("时间")<<tr("问题ID");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setColumnWidth(1,400);
    int row=0;
    for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
        Notification notif = *it;

        if(notif.getUserId()==USER.getId() && notif.getType()==Type::Notice)
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
            row++;
        }
    }
}

void NoticeWindow::on_praiseButton_toggled(bool checked)
{
    if(checked)
    {
        ui->focusButton->setChecked(false);
        ui->noticeButton->setChecked(false);
        ui->messageButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("回答")<<tr("时间");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Praise)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getContent()));
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(notif.getTime()));

                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }

}

void NoticeWindow::on_focusButton_toggled(bool checked)
{
    if(checked)
    {
        ui->noticeButton->setChecked(false);
        ui->praiseButton->setChecked(false);
        ui->messageButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("时间")<<tr("对方ID");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Focused)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getSenderId())));
                //ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }

}

void NoticeWindow::on_messageButton_toggled(bool checked)
{
    if(checked)
    {
        ui->focusButton->setChecked(false);
        ui->praiseButton->setChecked(false);
        ui->noticeButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("时间");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);

        /*因为迭代器类型搞错了
         * error: conversion from 'std::vector<Notification>::iterator {aka __gnu_cxx::__normal_iterator<Notification*,
         * std::vector<Notification> >}' to non-scalar type 'std::vector<int, std::allocator<int> >::iterator
         * {aka __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >}' requested
        */
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Message)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
               // ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }
}



void NoticeWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(ui->noticeButton->isChecked())
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        int quesId =ui->tableWidget->item(index.row(),3)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        if(notif.getAnswerId()==0)
        {
            QuesAnsWindow *qaw = new QuesAnsWindow;
            qaw->show();
            qaw->showQuesAnswers(quesId);
        }
        else
        {
            CommentDialog *cmtDlg = new CommentDialog;
            this->hide();
            cmtDlg->setAnswerId(notif.getAnswerId());
            cmtDlg->setAnswererId(quesId);
            cmtDlg->showComments();
            cmtDlg->exec();
        }

    }
    else if(ui->praiseButton->isChecked())
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        int quesId = notif.getQuestionId();
        int ansId = notif.getAnswerId();
        QuesAnsWindow *qaw = new QuesAnsWindow;
        qaw->show();
        qaw->showQuesAnswers(quesId);
        qaw->showAnswer(ansId);

    }
    else if(ui->focusButton->isChecked())
    {
        bool* ok = NULL;
        int senderId =ui->tableWidget->item(index.row(),3)->text().toInt(ok,10);
        UserdataWindow *uw = new UserdataWindow;
        uw->setUserId(senderId);
        uw->show();
        uw->showAllDatas();
        this->hide();
    }
    else
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        ReplyDialog *rplDlg = new ReplyDialog;
        rplDlg->setNotif(notif);
        rplDlg->showMessage();
        rplDlg->exec();
    }
}
=======
#include "noticewindow.h"
#include "ui_noticewindow.h"
#include "global.h"
#include "quesanswindow.h"
#include "replydialog.h"
#include "userdatawindow.h"
#include "commentdialog.h"
NoticeWindow::NoticeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticeWindow)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/bg7.jpg");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
    ui->noticeButton->setChecked(true);
    this->showNotice();
}

NoticeWindow::~NoticeWindow()
{
    delete ui;
}

void NoticeWindow::on_noticeButton_toggled(bool checked)
{
    if(checked)
    {
        this->showNotice();
    }

}
void  NoticeWindow::showNotice()
{
    ui->focusButton->setChecked(false);
    ui->praiseButton->setChecked(false);
    ui->messageButton->setChecked(false);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("标题")<<tr("时间")<<tr("问题ID");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setColumnWidth(1,400);
    int row=0;
    for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
        Notification notif = *it;

        if(notif.getUserId()==USER.getId() && notif.getType()==Type::Notice)
        {
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
            for(int col = 0;col<ui->tableWidget->columnCount();col++)
                ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
            //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
            row++;
        }
    }
}

void NoticeWindow::on_praiseButton_toggled(bool checked)
{
    if(checked)
    {
        ui->focusButton->setChecked(false);
        ui->noticeButton->setChecked(false);
        ui->messageButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("回答")<<tr("时间");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Praise)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getContent()));
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(notif.getTime()));

                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }

}

void NoticeWindow::on_focusButton_toggled(bool checked)
{
    if(checked)
    {
        ui->noticeButton->setChecked(false);
        ui->praiseButton->setChecked(false);
        ui->messageButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("时间")<<tr("对方ID");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Focused)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getSenderId())));
                //ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }

}

void NoticeWindow::on_messageButton_toggled(bool checked)
{
    if(checked)
    {
        ui->focusButton->setChecked(false);
        ui->praiseButton->setChecked(false);
        ui->noticeButton->setChecked(false);

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
        ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header;
        header<<tr("ID")<<tr("标题")<<tr("时间");
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->tableWidget->setColumnWidth(1,400);

        /*因为迭代器类型搞错了
         * error: conversion from 'std::vector<Notification>::iterator {aka __gnu_cxx::__normal_iterator<Notification*,
         * std::vector<Notification> >}' to non-scalar type 'std::vector<int, std::allocator<int> >::iterator
         * {aka __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >}' requested
        */
        int row=0;
        for (vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
        {
            Notification notif = *it;

            if(notif.getUserId()==USER.getId() && notif.getType()==Type::Message)
            {
                ui->tableWidget->setRowCount(row+1);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(notif.getId())));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(notif.getTitle()));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(notif.getTime()));
               // ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(notif.getQuestionId())));
                for(int col = 0;col<ui->tableWidget->columnCount();col++)
                    ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
                //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
                row++;
            }
        }
    }
}



void NoticeWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(ui->noticeButton->isChecked())
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        int quesId =ui->tableWidget->item(index.row(),3)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        if(notif.getAnswerId()==0)
        {
            QuesAnsWindow *qaw = new QuesAnsWindow;
            qaw->show();
            qaw->showQuesAnswers(quesId);
        }
        else
        {
            CommentDialog *cmtDlg = new CommentDialog;
            this->hide();
            cmtDlg->setAnswerId(notif.getAnswerId());
            cmtDlg->setAnswererId(quesId);
            cmtDlg->showComments();
            cmtDlg->exec();
        }

    }
    else if(ui->praiseButton->isChecked())
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        int quesId = notif.getQuestionId();
        int ansId = notif.getAnswerId();
        QuesAnsWindow *qaw = new QuesAnsWindow;
        qaw->show();
        qaw->showQuesAnswers(quesId);
        qaw->showAnswer(ansId);

    }
    else if(ui->focusButton->isChecked())
    {
        bool* ok = NULL;
        int senderId =ui->tableWidget->item(index.row(),3)->text().toInt(ok,10);
        UserdataWindow *uw = new UserdataWindow;
        uw->setUserId(senderId);
        uw->show();
        uw->showAllDatas();
        this->hide();
    }
    else
    {
        bool* ok = NULL;
        int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);
        Notification notif = Global::getNotification(id);
        ReplyDialog *rplDlg = new ReplyDialog;
        rplDlg->setNotif(notif);
        rplDlg->showMessage();
        rplDlg->exec();
    }
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
