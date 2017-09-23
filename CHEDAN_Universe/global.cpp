<<<<<<< HEAD
#include "global.h"

/*Global::Global()
{

}*/
Database Db;
User USER;
vector<Question> Questions;
vector<Answer> Answers;
vector<User> Users;
vector<Notification> Notifications;
User Global::getUser(int id)
{
    User user;
    vector<User>::iterator it;
    for(it = Users.begin();it!=Users.end();++it)
    {
        user = *it;
        if(user.getId()==id)
            break;
    }
    if(it!=Users.end())
        return user;
    else
    {
        user.setId(-1);
        return user;
    }
}

Question Global::getQuestion(int id)
{
    Question ques;
    for(vector<Question>::iterator it = Questions.begin();it!=Questions.end();++it)
    {
        ques = *it;
        if(ques.getId()==id)
            break;
    }
    return ques;
}

Answer Global::getAnswer(int id)
{
    Answer ans;
    for(vector<Answer>::iterator it = Answers.begin();it!=Answers.end();++it)
    {
       ans = *it;
        if(ans.getId()==id)
               break;
    }
    return ans;
}
Notification Global::getNotification(int id)
{
    Notification notif;
    for(vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
       notif = *it;
        if(notif.getId()==id)
               break;
    }
    return notif;
}

void Global::update(User user)
{
    try{
        for(vector<User>::iterator it = Users.begin();it!=Users.end();++it)
        {

            if((*it).getId()==user.getId())
            {
                (*it).setName(user.getName());
                (*it).setPassword(user.getPassword());
                (*it).setAnswerList(user.getAnswerList());
                (*it).setAskList(user.getAskList());
                (*it).setFollowedList(user.getFollowedList());
                (*it).setPraiseList(user.getPraiseList());
            }
        }
    Db.update(user);
    }
    catch(...)
    {
        qDebug()<<"update user error";
    }
    qDebug()<<"update user success";

}

void Global::update(Question ques)
{
    try{
        for(vector<Question>::iterator it = Questions.begin();it!=Questions.end();++it)
        {

            if((*it).getId()==ques.getId())
            {
                (*it).setTitle(ques.getTitle());
                (*it).setAnswerList(ques.getAnswerList());
                (*it).setContent(ques.getContent());
            }
        }
        Db.update(ques);
    }
    catch(...)
    {
        qDebug()<<"update question error";
    }
}

void Global::update(Answer ans)
{
    for(vector<Answer>::iterator it = Answers.begin();it!=Answers.end();++it)
    {

        if((*it).getId()==ans.getId())
        {

            (*it).setPraisedNum(ans.getPraisedNum());
            (*it).setContent(ans.getContent());
        }
    }
    Db.update(ans);
}

void Global::insert(User user)
{
    Users.push_back(user);
    Db.insert(user);
}

void Global::insert(Question ques)
{
   Questions.push_back(ques);
    Db.insert(ques);
}

void Global::insert(Answer ans)
{
    Answers.push_back(ans);
    Db.insert(ans);
}
void Global::insert(Notification notif)
{
    Notifications.push_back(notif);
    Db.insert(notif);
}
=======
#include "global.h"

/*Global::Global()
{

}*/
Database Db;
User USER;
vector<Question> Questions;
vector<Answer> Answers;
vector<User> Users;
vector<Notification> Notifications;
User Global::getUser(int id)
{
    User user;
    vector<User>::iterator it;
    for(it = Users.begin();it!=Users.end();++it)
    {
        user = *it;
        if(user.getId()==id)
            break;
    }
    if(it!=Users.end())
        return user;
    else
    {
        user.setId(-1);
        return user;
    }
}

Question Global::getQuestion(int id)
{
    Question ques;
    for(vector<Question>::iterator it = Questions.begin();it!=Questions.end();++it)
    {
        ques = *it;
        if(ques.getId()==id)
            break;
    }
    return ques;
}

Answer Global::getAnswer(int id)
{
    Answer ans;
    for(vector<Answer>::iterator it = Answers.begin();it!=Answers.end();++it)
    {
       ans = *it;
        if(ans.getId()==id)
               break;
    }
    return ans;
}
Notification Global::getNotification(int id)
{
    Notification notif;
    for(vector<Notification>::iterator it = Notifications.begin();it!=Notifications.end();++it)
    {
       notif = *it;
        if(notif.getId()==id)
               break;
    }
    return notif;
}

void Global::update(User user)
{
    try{
        for(vector<User>::iterator it = Users.begin();it!=Users.end();++it)
        {

            if((*it).getId()==user.getId())
            {
                (*it).setName(user.getName());
                (*it).setPassword(user.getPassword());
                (*it).setAnswerList(user.getAnswerList());
                (*it).setAskList(user.getAskList());
                (*it).setFollowedList(user.getFollowedList());
                (*it).setPraiseList(user.getPraiseList());
            }
        }
    Db.update(user);
    }
    catch(...)
    {
        qDebug()<<"update user error";
    }
    qDebug()<<"update user success";

}

void Global::update(Question ques)
{
    try{
        for(vector<Question>::iterator it = Questions.begin();it!=Questions.end();++it)
        {

            if((*it).getId()==ques.getId())
            {
                (*it).setTitle(ques.getTitle());
                (*it).setAnswerList(ques.getAnswerList());
                (*it).setContent(ques.getContent());
            }
        }
        Db.update(ques);
    }
    catch(...)
    {
        qDebug()<<"update question error";
    }
}

void Global::update(Answer ans)
{
    for(vector<Answer>::iterator it = Answers.begin();it!=Answers.end();++it)
    {

        if((*it).getId()==ans.getId())
        {

            (*it).setPraisedNum(ans.getPraisedNum());
            (*it).setContent(ans.getContent());
        }
    }
    Db.update(ans);
}

void Global::insert(User user)
{
    Users.push_back(user);
    Db.insert(user);
}

void Global::insert(Question ques)
{
   Questions.push_back(ques);
    Db.insert(ques);
}

void Global::insert(Answer ans)
{
    Answers.push_back(ans);
    Db.insert(ans);
}
void Global::insert(Notification notif)
{
    Notifications.push_back(notif);
    Db.insert(notif);
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
