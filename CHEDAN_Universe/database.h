<<<<<<< HEAD
#ifndef DATABASE_H
#define DATABASE_H
#include "user.h"
#include "question.h"
#include "answer.h"
#include "notification.h"
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
class Database
{
public:
    bool createConnection();                   //创建一个连接
    bool createTable();                    //创建4张数据库表

    bool insert(User user);                 //插入数据
    bool insert(Question ques);             //出入数据
    bool insert(Answer ans);                //出入数据
    bool insert(Notification notif);

    bool queryById(const int id,User& user);     //查询用户信息
    bool queryById(const int id,Question& ques);            //查询问题信息
    bool queryById(const int id,Answer& ans);            //查询问题信息

    vector<User> queryAllUser();
    vector<Question> queryAllQues();
    vector<Answer> queryAllAns();
    vector<Answer> queryAllAns(vector<int> ids);
    vector<Notification> queryAllNotif();

    bool update(User user);   //更新
    bool update(Question ques);   //更新
    bool update(Answer ans);   //更新
    //bool deleteById(int id);   //删除
    //bool sortById();           //排序
};

#endif // DATABASE_H
=======
#ifndef DATABASE_H
#define DATABASE_H
#include "user.h"
#include "question.h"
#include "answer.h"
#include "notification.h"
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
class Database
{
public:
    bool createConnection();                   //创建一个连接
    bool createTable();                    //创建4张数据库表

    bool insert(User user);                 //插入数据
    bool insert(Question ques);             //出入数据
    bool insert(Answer ans);                //出入数据
    bool insert(Notification notif);

    bool queryById(const int id,User& user);     //查询用户信息
    bool queryById(const int id,Question& ques);            //查询问题信息
    bool queryById(const int id,Answer& ans);            //查询问题信息

    vector<User> queryAllUser();
    vector<Question> queryAllQues();
    vector<Answer> queryAllAns();
    vector<Answer> queryAllAns(vector<int> ids);
    vector<Notification> queryAllNotif();

    bool update(User user);   //更新
    bool update(Question ques);   //更新
    bool update(Answer ans);   //更新
    //bool deleteById(int id);   //删除
    //bool sortById();           //排序
};

#endif // DATABASE_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
