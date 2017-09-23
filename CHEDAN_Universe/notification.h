<<<<<<< HEAD
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "basicinfo.h"

#include <QString>

enum Type{Notice=1,Praise=2,Focused=3,Message=4};

class Notification :public BasicInfo
{
public:
    Notification();


    int getSenderId();
    Type getType();
    QString getTitle();
    int getQuestionId();
    int getAnswerId();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();

    QString getContent();
    QString getTime();
    void setId(int id);
    void setUserId(int id);

    void setContent(QString content);
    void setTime(QString time);
    void setTitle(QString title);
    void setSenderId(int id);
    void setType(int type);
    void setQuestionId(int id);
    void setAnswerId(int id);

private:

    int senderId;//谁发的
    int questionId;//邀请回答时的情况
    int answerId;//查看评论或点赞时
    QString title;
    Type type;




};

#endif // NOTIFICATION_H
=======
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "basicinfo.h"

#include <QString>

enum Type{Notice=1,Praise=2,Focused=3,Message=4};

class Notification :public BasicInfo
{
public:
    Notification();


    int getSenderId();
    Type getType();
    QString getTitle();
    int getQuestionId();
    int getAnswerId();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();

    QString getContent();
    QString getTime();
    void setId(int id);
    void setUserId(int id);

    void setContent(QString content);
    void setTime(QString time);
    void setTitle(QString title);
    void setSenderId(int id);
    void setType(int type);
    void setQuestionId(int id);
    void setAnswerId(int id);

private:

    int senderId;//谁发的
    int questionId;//邀请回答时的情况
    int answerId;//查看评论或点赞时
    QString title;
    Type type;




};

#endif // NOTIFICATION_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
