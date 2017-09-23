<<<<<<< HEAD
#include "quesanswindow.h"
#include "ui_quesanswindow.h"
#include "answer.h"
#include "global.h"
#include "invitedialog.h"
#include "userdatawindow.h"
#include "commentdialog.h"
#include <iostream>
#include <QMessageBox>
QuesAnsWindow::QuesAnsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuesAnsWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    this->resize(800,764);
    this->setFixedSize(800,764);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("被赞数")<<tr("答主")<<tr("答案ID")<<tr("答主ID")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->show();
    ui->textBrowser->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->textBrowser_2->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->textEdit->setStyleSheet("background-color:rgba(0,0,0,50)");

    ui->praiseButton->setVisible(false);
    ui->focusDZButton->setVisible(false);
    ui->commentButton->setVisible(false);
    ui->aboutDZButton->setVisible(false);
    ui->textBrowser->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textBrowser->setTextColor(QColor("white"));
    ui->textBrowser_2->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textBrowser_2->setTextColor(QColor("white"));
    ui->textEdit->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textEdit->setTextColor(QColor("white"));
}

QuesAnsWindow::~QuesAnsWindow()
{
    delete ui;
}
void QuesAnsWindow::setAsker(User user)
{
    this->asker = user;
}

void QuesAnsWindow::setQuestion(Question question)
{
    this->question = question;
}

User QuesAnsWindow::getAsker()
{
    return this->asker;
}

Question QuesAnsWindow::getQuestion()
{
    return this->question;
}
void QuesAnsWindow::setAnswers(vector<Answer> answers)
{
    this->answers = answers;
}

vector<Answer> QuesAnsWindow::getAnswers()
{
    return this->answers;
}
void QuesAnsWindow::setAnswerer(User user)
{
    this->answerer = user;
}

void QuesAnsWindow::setCurAnswer(Answer ans)
{
    this->curAnswer = ans;
}

User QuesAnsWindow::getAnswerer()
{
    return this->answerer;
}

Answer QuesAnsWindow::getCurAnswer()
{
    return this->curAnswer;
}

void QuesAnsWindow::showQuesAnswers(int id)
{
    Question ques = Global::getQuestion(id);//问题
    this->setQuestion(ques);

    ui->label_title->setText(ques.getTitle());
    ui->textBrowser_2->setText(ques.getContent());
    ui->label_time->setText(ques.getTime());

    User user = Global::getUser(ques.getUserId());//题主
    this->setAsker(user);
    ui->label_tizhu->setText(user.getName());
    vector<int>ansIds = ques.getAnswerList();
    vector<Answer>answers;
    //所有回答
    for(vector<int>::iterator it = ansIds.begin();it!=ansIds.end();++it)
    {
           Answer ans=Global::getAnswer((*it));
           answers.push_back(ans);

    }
    this->setAnswers(answers);//所有回答
    int flag=0;
    int row = 0;
    for(vector<Answer>::reverse_iterator rit = answers.rbegin();rit!=answers.rend();++rit)
    {
        Answer ans = *rit;
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ans.getUserId())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ans.getTime()));

        qDebug()<<QString::number(ans.getId())<<" "<<ans.getContent()<<" "<<ans.getTime()<<" "<<row;
        row++;
        flag=1;
    }
    for(int row = 0;row < answers.size();row++)
    {
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
    }
    if(flag==0)
         ui->tableWidget->setRowCount(0);
    ui->tableWidget->show();
    //检查是否关注题主
    bool flag1 = true;
    User tmpU = this->getAsker();
    if (tmpU.getId()!=USER.getId())
    {
        ui->focusTZButton->setCheckable(true);
        vector<int> focusls = USER.getFocusList();
        for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
        {
            User u = Global::getUser(*it);
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag1=false;//已经关注了
                ui->focusTZButton->setChecked(true);

                ui->focusTZButton->setText("取消关注");
                qDebug()<<"取消关注";
                break;

            }
        }
        if(flag1)
       {
            ui->focusTZButton->setChecked(false);
            ui->focusTZButton->setText("关注题主");
        }
    }
    else
    {
        ui->focusTZButton->setVisible(false);
        ui->aboutTZButton->setVisible(false);
    }
}
void QuesAnsWindow::freshTable()
{

    vector<Answer>answers = this->getAnswers();
    qDebug()<<"freshTable"<<this->getAnswers().size();
    int flag=0;
    int row = 0;
    for(vector<Answer>::reverse_iterator rit = answers.rbegin();rit!=answers.rend();++rit)
    {
        Answer ans = *rit;

        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ans.getUserId())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ans.getTime()));


        qDebug()<<QString::number(ans.getId())<<" "<<ans.getContent()<<" "<<ans.getTime()<<" "<<row;
        row++;
        flag=1;
    }
    for(int row = 0;row < answers.size();row++)
    {
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
    }
    if(flag==0)
         ui->tableWidget->setRowCount(0);
    ui->tableWidget->show();

}

void QuesAnsWindow::on_answerQuesButton_clicked()
{
    qDebug()<<"6begin";
    QString currentContent = ui->textEdit->document()->toPlainText();
    if(currentContent!="")
    {
        Answer answer;
        int id=Answers.size()+1;

        //answer.setContent(currentContent);
        int userId=USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        //answer.setTime(timestr);
        answer.created(id,userId,currentContent,timestr);
        answer.setPraisedNum(0);
        answer.setQuestionId(this->getQuestion().getId());
        qDebug()<<"5";

        vector<int> answerlist = this->getQuestion().getAnswerList();
        answerlist.push_back(answer.getId());

        qDebug()<<"4";

        //this->setQuestion(this->getQuestion().setAnswerList(answerlist));//大坑啊，这个一定要总结错误
        Question tmpQ = this->getQuestion();
        tmpQ.setAnswerList(answerlist);
        this->setQuestion(tmpQ);
        qDebug()<<"3";

        vector<Answer> answers = this->getAnswers();
        answers.push_back(answer);
        qDebug()<<"answer"<<this->getAnswers().size();
        this->setAnswers(answers);
        qDebug()<<"answer"<<this->getAnswers().size();

        USER.handleAnswerList(answer.getId(),1);
        qDebug()<<"2";
        try
        {
            std::cout<<answer;
        }
        catch(...)
        {
            qDebug()<<"cout<<answer error";
            Global::insert(answer);
        }
        Global::update(this->getQuestion());
        Global::update(USER);
        this->freshTable();
        ui->textEdit->clear();
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入搜索内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    qDebug()<<"1end";

}
void QuesAnsWindow::showAnswer(int id)
{
    Answer ans;
    ans = Global::getAnswer(id);

    User ansuser = Global::getUser(ans.getUserId());
    this->setAnswerer(ansuser);
    this->setCurAnswer(ans);
    qDebug()<<"on_tableWidget_clicked"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
    ui->label_dazhu->setText(ansuser.getName());
    ui->label_time->setText(ans.getTime());
    ui->label_prsnum->setText(QString::number(ans.getPraisedNum()));
    ui->textBrowser->setText(ans.getContent());

    if(ansuser.getId()==USER.getId())
    {
       ui->praiseButton->setVisible(false);
       ui->focusDZButton->setVisible(false);
       ui->aboutDZButton->setVisible(false);
       ui->commentButton->setVisible(false);

    }
    else
    {
       ui->praiseButton->setVisible(true);
       ui->focusDZButton->setVisible(true);
       ui->aboutDZButton->setVisible(true);
        ui->commentButton->setVisible(true);
       ui->praiseButton->setCheckable(true);
       ui->focusDZButton->setCheckable(true);

    }
    bool flag1 = true;
    vector<int> praisels = USER.getPraiseList();
    for(vector<int>::iterator it = praisels.begin();it != praisels.end();++it)
    {
        if(*it > Answers.size()||*it<0)
            break;
        Answer tmpA = Global::getAnswer(*it);

        if(tmpA.getId()== this->getCurAnswer().getId())
        {
            flag1=false;//已经赞过了
            ui->praiseButton->setChecked(true);
            ui->praiseButton->setText("取消赞");
            break;
        }

    }
    if(flag1)
    {
        ui->praiseButton->setChecked(false);
        ui->praiseButton->setText("赞");
    }
    //检查是否已经关注答主
    User tmpU = this->getAnswerer();
    bool flag2 = true;
    vector<int> focusls = USER.getFocusList();
    for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
    {
        User u = Global::getUser(*it);
        if(u.getId()==-1)
            break;
        if(tmpU.getId()== *it)
        {
            flag2=false;//已经关注了
            ui->focusDZButton->setChecked(true);
            ui->focusDZButton->setText("取消关注");
            break;

        }
    }
    if(flag2)
    {
        ui->focusDZButton->setChecked(false);
        ui->focusDZButton->setText("关注答主");
    }
    //qDebug()<<"on_tableWidget_clicked";
}

void QuesAnsWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),2)->text().toInt(ok,10);
    qDebug()<<"on_tableWidget_clicked"<<id;
    showAnswer(id);


}


void QuesAnsWindow::on_freshButton_clicked()
{
    freshTable();
}

//关注某人创建通知
void focusNotice(User user)
{
    //创建通知
    Notification notif;
    int id = Notifications.size()+1;
    int userId =user.getId();
    int senderId = USER.getId();
    int questionId = 0;
    int answerId = 0;
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    QString title = QString("%1 关注了你").arg(USER.getName());
    QString content = "";
    notif.created(id,userId,content,timestr);
    notif.setQuestionId(questionId);
    notif.setAnswerId(answerId);
    notif.setSenderId(senderId);
    notif.setType(3);
    notif.setTitle(title);

    Global::insert(notif);
}


void QuesAnsWindow::on_praiseButton_clicked()
{
    qDebug()<<"begin";
    User tmpU = this->getAnswerer();
    qDebug()<<"on_praiseButton_clicked()"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
    if(tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> praisels = USER.getPraiseList();
        for(vector<int>::iterator it = praisels.begin();it != praisels.end();++it)
        {
            if(*it > Answers.size()|| *it<0)
                break;
            Answer tmpA = Global::getAnswer(*it);
            qDebug()<<"tmpA"<<tmpA.getId()<<" "<<tmpA.getContent();
            qDebug()<<"flag1"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
            if(tmpA.getId()== this->getCurAnswer().getId())
            {
                qDebug()<<"flag2";

                flag=false;//已经赞过了
                ui->praiseButton->setText("取消赞");
                qDebug()<<"flag3";
                break;

            }

            qDebug()<<flag;

        }
        if(flag)
        {
            qDebug()<<"flag5";
            int upn= tmpU.getPraisedNum();
            //this->setAnswerer(this->getAnswerer().setPraisedNum(upn+1));


            tmpU.setPraisedNum(upn+1);
            this->setAnswerer(tmpU);
             qDebug()<<"flag4";
            Global::update(this->getAnswerer());

            int apn=this->getCurAnswer().getPraisedNum();
            //this->setCurAnswer(this->getCurAnswer().setPraisedNum(apn+1));
            qDebug()<<"flag3";
            Answer tmpA = this->getCurAnswer();
            tmpA.setPraisedNum(apn+1);
            this->setCurAnswer(tmpA);
            qDebug()<<"flag2";
            Global::update(this->getCurAnswer());
            ui->label_prsnum->setText(QString::number(apn+1));
            ui->praiseButton->setChecked(true);
            ui->praiseButton->setText("取消赞");
            qDebug()<<"flag1";

            USER.handlePraiseList(this->getCurAnswer().getId(),1);
            Global::update(USER);
            qDebug()<<"flag=true";
            //创建通知
            Notification notif;

            int id = Notifications.size()+1;
            int userId =this->getAnswerer().getId();
            int senderId = USER.getId();
            int questionId = this->getQuestion().getId();
            int answerId = this->getCurAnswer().getId();
            QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
            QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
            QString title = QString("%1 赞了你的回答").arg(USER.getName());
            QString content = this->getCurAnswer().getContent();
            notif.created(id,userId,content,timestr);
            notif.setQuestionId(questionId);
            notif.setAnswerId(answerId);
            notif.setSenderId(senderId);
            notif.setType(2);
            notif.setTitle(title);

            Global::insert(notif);
        }
        else
        {   qDebug()<<"f4";
            int upn=tmpU.getPraisedNum();
            //this->setAnswerer(this->getAnswerer().setPraisedNum(upn+1));


            tmpU.setPraisedNum(upn-1);
            this->setAnswerer(tmpU);
            qDebug()<<"f3";
            Global::update(this->getAnswerer());
            int apn=(this->getCurAnswer()).getPraisedNum();
            //this->setCurAnswer(this->getCurAnswer().setPraisedNum(apn+1));
            qDebug()<<"f2";
            Answer tmpA = this->getCurAnswer();
            tmpA.setPraisedNum(apn-1);
            this->setCurAnswer(tmpA);
            qDebug()<<"f1";
            Global::update(this->getCurAnswer());
            ui->label_prsnum->setText(QString::number(apn-1));
            qDebug()<<"f0";
            ui->praiseButton->setChecked(false);
            ui->praiseButton->setText("赞");
            USER.handlePraiseList(this->getCurAnswer().getId(),0);qDebug()<<this->getCurAnswer().getId()<<" "<<this->getCurAnswer().getPraisedNum();
            Global::update(USER);qDebug()<<USER.getPraisedNum();
            qDebug()<<"flag=false";
        }
    }
}

void QuesAnsWindow::on_focusTZButton_clicked()
{
    User tmpU = this->getAsker();
    if(tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> focusls=USER.getFocusList();//这又是一个大大的坑！！！！这是为什么呢？？？？
        for(vector<int>::iterator it= focusls.begin(); it != focusls.end(); ++it)
        {
            User u = Global::getUser(*it);
             qDebug()<<"onfocusTZbt"<<u.getId()<<u.getName()<<" "<<tmpU.getId()<<" "<<*it;
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag=false;//已经关注了

                break;
            }
        }
        if(flag)
        {

            tmpU.handleFollowedList(USER.getId(),1);
            this->setAsker(tmpU);

            USER.handleFocusList(this->getAsker().getId(),1);
            Global::update(this->getAsker());
            Global::update(USER);
            focusNotice(this->getAsker());
            ui->focusTZButton->setChecked(true);
            ui->focusTZButton->setText("取消关注");
            qDebug()<<"取消关注"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
        else
        {

            tmpU.handleFollowedList(USER.getId(),0);
            qDebug()<<"flag=false"<<this->getAsker().getId()<<" "<<tmpU.getId();
            this->setAsker(tmpU);
            qDebug()<<"flag=false"<<this->getAsker().getId();
            //this->getAsker().handleFollowedList(USER.getId(),0);
            USER.handleFocusList(this->getAsker().getId(),0);
            qDebug()<<"USER.handleFocusList"<<this->getAsker().getId();
            Global::update(this->getAsker());
            Global::update(USER);
            ui->focusTZButton->setChecked(false);
            ui->focusTZButton->setText("关注题主");
            qDebug()<<"关注题主"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
    }
}

void QuesAnsWindow::on_focusDZButton_clicked()
{
    User tmpU = this->getAnswerer();
    if( tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> focusls = USER.getFocusList();
        for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
        {
            User u = Global::getUser(*it);
            qDebug()<<"onfocusDZbt"<<u.getId()<<u.getName()<<" "<<tmpU.getId()<<" "<<*it;;
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag=false;//已经关注了

                break;
            }
        }
        if(flag)
        {

            tmpU.handleFollowedList(USER.getId(),1);
            this->setAnswerer(tmpU);
            //this->getAnswerer().handleFollowedList(USER.getId(),1);

            USER.handleFocusList(this->getAnswerer().getId(),1);
            Global::update(this->getAnswerer());
            Global::update(USER);
            focusNotice(this->getAnswerer());
            ui->focusDZButton->setChecked(true);
            ui->focusDZButton->setText("取消关注");
            qDebug()<<"取消关注"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
        else
        {

            tmpU.handleFollowedList(USER.getId(),0);
            this->setAnswerer(tmpU);
            //this->getAnswerer().handleFollowedList(USER.getId(),0);
            USER.handleFocusList(this->getAnswerer().getId(),0);
            Global::update(this->getAnswerer());
            Global::update(USER);
            ui->focusDZButton->setChecked(false);
            ui->focusDZButton->setText("关注答主");
            qDebug()<<"关注答主"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
    }

}

void QuesAnsWindow::on_inviteButton_clicked()
{
    InviteDialog *ivtdlg = new InviteDialog;
    ivtdlg->setQuestionId(this->getQuestion().getId());
    ivtdlg->exec();
}


void QuesAnsWindow::on_aboutTZButton_clicked()
{
    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(this->getAsker().getId());
    uw->show();
    uw->showAllDatas();
    this->hide();
}

void QuesAnsWindow::on_aboutDZButton_clicked()
{
    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(this->getAnswerer().getId());
    uw->show();
    uw->showAllDatas();
    this->hide();
}

void QuesAnsWindow::on_commentButton_clicked()
{
    CommentDialog *cmtDlg = new CommentDialog; 
    cmtDlg->setAnswerId(this->getCurAnswer().getId());
    cmtDlg->setAnswererId(this->getAnswerer().getId());
    cmtDlg->showComments();
    cmtDlg->exec();

}
=======
#include "quesanswindow.h"
#include "ui_quesanswindow.h"
#include "answer.h"
#include "global.h"
#include "invitedialog.h"
#include "userdatawindow.h"
#include "commentdialog.h"
#include <iostream>
#include <QMessageBox>
QuesAnsWindow::QuesAnsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuesAnsWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg4.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    this->resize(800,764);
    this->setFixedSize(800,764);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("被赞数")<<tr("答主")<<tr("答案ID")<<tr("答主ID")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->show();
    ui->textBrowser->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->textBrowser_2->setStyleSheet("background-color:rgba(0,0,0,50)");
    ui->textEdit->setStyleSheet("background-color:rgba(0,0,0,50)");

    ui->praiseButton->setVisible(false);
    ui->focusDZButton->setVisible(false);
    ui->commentButton->setVisible(false);
    ui->aboutDZButton->setVisible(false);
    ui->textBrowser->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textBrowser->setTextColor(QColor("white"));
    ui->textBrowser_2->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textBrowser_2->setTextColor(QColor("white"));
    ui->textEdit->setFont(QFont("微软雅黑", 12, QFont::Light ));
    ui->textEdit->setTextColor(QColor("white"));
}

QuesAnsWindow::~QuesAnsWindow()
{
    delete ui;
}
void QuesAnsWindow::setAsker(User user)
{
    this->asker = user;
}

void QuesAnsWindow::setQuestion(Question question)
{
    this->question = question;
}

User QuesAnsWindow::getAsker()
{
    return this->asker;
}

Question QuesAnsWindow::getQuestion()
{
    return this->question;
}
void QuesAnsWindow::setAnswers(vector<Answer> answers)
{
    this->answers = answers;
}

vector<Answer> QuesAnsWindow::getAnswers()
{
    return this->answers;
}
void QuesAnsWindow::setAnswerer(User user)
{
    this->answerer = user;
}

void QuesAnsWindow::setCurAnswer(Answer ans)
{
    this->curAnswer = ans;
}

User QuesAnsWindow::getAnswerer()
{
    return this->answerer;
}

Answer QuesAnsWindow::getCurAnswer()
{
    return this->curAnswer;
}

void QuesAnsWindow::showQuesAnswers(int id)
{
    Question ques = Global::getQuestion(id);//问题
    this->setQuestion(ques);

    ui->label_title->setText(ques.getTitle());
    ui->textBrowser_2->setText(ques.getContent());
    ui->label_time->setText(ques.getTime());

    User user = Global::getUser(ques.getUserId());//题主
    this->setAsker(user);
    ui->label_tizhu->setText(user.getName());
    vector<int>ansIds = ques.getAnswerList();
    vector<Answer>answers;
    //所有回答
    for(vector<int>::iterator it = ansIds.begin();it!=ansIds.end();++it)
    {
           Answer ans=Global::getAnswer((*it));
           answers.push_back(ans);

    }
    this->setAnswers(answers);//所有回答
    int flag=0;
    int row = 0;
    for(vector<Answer>::reverse_iterator rit = answers.rbegin();rit!=answers.rend();++rit)
    {
        Answer ans = *rit;
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ans.getUserId())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ans.getTime()));

        qDebug()<<QString::number(ans.getId())<<" "<<ans.getContent()<<" "<<ans.getTime()<<" "<<row;
        row++;
        flag=1;
    }
    for(int row = 0;row < answers.size();row++)
    {
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
    }
    if(flag==0)
         ui->tableWidget->setRowCount(0);
    ui->tableWidget->show();
    //检查是否关注题主
    bool flag1 = true;
    User tmpU = this->getAsker();
    if (tmpU.getId()!=USER.getId())
    {
        ui->focusTZButton->setCheckable(true);
        vector<int> focusls = USER.getFocusList();
        for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
        {
            User u = Global::getUser(*it);
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag1=false;//已经关注了
                ui->focusTZButton->setChecked(true);

                ui->focusTZButton->setText("取消关注");
                qDebug()<<"取消关注";
                break;

            }
        }
        if(flag1)
       {
            ui->focusTZButton->setChecked(false);
            ui->focusTZButton->setText("关注题主");
        }
    }
    else
    {
        ui->focusTZButton->setVisible(false);
        ui->aboutTZButton->setVisible(false);
    }
}
void QuesAnsWindow::freshTable()
{

    vector<Answer>answers = this->getAnswers();
    qDebug()<<"freshTable"<<this->getAnswers().size();
    int flag=0;
    int row = 0;
    for(vector<Answer>::reverse_iterator rit = answers.rbegin();rit!=answers.rend();++rit)
    {
        Answer ans = *rit;

        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ans.getPraisedNum())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Global::getUser(ans.getUserId()).getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(ans.getId())));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ans.getUserId())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ans.getTime()));


        qDebug()<<QString::number(ans.getId())<<" "<<ans.getContent()<<" "<<ans.getTime()<<" "<<row;
        row++;
        flag=1;
    }
    for(int row = 0;row < answers.size();row++)
    {
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
    }
    if(flag==0)
         ui->tableWidget->setRowCount(0);
    ui->tableWidget->show();

}

void QuesAnsWindow::on_answerQuesButton_clicked()
{
    qDebug()<<"6begin";
    QString currentContent = ui->textEdit->document()->toPlainText();
    if(currentContent!="")
    {
        Answer answer;
        int id=Answers.size()+1;

        //answer.setContent(currentContent);
        int userId=USER.getId();
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
        //answer.setTime(timestr);
        answer.created(id,userId,currentContent,timestr);
        answer.setPraisedNum(0);
        answer.setQuestionId(this->getQuestion().getId());
        qDebug()<<"5";

        vector<int> answerlist = this->getQuestion().getAnswerList();
        answerlist.push_back(answer.getId());

        qDebug()<<"4";

        //this->setQuestion(this->getQuestion().setAnswerList(answerlist));//大坑啊，这个一定要总结错误
        Question tmpQ = this->getQuestion();
        tmpQ.setAnswerList(answerlist);
        this->setQuestion(tmpQ);
        qDebug()<<"3";

        vector<Answer> answers = this->getAnswers();
        answers.push_back(answer);
        qDebug()<<"answer"<<this->getAnswers().size();
        this->setAnswers(answers);
        qDebug()<<"answer"<<this->getAnswers().size();

        USER.handleAnswerList(answer.getId(),1);
        qDebug()<<"2";
        try
        {
            std::cout<<answer;
        }
        catch(...)
        {
            qDebug()<<"cout<<answer error";
            Global::insert(answer);
        }
        Global::update(this->getQuestion());
        Global::update(USER);
        this->freshTable();
        ui->textEdit->clear();
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入搜索内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }
    qDebug()<<"1end";

}
void QuesAnsWindow::showAnswer(int id)
{
    Answer ans;
    ans = Global::getAnswer(id);

    User ansuser = Global::getUser(ans.getUserId());
    this->setAnswerer(ansuser);
    this->setCurAnswer(ans);
    qDebug()<<"on_tableWidget_clicked"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
    ui->label_dazhu->setText(ansuser.getName());
    ui->label_time->setText(ans.getTime());
    ui->label_prsnum->setText(QString::number(ans.getPraisedNum()));
    ui->textBrowser->setText(ans.getContent());

    if(ansuser.getId()==USER.getId())
    {
       ui->praiseButton->setVisible(false);
       ui->focusDZButton->setVisible(false);
       ui->aboutDZButton->setVisible(false);
       ui->commentButton->setVisible(false);

    }
    else
    {
       ui->praiseButton->setVisible(true);
       ui->focusDZButton->setVisible(true);
       ui->aboutDZButton->setVisible(true);
        ui->commentButton->setVisible(true);
       ui->praiseButton->setCheckable(true);
       ui->focusDZButton->setCheckable(true);

    }
    bool flag1 = true;
    vector<int> praisels = USER.getPraiseList();
    for(vector<int>::iterator it = praisels.begin();it != praisels.end();++it)
    {
        if(*it > Answers.size()||*it<0)
            break;
        Answer tmpA = Global::getAnswer(*it);

        if(tmpA.getId()== this->getCurAnswer().getId())
        {
            flag1=false;//已经赞过了
            ui->praiseButton->setChecked(true);
            ui->praiseButton->setText("取消赞");
            break;
        }

    }
    if(flag1)
    {
        ui->praiseButton->setChecked(false);
        ui->praiseButton->setText("赞");
    }
    //检查是否已经关注答主
    User tmpU = this->getAnswerer();
    bool flag2 = true;
    vector<int> focusls = USER.getFocusList();
    for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
    {
        User u = Global::getUser(*it);
        if(u.getId()==-1)
            break;
        if(tmpU.getId()== *it)
        {
            flag2=false;//已经关注了
            ui->focusDZButton->setChecked(true);
            ui->focusDZButton->setText("取消关注");
            break;

        }
    }
    if(flag2)
    {
        ui->focusDZButton->setChecked(false);
        ui->focusDZButton->setText("关注答主");
    }
    //qDebug()<<"on_tableWidget_clicked";
}

void QuesAnsWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),2)->text().toInt(ok,10);
    qDebug()<<"on_tableWidget_clicked"<<id;
    showAnswer(id);


}


void QuesAnsWindow::on_freshButton_clicked()
{
    freshTable();
}

//关注某人创建通知
void focusNotice(User user)
{
    //创建通知
    Notification notif;
    int id = Notifications.size()+1;
    int userId =user.getId();
    int senderId = USER.getId();
    int questionId = 0;
    int answerId = 0;
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    QString title = QString("%1 关注了你").arg(USER.getName());
    QString content = "";
    notif.created(id,userId,content,timestr);
    notif.setQuestionId(questionId);
    notif.setAnswerId(answerId);
    notif.setSenderId(senderId);
    notif.setType(3);
    notif.setTitle(title);

    Global::insert(notif);
}


void QuesAnsWindow::on_praiseButton_clicked()
{
    qDebug()<<"begin";
    User tmpU = this->getAnswerer();
    qDebug()<<"on_praiseButton_clicked()"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
    if(tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> praisels = USER.getPraiseList();
        for(vector<int>::iterator it = praisels.begin();it != praisels.end();++it)
        {
            if(*it > Answers.size()|| *it<0)
                break;
            Answer tmpA = Global::getAnswer(*it);
            qDebug()<<"tmpA"<<tmpA.getId()<<" "<<tmpA.getContent();
            qDebug()<<"flag1"<<this->getCurAnswer().getId()<<this->getCurAnswer().getContent();
            if(tmpA.getId()== this->getCurAnswer().getId())
            {
                qDebug()<<"flag2";

                flag=false;//已经赞过了
                ui->praiseButton->setText("取消赞");
                qDebug()<<"flag3";
                break;

            }

            qDebug()<<flag;

        }
        if(flag)
        {
            qDebug()<<"flag5";
            int upn= tmpU.getPraisedNum();
            //this->setAnswerer(this->getAnswerer().setPraisedNum(upn+1));


            tmpU.setPraisedNum(upn+1);
            this->setAnswerer(tmpU);
             qDebug()<<"flag4";
            Global::update(this->getAnswerer());

            int apn=this->getCurAnswer().getPraisedNum();
            //this->setCurAnswer(this->getCurAnswer().setPraisedNum(apn+1));
            qDebug()<<"flag3";
            Answer tmpA = this->getCurAnswer();
            tmpA.setPraisedNum(apn+1);
            this->setCurAnswer(tmpA);
            qDebug()<<"flag2";
            Global::update(this->getCurAnswer());
            ui->label_prsnum->setText(QString::number(apn+1));
            ui->praiseButton->setChecked(true);
            ui->praiseButton->setText("取消赞");
            qDebug()<<"flag1";

            USER.handlePraiseList(this->getCurAnswer().getId(),1);
            Global::update(USER);
            qDebug()<<"flag=true";
            //创建通知
            Notification notif;

            int id = Notifications.size()+1;
            int userId =this->getAnswerer().getId();
            int senderId = USER.getId();
            int questionId = this->getQuestion().getId();
            int answerId = this->getCurAnswer().getId();
            QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
            QString timestr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
            QString title = QString("%1 赞了你的回答").arg(USER.getName());
            QString content = this->getCurAnswer().getContent();
            notif.created(id,userId,content,timestr);
            notif.setQuestionId(questionId);
            notif.setAnswerId(answerId);
            notif.setSenderId(senderId);
            notif.setType(2);
            notif.setTitle(title);

            Global::insert(notif);
        }
        else
        {   qDebug()<<"f4";
            int upn=tmpU.getPraisedNum();
            //this->setAnswerer(this->getAnswerer().setPraisedNum(upn+1));


            tmpU.setPraisedNum(upn-1);
            this->setAnswerer(tmpU);
            qDebug()<<"f3";
            Global::update(this->getAnswerer());
            int apn=(this->getCurAnswer()).getPraisedNum();
            //this->setCurAnswer(this->getCurAnswer().setPraisedNum(apn+1));
            qDebug()<<"f2";
            Answer tmpA = this->getCurAnswer();
            tmpA.setPraisedNum(apn-1);
            this->setCurAnswer(tmpA);
            qDebug()<<"f1";
            Global::update(this->getCurAnswer());
            ui->label_prsnum->setText(QString::number(apn-1));
            qDebug()<<"f0";
            ui->praiseButton->setChecked(false);
            ui->praiseButton->setText("赞");
            USER.handlePraiseList(this->getCurAnswer().getId(),0);qDebug()<<this->getCurAnswer().getId()<<" "<<this->getCurAnswer().getPraisedNum();
            Global::update(USER);qDebug()<<USER.getPraisedNum();
            qDebug()<<"flag=false";
        }
    }
}

void QuesAnsWindow::on_focusTZButton_clicked()
{
    User tmpU = this->getAsker();
    if(tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> focusls=USER.getFocusList();//这又是一个大大的坑！！！！这是为什么呢？？？？
        for(vector<int>::iterator it= focusls.begin(); it != focusls.end(); ++it)
        {
            User u = Global::getUser(*it);
             qDebug()<<"onfocusTZbt"<<u.getId()<<u.getName()<<" "<<tmpU.getId()<<" "<<*it;
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag=false;//已经关注了

                break;
            }
        }
        if(flag)
        {

            tmpU.handleFollowedList(USER.getId(),1);
            this->setAsker(tmpU);

            USER.handleFocusList(this->getAsker().getId(),1);
            Global::update(this->getAsker());
            Global::update(USER);
            focusNotice(this->getAsker());
            ui->focusTZButton->setChecked(true);
            ui->focusTZButton->setText("取消关注");
            qDebug()<<"取消关注"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
        else
        {

            tmpU.handleFollowedList(USER.getId(),0);
            qDebug()<<"flag=false"<<this->getAsker().getId()<<" "<<tmpU.getId();
            this->setAsker(tmpU);
            qDebug()<<"flag=false"<<this->getAsker().getId();
            //this->getAsker().handleFollowedList(USER.getId(),0);
            USER.handleFocusList(this->getAsker().getId(),0);
            qDebug()<<"USER.handleFocusList"<<this->getAsker().getId();
            Global::update(this->getAsker());
            Global::update(USER);
            ui->focusTZButton->setChecked(false);
            ui->focusTZButton->setText("关注题主");
            qDebug()<<"关注题主"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
    }
}

void QuesAnsWindow::on_focusDZButton_clicked()
{
    User tmpU = this->getAnswerer();
    if( tmpU.getId()!=USER.getId())
    {
        bool flag = true;
        vector<int> focusls = USER.getFocusList();
        for(vector<int>::iterator it = focusls.begin();it != focusls.end();++it)
        {
            User u = Global::getUser(*it);
            qDebug()<<"onfocusDZbt"<<u.getId()<<u.getName()<<" "<<tmpU.getId()<<" "<<*it;;
            if(u.getId()==-1)
                break;
            if(tmpU.getId()== *it)
            {
                flag=false;//已经关注了

                break;
            }
        }
        if(flag)
        {

            tmpU.handleFollowedList(USER.getId(),1);
            this->setAnswerer(tmpU);
            //this->getAnswerer().handleFollowedList(USER.getId(),1);

            USER.handleFocusList(this->getAnswerer().getId(),1);
            Global::update(this->getAnswerer());
            Global::update(USER);
            focusNotice(this->getAnswerer());
            ui->focusDZButton->setChecked(true);
            ui->focusDZButton->setText("取消关注");
            qDebug()<<"取消关注"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
        else
        {

            tmpU.handleFollowedList(USER.getId(),0);
            this->setAnswerer(tmpU);
            //this->getAnswerer().handleFollowedList(USER.getId(),0);
            USER.handleFocusList(this->getAnswerer().getId(),0);
            Global::update(this->getAnswerer());
            Global::update(USER);
            ui->focusDZButton->setChecked(false);
            ui->focusDZButton->setText("关注答主");
            qDebug()<<"关注答主"<<USER.getFocusList().size()<<USER.getFollowedList().size();
        }
    }

}

void QuesAnsWindow::on_inviteButton_clicked()
{
    InviteDialog *ivtdlg = new InviteDialog;
    ivtdlg->setQuestionId(this->getQuestion().getId());
    ivtdlg->exec();
}


void QuesAnsWindow::on_aboutTZButton_clicked()
{
    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(this->getAsker().getId());
    uw->show();
    uw->showAllDatas();
    this->hide();
}

void QuesAnsWindow::on_aboutDZButton_clicked()
{
    UserdataWindow *uw = new UserdataWindow;
    uw->setUserId(this->getAnswerer().getId());
    uw->show();
    uw->showAllDatas();
    this->hide();
}

void QuesAnsWindow::on_commentButton_clicked()
{
    CommentDialog *cmtDlg = new CommentDialog; 
    cmtDlg->setAnswerId(this->getCurAnswer().getId());
    cmtDlg->setAnswererId(this->getAnswerer().getId());
    cmtDlg->showComments();
    cmtDlg->exec();

}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
