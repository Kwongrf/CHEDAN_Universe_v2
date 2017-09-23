<<<<<<< HEAD
#ifndef BASICINFO_H
#define BASICINFO_H

#include <QString>



class BasicInfo
{
public:
    BasicInfo();
    int id;
    int userId;
    QString content;
    QString createtime;

    //virtual void show() = 0;
    virtual void created(int id,int userId,QString content,QString createtime) = 0;

    virtual int getId() = 0;
    virtual int getUserId() = 0;
    virtual QString getContent() = 0;
    virtual QString getTime() = 0;
    virtual void setId(int id) = 0;
    virtual void setUserId(int id) = 0;
    virtual void setContent(QString content) = 0;
    virtual void setTime(QString time) = 0;
};

#endif // BASICINFO_H
=======
#ifndef BASICINFO_H
#define BASICINFO_H

#include <QString>



class BasicInfo
{
public:
    BasicInfo();
    int id;
    int userId;
    QString content;
    QString createtime;

    //virtual void show() = 0;
    virtual void created(int id,int userId,QString content,QString createtime) = 0;

    virtual int getId() = 0;
    virtual int getUserId() = 0;
    virtual QString getContent() = 0;
    virtual QString getTime() = 0;
    virtual void setId(int id) = 0;
    virtual void setUserId(int id) = 0;
    virtual void setContent(QString content) = 0;
    virtual void setTime(QString time) = 0;
};

#endif // BASICINFO_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
