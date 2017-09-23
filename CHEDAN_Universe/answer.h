<<<<<<< HEAD
#ifndef ANSWER_H
#define ANSWER_H
#include "basicinfo.h"
#include <iostream>
class Answer :public BasicInfo
{
public:
    Answer();

    int getPraisedNum();
    void setPraisedNum(int praisedNum);

    //void show();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();
    int getQuestionId();
    QString getContent();
    QString getTime();
    void setId(int id);
    void setUserId(int id);
    void setQuestionId(int id);
    void setContent(QString content);
    void setTime(QString time);

    //重载输出运算符
    friend  std::ostream &operator<<(std::ostream &os,const Answer &ans);  //声明为友元
    //重载输入运算符
    friend  std::istream &operator>>(std::istream &is,Answer &ans);
    //iostream 在std的命名空间里
private:
       int praisedNum;
       int questionId;

};

#endif // ANSWER_H
=======
#ifndef ANSWER_H
#define ANSWER_H
#include "basicinfo.h"
#include <iostream>
class Answer :public BasicInfo
{
public:
    Answer();

    int getPraisedNum();
    void setPraisedNum(int praisedNum);

    //void show();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();
    int getQuestionId();
    QString getContent();
    QString getTime();
    void setId(int id);
    void setUserId(int id);
    void setQuestionId(int id);
    void setContent(QString content);
    void setTime(QString time);

    //重载输出运算符
    friend  std::ostream &operator<<(std::ostream &os,const Answer &ans);  //声明为友元
    //重载输入运算符
    friend  std::istream &operator>>(std::istream &is,Answer &ans);
    //iostream 在std的命名空间里
private:
       int praisedNum;
       int questionId;

};

#endif // ANSWER_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
