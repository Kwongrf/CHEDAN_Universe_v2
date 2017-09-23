<<<<<<< HEAD
#include "notification.h"

Notification::Notification()
{

}
int Notification::getId()
{
    return this->id;
}

int Notification::getUserId()
{
    return this->userId;
}

QString Notification::getContent()
{
    return this->content;
}

QString Notification::getTime()
{
    return this->createtime;
}
int Notification::getSenderId()
{
    return this->senderId;
}
QString Notification::getTitle()
{
    return this->title;
}
Type Notification::getType()
{
    return this->type;
}
void Notification::setSenderId(int id)
{
    this->senderId = id;
}
void Notification::setTitle(QString title)
{
    this->title = title;
}
void Notification::setType(int type)
{

        this->type = Type(type);
}

void Notification::setId(int id)
{
    this->id = id;
}

void Notification::setUserId(int id)
{
    this->userId = id;
}

void Notification::setContent(QString content)
{
    this->content = content;
}

void Notification::setTime(QString createtime)
{
    this->createtime = createtime;
}
void Notification::created(int id,int userId,QString content,QString createtime)//因为没有实现这个函数导致出现vtable reference
{
    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}
int Notification::getQuestionId()
{
    return this->questionId;
}
int Notification::getAnswerId()
{
    return this->answerId;
}
void Notification::setQuestionId(int id)
{
    this->questionId=id;
}
void Notification::setAnswerId(int id)
{
    this->answerId=id;
}
=======
#include "notification.h"

Notification::Notification()
{

}
int Notification::getId()
{
    return this->id;
}

int Notification::getUserId()
{
    return this->userId;
}

QString Notification::getContent()
{
    return this->content;
}

QString Notification::getTime()
{
    return this->createtime;
}
int Notification::getSenderId()
{
    return this->senderId;
}
QString Notification::getTitle()
{
    return this->title;
}
Type Notification::getType()
{
    return this->type;
}
void Notification::setSenderId(int id)
{
    this->senderId = id;
}
void Notification::setTitle(QString title)
{
    this->title = title;
}
void Notification::setType(int type)
{

        this->type = Type(type);
}

void Notification::setId(int id)
{
    this->id = id;
}

void Notification::setUserId(int id)
{
    this->userId = id;
}

void Notification::setContent(QString content)
{
    this->content = content;
}

void Notification::setTime(QString createtime)
{
    this->createtime = createtime;
}
void Notification::created(int id,int userId,QString content,QString createtime)//因为没有实现这个函数导致出现vtable reference
{
    this->setId(id);
    this->setUserId(userId);
    this->setContent(content);
    this->setTime(createtime);
}
int Notification::getQuestionId()
{
    return this->questionId;
}
int Notification::getAnswerId()
{
    return this->answerId;
}
void Notification::setQuestionId(int id)
{
    this->questionId=id;
}
void Notification::setAnswerId(int id)
{
    this->answerId=id;
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
