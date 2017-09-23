<<<<<<< HEAD
#include "question.h"
class MainWindow;
Question::Question()
{

}


void Question::created(int id,int userId,QString content,QString createtime)
{
    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}

int Question::getId()
{
    return this->id;
}

int Question::getUserId()
{
    return this->userId;
}

QString Question::getContent()
{
    return this->content;
}

QString Question::getTime()
{
    return this->createtime;
}
vector<int> Question::getAnswerList()
{
    return this->answerlist;
}
void Question::setAnswerList(vector<int> answerlist)
{
    this->answerlist = answerlist;
}

QString Question::getTitle()
{
    return this->title;
}
void Question::setTitle(QString title)
{
    this->title = title;
}

void Question::setId(int id)
{
    this->id = id;
}

void Question::setUserId(int id)
{
    this->userId = id;
}

void Question::setContent(QString content)
{
    this->content = content;
}

void Question::setTime(QString createtime)
{
    this->createtime = createtime;
}
ostream  &operator<<(ostream &os,const Question &ques)
{
    //这一步很重要
    QByteArray ba1 = ques.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ques.createtime.toLatin1();
    char *timestr = ba2.data();
    QByteArray ba3 = ques.title.toLatin1();
    char *titlestr = ba3.data();
    //os<<ans.getId()<<","<<ans.getUserId()<<","<<ans.getQuestionId()<<","<<ans.getPraisedNum()<<","<<ans.getContent()<<","<<ans.getTime();
    os<<ques.id<<ques.userId<<titlestr<<contentstr<<timestr;
    return os;
}

istream  &operator>>(istream &is,Question &ques)
{
    QByteArray ba1 = ques.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ques.createtime.toLatin1();
    char *timestr = ba2.data();
    QByteArray ba3 = ques.title.toLatin1();
    char *titlestr = ba3.data();
    //is>>ans.getId()>>",">>ans.getUserId()>>",">>ans.getQuestionId()>>",">>ans.getPraisedNum()>>",">>ans.getContent()>>","<<ans.getTime();
    is>>ques.id>>ques.userId>>titlestr>>contentstr>>timestr;
    //输入判断
    if(!is)
        ques = Question(); //如果失败，默认初始化
    return is;
}
=======
#include "question.h"
class MainWindow;
Question::Question()
{

}


void Question::created(int id,int userId,QString content,QString createtime)
{
    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}

int Question::getId()
{
    return this->id;
}

int Question::getUserId()
{
    return this->userId;
}

QString Question::getContent()
{
    return this->content;
}

QString Question::getTime()
{
    return this->createtime;
}
vector<int> Question::getAnswerList()
{
    return this->answerlist;
}
void Question::setAnswerList(vector<int> answerlist)
{
    this->answerlist = answerlist;
}

QString Question::getTitle()
{
    return this->title;
}
void Question::setTitle(QString title)
{
    this->title = title;
}

void Question::setId(int id)
{
    this->id = id;
}

void Question::setUserId(int id)
{
    this->userId = id;
}

void Question::setContent(QString content)
{
    this->content = content;
}

void Question::setTime(QString createtime)
{
    this->createtime = createtime;
}
ostream  &operator<<(ostream &os,const Question &ques)
{
    //这一步很重要
    QByteArray ba1 = ques.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ques.createtime.toLatin1();
    char *timestr = ba2.data();
    QByteArray ba3 = ques.title.toLatin1();
    char *titlestr = ba3.data();
    //os<<ans.getId()<<","<<ans.getUserId()<<","<<ans.getQuestionId()<<","<<ans.getPraisedNum()<<","<<ans.getContent()<<","<<ans.getTime();
    os<<ques.id<<ques.userId<<titlestr<<contentstr<<timestr;
    return os;
}

istream  &operator>>(istream &is,Question &ques)
{
    QByteArray ba1 = ques.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ques.createtime.toLatin1();
    char *timestr = ba2.data();
    QByteArray ba3 = ques.title.toLatin1();
    char *titlestr = ba3.data();
    //is>>ans.getId()>>",">>ans.getUserId()>>",">>ans.getQuestionId()>>",">>ans.getPraisedNum()>>",">>ans.getContent()>>","<<ans.getTime();
    is>>ques.id>>ques.userId>>titlestr>>contentstr>>timestr;
    //输入判断
    if(!is)
        ques = Question(); //如果失败，默认初始化
    return is;
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
