<<<<<<< HEAD
#ifndef QUESTION_H
#define QUESTION_H
#include "basicinfo.h"
#include <vector>
using namespace std;
class Question :public BasicInfo
{
public:
    Question();


    //void show();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();
    QString getContent();
    QString getTime();
    vector<int> getAnswerList();
    void setAnswerList(vector<int> answerlist);
    QString getTitle();
    void setTitle(QString title);
    void setId(int id);
    void setUserId(int id);
    void setContent(QString content);
    void setTime(QString time);

    //重载输出运算符
    friend  ostream  &operator<<(ostream &os,const Question &ques);  //声明为友元
    //重载输入运算符
    friend  istream  &operator>>(istream &is,Question &ques);
private:
    vector<int> answerlist;
     QString title;

};

#endif // QUESTION_H
=======
#ifndef QUESTION_H
#define QUESTION_H
#include "basicinfo.h"
#include <vector>
using namespace std;
class Question :public BasicInfo
{
public:
    Question();


    //void show();
    void created(int id,int userId,QString content,QString createtime);
    int getId();
    int getUserId();
    QString getContent();
    QString getTime();
    vector<int> getAnswerList();
    void setAnswerList(vector<int> answerlist);
    QString getTitle();
    void setTitle(QString title);
    void setId(int id);
    void setUserId(int id);
    void setContent(QString content);
    void setTime(QString time);

    //重载输出运算符
    friend  ostream  &operator<<(ostream &os,const Question &ques);  //声明为友元
    //重载输入运算符
    friend  istream  &operator>>(istream &is,Question &ques);
private:
    vector<int> answerlist;
     QString title;

};

#endif // QUESTION_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
