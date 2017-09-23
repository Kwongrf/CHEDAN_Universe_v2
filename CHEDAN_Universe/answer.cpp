<<<<<<< HEAD
#include "answer.h"
#include "global.h"
Answer::Answer()
{

}


void Answer::created(int id,int userId,QString content,QString createtime)
{

    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}
int Answer::getPraisedNum()
{
    return this->praisedNum;
}
void Answer::setPraisedNum(int praisedNum)
{
    this->praisedNum = praisedNum;
}

int Answer::getId()
{
    return this->id;
}

int Answer::getUserId()
{
    return this->userId;
}
int Answer::getQuestionId()
{
    return this->questionId;
}

QString Answer::getContent()
{
    return this->content;
}

QString Answer::getTime()
{
    return this->createtime;
}
void Answer::setId(int id)
{
    this->id = id;
}

void Answer::setUserId(int id)
{
    this->userId = id;
}
void Answer::setQuestionId(int id)
{
    this->questionId = id;
}

void Answer::setContent(QString content)
{
    this->content = content;
}

void Answer::setTime(QString createtime)
{
    this->createtime = createtime;
}

std::ostream &operator<<(std::ostream &os,const Answer &ans)//这里出现了一个坑就是我把它定义在.h文件里，导致multiple definition，可以用inline或者定义到cpp
{
    //os<<ans.getId()<<","<<ans.getUserId()<<","<<ans.getQuestionId()<<","<<ans.getPraisedNum()<<","<<ans.getContent()<<","<<ans.getTime();

    QByteArray ba1 = ans.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ans.createtime.toLatin1();
    char *timestr = ba2.data();
    os<<ans.id<<ans.userId<<ans.questionId<<ans.praisedNum<<contentstr<<timestr;
    Global::insert(ans);
    return os;
}

std::istream &operator>>(std::istream &is,Answer &ans)
{
    ans = Global::getAnswer(ans.getId());
    QByteArray ba1 = ans.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ans.createtime.toLatin1();
    char *timestr = ba2.data();
    //is>>ans.getId()>>",">>ans.getUserId()>>",">>ans.getQuestionId()>>",">>ans.getPraisedNum()>>",">>ans.getContent()>>","<<ans.getTime();
    is>>ans.id>>ans.userId>>ans.questionId>>ans.praisedNum>>contentstr>>timestr;
    //输入判断

    if(!is)
        ans = Answer(); //如果失败，默认初始化
    return is;
}
=======
#include "answer.h"
#include "global.h"
Answer::Answer()
{

}


void Answer::created(int id,int userId,QString content,QString createtime)
{

    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}
int Answer::getPraisedNum()
{
    return this->praisedNum;
}
void Answer::setPraisedNum(int praisedNum)
{
    this->praisedNum = praisedNum;
}

int Answer::getId()
{
    return this->id;
}

int Answer::getUserId()
{
    return this->userId;
}
int Answer::getQuestionId()
{
    return this->questionId;
}

QString Answer::getContent()
{
    return this->content;
}

QString Answer::getTime()
{
    return this->createtime;
}
void Answer::setId(int id)
{
    this->id = id;
}

void Answer::setUserId(int id)
{
    this->userId = id;
}
void Answer::setQuestionId(int id)
{
    this->questionId = id;
}

void Answer::setContent(QString content)
{
    this->content = content;
}

void Answer::setTime(QString createtime)
{
    this->createtime = createtime;
}

std::ostream &operator<<(std::ostream &os,const Answer &ans)//这里出现了一个坑就是我把它定义在.h文件里，导致multiple definition，可以用inline或者定义到cpp
{
    //os<<ans.getId()<<","<<ans.getUserId()<<","<<ans.getQuestionId()<<","<<ans.getPraisedNum()<<","<<ans.getContent()<<","<<ans.getTime();

    QByteArray ba1 = ans.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ans.createtime.toLatin1();
    char *timestr = ba2.data();
    os<<ans.id<<ans.userId<<ans.questionId<<ans.praisedNum<<contentstr<<timestr;
    Global::insert(ans);
    return os;
}

std::istream &operator>>(std::istream &is,Answer &ans)
{
    ans = Global::getAnswer(ans.getId());
    QByteArray ba1 = ans.content.toLatin1();
    char *contentstr = ba1.data();
    QByteArray ba2 = ans.createtime.toLatin1();
    char *timestr = ba2.data();
    //is>>ans.getId()>>",">>ans.getUserId()>>",">>ans.getQuestionId()>>",">>ans.getPraisedNum()>>",">>ans.getContent()>>","<<ans.getTime();
    is>>ans.id>>ans.userId>>ans.questionId>>ans.praisedNum>>contentstr>>timestr;
    //输入判断

    if(!is)
        ans = Answer(); //如果失败，默认初始化
    return is;
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
