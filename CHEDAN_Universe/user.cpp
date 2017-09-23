<<<<<<< HEAD
#include "user.h"
#include "global.h"
User::User()
{

}
int User::getId()
{
    return this->id;
}

void User::setId(int id)
{
    this->id = id;
}

QString User::getName()
{
    return this->name;
}

void User::setName(QString name)
{
    this->name = name;
}

QString User::getPassword()
{
    return this->password;
}

void User::setPassword(QString password)
{
    this->password = password;
}
int User::getPraisedNum()
{
    return this->praisedNum;
}

void User::setPraisedNum(int n)
{
    this->praisedNum = n;
}

vector<int> User::getFocusList()
{
    return this->focuslist;
}

void User::handleFocusList(int id,bool method)//method = 1 增加，method = 0减少
{
    if(method)
    {
        this->focuslist.push_back(id);
    }
    else
    {
        for(vector<int>::iterator it=this->focuslist.begin();it!=this->focuslist.end();++it)
        {
            if(*it<0 || *it>Users.size())
                break;
            if(*it ==id)
            {
                it=this->focuslist.erase(it);
                break;
            }
        }
    }
}
void User::setFocusList(vector<int> focuslist)
{
    this->focuslist = focuslist;
}

vector<int> User::getFollowedList()
{
    return this->followedlist;
}

void User::handleFollowedList(int id,bool method)//method = 1 增加，method = 0减少
{
    if(method)
    {
        this->followedlist.push_back(id);
    }
    else
    {
        for(vector<int>::iterator it=this->followedlist.begin();it!=this->followedlist.end();++it)
        {
            if(*it<0 || *it>Users.size())
                break;
            if(*it ==id)
             {
                it=this->followedlist.erase(it);
                break;
            }
        }
    }
}
void User::setFollowedList(vector<int> followedlist)
{
    this->followedlist = followedlist;
}

vector<int> User::getPraiseList()
{
    return this->praiselist;
}

void User::setPraiseList(vector<int> praiselist)
{
    this->praiselist = praiselist;
}

void User::handlePraiseList(int id,bool method)
{
    if(method)
    {
        this->praiselist.push_back(id);
        //this->setPraisedNum(this->getPraisedNum()+1);
        qDebug()<<"pushback success";
    }
    else
    {
        for(vector<int>::iterator it=this->praiselist.begin();it!=this->praiselist.end();it++)
        {

            qDebug()<<"handle "<<*it<<"and id"<<id;
            if(*it ==id)
            {
                it=this->praiselist.erase(it);
                //this->setPraisedNum(this->getPraisedNum()-1);
                qDebug()<<"erase user success";
                break;
            }
            else if(*it > Answers.size()||*it<0)//这里出现一个错就是误以为it要小于用户数量，但是肯定不行
                break;
        }
    }
    qDebug()<<"handlePraiseList";
}
vector<int> User::getAnswerList()
{
    return this->answerlist;
}

void User::setAnswerList(vector<int> answerlist)
{
    this->answerlist = answerlist;
}
void User::handleAnswerList(int id,bool method)
{
    if(method)
    {
        this->answerlist.push_back(id);
        qDebug()<<"add answer success";
    }
    else
    {
        for(vector<int>::iterator it=this->answerlist.begin();it!=this->answerlist.end();++it)
        {

            if(*it == id)
            {
                it=this->answerlist.erase(it);
                qDebug()<<"erase answer success";
                break;
            }
            else if(*it> Answers.size()||*it<0)
                break;
        }
    }
}

vector<int> User::getAskList()
{
    return this->asklist;
}

void User::setAskList(vector<int>asklist)
{
    this->asklist = asklist;
}

void User::handleAskList(int id,bool method)
{
    if(method)
    {
        this->asklist.push_back(id);
        qDebug()<<"add ques success";
    }
    else
    {
        for(vector<int>::iterator it=this->asklist.begin();it!=this->asklist.end();++it)
        {

            if(*it ==id)
            {
                it=this->asklist.erase(it);
                qDebug()<<"erase ques success";
                break;
            }
            else if(*it > Questions.size()||*it<0)
                break;
        }
    }
}
=======
#include "user.h"
#include "global.h"
User::User()
{

}
int User::getId()
{
    return this->id;
}

void User::setId(int id)
{
    this->id = id;
}

QString User::getName()
{
    return this->name;
}

void User::setName(QString name)
{
    this->name = name;
}

QString User::getPassword()
{
    return this->password;
}

void User::setPassword(QString password)
{
    this->password = password;
}
int User::getPraisedNum()
{
    return this->praisedNum;
}

void User::setPraisedNum(int n)
{
    this->praisedNum = n;
}

vector<int> User::getFocusList()
{
    return this->focuslist;
}

void User::handleFocusList(int id,bool method)//method = 1 增加，method = 0减少
{
    if(method)
    {
        this->focuslist.push_back(id);
    }
    else
    {
        for(vector<int>::iterator it=this->focuslist.begin();it!=this->focuslist.end();++it)
        {
            if(*it<0 || *it>Users.size())
                break;
            if(*it ==id)
            {
                it=this->focuslist.erase(it);
                break;
            }
        }
    }
}
void User::setFocusList(vector<int> focuslist)
{
    this->focuslist = focuslist;
}

vector<int> User::getFollowedList()
{
    return this->followedlist;
}

void User::handleFollowedList(int id,bool method)//method = 1 增加，method = 0减少
{
    if(method)
    {
        this->followedlist.push_back(id);
    }
    else
    {
        for(vector<int>::iterator it=this->followedlist.begin();it!=this->followedlist.end();++it)
        {
            if(*it<0 || *it>Users.size())
                break;
            if(*it ==id)
             {
                it=this->followedlist.erase(it);
                break;
            }
        }
    }
}
void User::setFollowedList(vector<int> followedlist)
{
    this->followedlist = followedlist;
}

vector<int> User::getPraiseList()
{
    return this->praiselist;
}

void User::setPraiseList(vector<int> praiselist)
{
    this->praiselist = praiselist;
}

void User::handlePraiseList(int id,bool method)
{
    if(method)
    {
        this->praiselist.push_back(id);
        //this->setPraisedNum(this->getPraisedNum()+1);
        qDebug()<<"pushback success";
    }
    else
    {
        for(vector<int>::iterator it=this->praiselist.begin();it!=this->praiselist.end();it++)
        {

            qDebug()<<"handle "<<*it<<"and id"<<id;
            if(*it ==id)
            {
                it=this->praiselist.erase(it);
                //this->setPraisedNum(this->getPraisedNum()-1);
                qDebug()<<"erase user success";
                break;
            }
            else if(*it > Answers.size()||*it<0)//这里出现一个错就是误以为it要小于用户数量，但是肯定不行
                break;
        }
    }
    qDebug()<<"handlePraiseList";
}
vector<int> User::getAnswerList()
{
    return this->answerlist;
}

void User::setAnswerList(vector<int> answerlist)
{
    this->answerlist = answerlist;
}
void User::handleAnswerList(int id,bool method)
{
    if(method)
    {
        this->answerlist.push_back(id);
        qDebug()<<"add answer success";
    }
    else
    {
        for(vector<int>::iterator it=this->answerlist.begin();it!=this->answerlist.end();++it)
        {

            if(*it == id)
            {
                it=this->answerlist.erase(it);
                qDebug()<<"erase answer success";
                break;
            }
            else if(*it> Answers.size()||*it<0)
                break;
        }
    }
}

vector<int> User::getAskList()
{
    return this->asklist;
}

void User::setAskList(vector<int>asklist)
{
    this->asklist = asklist;
}

void User::handleAskList(int id,bool method)
{
    if(method)
    {
        this->asklist.push_back(id);
        qDebug()<<"add ques success";
    }
    else
    {
        for(vector<int>::iterator it=this->asklist.begin();it!=this->asklist.end();++it)
        {

            if(*it ==id)
            {
                it=this->asklist.erase(it);
                qDebug()<<"erase ques success";
                break;
            }
            else if(*it > Questions.size()||*it<0)
                break;
        }
    }
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
