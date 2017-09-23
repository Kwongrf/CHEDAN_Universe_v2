<<<<<<< HEAD
#include "database.h"
#include "user.h"
#include <QSqlTableModel>
#include <QString>


string vectostr(vector<int>list);
vector<int> split(QString& str,const char* c);

//建立一个数据库连接
bool Database::createConnection()
{

    //以后就可以用"sqlite1"与数据库进行连接了
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","sqlite1");
    db.setDatabaseName(".//CHEDAN_Universe.db");
    if( !db.open())
    {   QSqlQuery query(db);
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("无法建立数据库连接"));
        return false;
    }
    qDebug() << QString(QObject::tr("建立数据库连接"));
    return true;
}
//创建数据库表
bool Database::createTable()
{

    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success1 = query.exec("create table users(id int primary key,name varchar(30),userpassword varchar(30),praisedNum int,answerlist varchar(100),asklist varchar(100),focuslist varchar(100),followedlist varchar(100),praiselist varchar(100))");
    if(success1)
    {
        qDebug() << QObject::tr("数据库表1创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表1失败"));

    }
    bool success2 = query.exec("create table questions(id int primary key,title varchar(100),userId int,"
                              "content varchar(200),createtime varchar(40),answerlist varchar(100))");
    if(success2)
    {
        qDebug() << QObject::tr("数据库表2创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表2失败"));

    }
    bool success3 = query.exec("create table answers(id int primary key,userId int,questionId int,"
                              "praisedNum int,content varchar(200),createtime varchar(40))");
    if(success3)
    {
        qDebug() << QObject::tr("数据库表3创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表3失败"));

    }
    bool success4 = query.exec("create table notifications(id int primary key,userId int,senderId int,noticetype int,"
                              "title varchar(100),content varchar(200),createtime varchar(40),questionId int, answerId int)");
    if(success4)
    {
        qDebug() << QObject::tr("数据库表4创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表4失败"));
        return false;
    }
    return true;
}

//向数据库中插入记录,即注册账号信息
bool Database::insert(User user)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接

    QSqlQuery query(db);
    query.prepare("insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, user.getId());
    query.bindValue(1, user.getName());
    query.bindValue(2, user.getPassword());
    query.bindValue(3, user.getPraisedNum());
    string answerliststr = vectostr(user.getAnswerList());
    query.bindValue(4,answerliststr.c_str());

    string askliststr = vectostr(user.getAskList());
    query.bindValue(5,askliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string focusliststr = vectostr(user.getFocusList());
    query.bindValue(6, focusliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string followedliststr = vectostr(user.getFollowedList());
    query.bindValue(7,followedliststr.c_str());

    string praiseliststr = vectostr(user.getPraiseList());
    query.bindValue(8,praiseliststr.c_str());


    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

bool Database::insert(Question ques)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into questions values(?, ?, ?, ?, ?, ?)");
    query.bindValue(0, ques.getId());
    query.bindValue(1, ques.getTitle());
    query.bindValue(2, ques.getUserId());
    query.bindValue(3, ques.getContent());
    query.bindValue(4, ques.getTime());
    //将vector<int>转化成一个字符串存起来
    string answerliststr = vectostr(ques.getAnswerList());
    query.bindValue(5,answerliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

bool Database::insert(Answer ans)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into answers values(?, ?, ?, ?, ?, ?)");
    query.bindValue(0, ans.getId());
    query.bindValue(1, ans.getUserId());
    query.bindValue(2, ans.getQuestionId());
    query.bindValue(3, ans.getPraisedNum());
    query.bindValue(4, ans.getContent());
    query.bindValue(5, ans.getTime());


    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}
bool Database::insert(Notification notif)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into notifications values(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, notif.getId());
    query.bindValue(1, notif.getUserId());
    query.bindValue(2, notif.getSenderId());
    query.bindValue(3, notif.getType());
    query.bindValue(4, notif.getTitle());
    query.bindValue(5, notif.getContent());
    query.bindValue(6, notif.getTime());
    query.bindValue(7, notif.getQuestionId());
    query.bindValue(8, notif.getAnswerId());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

//查询某个用户信息
bool Database::queryById(const int id,User& user)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    /*QSqlTableModel model;
    model.setTable("users");
    model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    char* idstr = itoa(id,idstr,10);
    //model->setFilter(QObject::tr("id = %1").arg(idstr));
    model.setFilter("id = 1");
    if(model.select())
    {
        const char* c = ",";
        QSqlRecord record = model.record(0);
        user.setId(record.value("id").toInt());
        user.setName(record.value("name").toString());
        user.setPassword(record.value("password").toString());
        user.setPraisedNum(record.value("praisedNum").toInt());
        user.setAnswerNum(record.value("answerNum").toInt());
        user.setAskNum(record.value("askNum").toInt());
        QString focusstr = record.value("focuslist").toString();
        vector<int>focuslist = split(focusstr,c);
        user.setFocusList(focuslist);
        QString followedstr = record.value("followedlist").toString();
        user.setFollowedList(split(followedstr,c));
        return true;
    }
    else
    {

        return false;
    }*/
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from users where id = %1").arg(id));
    //bool success = query.exec("select * from users where id = 1");
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
           for(int index = 0; index < 7; index++)
               qDebug() << query.value(index) << " ";
           qDebug() << "\n";
            const char* c = ",";
            user.setId(id);
            user.setName(query.value(1).toString());
            user.setPassword(query.value(2).toString());
            user.setPraisedNum(query.value(3).toInt());
            QString answerstr = query.value(4).toString();
            user.setAnswerList(split(answerstr,c));
            QString askstr = query.value(5).toString();
            user.setAnswerList(split(askstr,c));
            QString focusstr = query.value(6).toString();
            vector<int>focuslist = split(focusstr,c);
            user.setFocusList(focuslist);
            QString followedstr = query.value(7).toString();
            user.setFollowedList(split(followedstr,c));
            QString praisestr = query.value(8).toString();
            user.setPraiseList(split(praisestr,c));


            qDebug()<<query.value(2).toString();
            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}
bool Database::queryById(const int id,Question& ques)            //查询问题信息
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from questions where id = %1").arg(id));
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
            const char* c = ",";
            ques.setId(id);
            ques.setTitle(query.value(1).toString());
            ques.setUserId(query.value(2).toInt());
            ques.setContent(query.value(3).toString());
            ques.setTime(query.value(4).toString());

            QString answerstr = query.value(5).toString();
            vector<int>answerlist = split(answerstr,c);
            ques.setAnswerList(answerlist);

            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}

bool Database::queryById(const int id,Answer& ans)            //查询问题信息
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from answers where id = %1").arg(id));
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
            ans.setId(id);
            ans.setUserId(query.value(1).toInt());
            ans.setQuestionId(query.value(2).toInt());
            ans.setPraisedNum(query.value(3).toInt());
            ans.setContent(query.value(4).toString());
            ans.setTime(query.value(5).toString());

            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}
vector<Question> Database::queryAllQues()                         //返回所有问题
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from questions");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Question> questions;
        while(query.next())
        {
            Question ques;
            const char* c = ",";
            ques.setId(query.value(0).toInt());
            ques.setTitle(query.value(1).toString());
            ques.setUserId(query.value(2).toInt());
            ques.setContent(query.value(3).toString());
            ques.setTime(query.value(4).toString());

            QString answerstr = query.value(5).toString();
            vector<int>answerlist = split(answerstr,c);
            ques.setAnswerList(answerlist);
            questions.push_back(ques);

        }
        return questions;

    }
    else
    {
        qDebug()<<query.lastError();

    }
}
vector<Answer> Database::queryAllAns()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from answers");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Answer> answers;
        while(query.next())
        {
            Answer ans;
            ans.setId(query.value(0).toInt());
            ans.setUserId(query.value(1).toInt());
            ans.setQuestionId(query.value(2).toInt());
            ans.setPraisedNum(query.value(3).toInt());
            ans.setContent(query.value(4).toString());
            ans.setTime(query.value(5).toString());

            answers.push_back(ans);

        }
        return answers;
    }
}
vector<User> Database::queryAllUser()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from users");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<User> users;
        while(query.next())
        {
            User user;
            const char* c = ",";
            user.setId(query.value(0).toInt());
            user.setName(query.value(1).toString());
            user.setPassword(query.value(2).toString());
            user.setPraisedNum(query.value(3).toInt());
            QString answerstr = query.value(4).toString();
            user.setAnswerList(split(answerstr,c));
            QString askstr = query.value(5).toString();
            user.setAskList(split(askstr,c));
            QString focusstr = query.value(6).toString();
            vector<int>focuslist = split(focusstr,c);
            user.setFocusList(focuslist);
            QString followedstr = query.value(7).toString();
            user.setFollowedList(split(followedstr,c));
            QString praisestr = query.value(8).toString();
            user.setPraiseList(split(praisestr,c));

            users.push_back(user);

        }
        return users;
    }
}

vector<Answer> Database::queryAllAns(vector<int> ids)
{
    Answer ans;
    vector<Answer> answers;
    for (vector<int>::iterator it = ids.begin();it!=ids.end();++it)
    {
        queryById(*it,ans);
        answers.push_back(ans);
    }
    return answers;

}
bool Database::update(User user)   //更新
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update users set id=?,name=?,"
                             "userpassword=?, praisedNum=?,"                           
                             "answerlist=?, asklist=?,"
                             "focuslist=?, followedlist=?,"
                             "praiselist=? where id = %1").arg(user.getId()));

    query.bindValue(0, user.getId());
    query.bindValue(1, user.getName());
    query.bindValue(2, user.getPassword());
    query.bindValue(3, user.getPraisedNum());
    string answerliststr = vectostr(user.getAnswerList());
    query.bindValue(4,answerliststr.c_str());

    string askliststr = vectostr(user.getAskList());
    query.bindValue(5,askliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string focusliststr = vectostr(user.getFocusList());
    query.bindValue(6, focusliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string followedliststr = vectostr(user.getFollowedList());
    query.bindValue(7,followedliststr.c_str());

    string praiseliststr = vectostr(user.getPraiseList());
    query.bindValue(8,praiseliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("user更新失败"));
          return false;
    }
    return true;
}
vector<Notification> Database::queryAllNotif()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from notifications");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Notification> notifications;
        while(query.next())
        {
            Notification notif;
            notif.setId(query.value(0).toInt());
            notif.setUserId(query.value(1).toInt());
            notif.setSenderId(query.value(2).toInt());
            notif.setType(query.value(3).toInt());
            notif.setTitle(query.value(4).toString());
            notif.setContent(query.value(5).toString());
            notif.setTime(query.value(6).toString());
            notif.setQuestionId(query.value(7).toInt());
            notif.setAnswerId(query.value(8).toInt());
            notifications.push_back(notif);

        }
        return notifications;
    }
}

bool Database::update(Question ques)   //更新
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update questions set id=?,title=?,"
                             "userId=?, content=?,"
                             "createtime=?, answerlist=?"
                             " where id=%1").arg(ques.getId()));
    //qDebug()<<ques.getId()<<" "<<ques.getTitle()<<" "<<ques.getUserId()<<" "<<ques.getContent()<<" "<<ques.getTime();
    query.bindValue(0, ques.getId());
    query.bindValue(1, ques.getTitle());
    query.bindValue(2, ques.getUserId());
    query.bindValue(3, ques.getContent());
    query.bindValue(4, ques.getTime());
    //将vector<int>转化成一个字符串存起来
    string answerliststr = vectostr(ques.getAnswerList());
    query.bindValue(5,answerliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("qustion更新失败"));
          return false;
    }
    return true;
}
bool Database::update(Answer ans)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update answers set id=?,userId=?,"
                             "questionId=?,praisedNum=?,content=?,"
                             "createtime=? where id=%1").arg(ans.getId()));
    //qDebug()<<ans.getId()<<" "<<ans.getUserId()<<" "<<ans.getPraisedNum()<<" "<<ans.getContent()<<" "<<ans.getTime();
    query.bindValue(0, ans.getId());
    query.bindValue(1, ans.getUserId());
    query.bindValue(2, ans.getQuestionId());
    query.bindValue(3, ans.getPraisedNum());
    query.bindValue(4, ans.getContent());
    query.bindValue(5, ans.getTime());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("answer更新失败"));
          return false;
    }
    return true;
}


string vectostr(vector<int>list)
{
    string liststr="";
    string str="";
    char* cstr;
    for(vector<int>::iterator it=list.begin();it!=list.end();++it)
    {
        itoa(*it,cstr,10);
        str = cstr;
        liststr =liststr+str;
        if (it!=list.end()-1)
            liststr =liststr+",";
    }
    return liststr;
}

vector<int> split(QString& str,const char* c)
{
    char *cstr, *p;
    vector<int> res;
    //cstr = new char[str.size()+1];
    //strcpy(cstr,str.c_str());
    QByteArray ba = str.toLatin1();
    cstr = ba.data();
    p = strtok(cstr,c);
    //qDebug()<<"split"<<p;
    while(p!=NULL)
    {
        res.push_back(atoi(p));
        p = strtok(NULL,c);
        //qDebug()<<"split"<<p;
    }
    return res;
}
=======
#include "database.h"
#include "user.h"
#include <QSqlTableModel>
#include <QString>


string vectostr(vector<int>list);
vector<int> split(QString& str,const char* c);

//建立一个数据库连接
bool Database::createConnection()
{

    //以后就可以用"sqlite1"与数据库进行连接了
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","sqlite1");
    db.setDatabaseName(".//CHEDAN_Universe.db");
    if( !db.open())
    {   QSqlQuery query(db);
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("无法建立数据库连接"));
        return false;
    }
    qDebug() << QString(QObject::tr("建立数据库连接"));
    return true;
}
//创建数据库表
bool Database::createTable()
{

    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success1 = query.exec("create table users(id int primary key,name varchar(30),userpassword varchar(30),praisedNum int,answerlist varchar(100),asklist varchar(100),focuslist varchar(100),followedlist varchar(100),praiselist varchar(100))");
    if(success1)
    {
        qDebug() << QObject::tr("数据库表1创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表1失败"));

    }
    bool success2 = query.exec("create table questions(id int primary key,title varchar(100),userId int,"
                              "content varchar(200),createtime varchar(40),answerlist varchar(100))");
    if(success2)
    {
        qDebug() << QObject::tr("数据库表2创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表2失败"));

    }
    bool success3 = query.exec("create table answers(id int primary key,userId int,questionId int,"
                              "praisedNum int,content varchar(200),createtime varchar(40))");
    if(success3)
    {
        qDebug() << QObject::tr("数据库表3创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表3失败"));

    }
    bool success4 = query.exec("create table notifications(id int primary key,userId int,senderId int,noticetype int,"
                              "title varchar(100),content varchar(200),createtime varchar(40),questionId int, answerId int)");
    if(success4)
    {
        qDebug() << QObject::tr("数据库表4创建成功！\n");

    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("创建数据库表4失败"));
        return false;
    }
    return true;
}

//向数据库中插入记录,即注册账号信息
bool Database::insert(User user)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接

    QSqlQuery query(db);
    query.prepare("insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, user.getId());
    query.bindValue(1, user.getName());
    query.bindValue(2, user.getPassword());
    query.bindValue(3, user.getPraisedNum());
    string answerliststr = vectostr(user.getAnswerList());
    query.bindValue(4,answerliststr.c_str());

    string askliststr = vectostr(user.getAskList());
    query.bindValue(5,askliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string focusliststr = vectostr(user.getFocusList());
    query.bindValue(6, focusliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string followedliststr = vectostr(user.getFollowedList());
    query.bindValue(7,followedliststr.c_str());

    string praiseliststr = vectostr(user.getPraiseList());
    query.bindValue(8,praiseliststr.c_str());


    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

bool Database::insert(Question ques)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into questions values(?, ?, ?, ?, ?, ?)");
    query.bindValue(0, ques.getId());
    query.bindValue(1, ques.getTitle());
    query.bindValue(2, ques.getUserId());
    query.bindValue(3, ques.getContent());
    query.bindValue(4, ques.getTime());
    //将vector<int>转化成一个字符串存起来
    string answerliststr = vectostr(ques.getAnswerList());
    query.bindValue(5,answerliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

bool Database::insert(Answer ans)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into answers values(?, ?, ?, ?, ?, ?)");
    query.bindValue(0, ans.getId());
    query.bindValue(1, ans.getUserId());
    query.bindValue(2, ans.getQuestionId());
    query.bindValue(3, ans.getPraisedNum());
    query.bindValue(4, ans.getContent());
    query.bindValue(5, ans.getTime());


    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}
bool Database::insert(Notification notif)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into notifications values(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, notif.getId());
    query.bindValue(1, notif.getUserId());
    query.bindValue(2, notif.getSenderId());
    query.bindValue(3, notif.getType());
    query.bindValue(4, notif.getTitle());
    query.bindValue(5, notif.getContent());
    query.bindValue(6, notif.getTime());
    query.bindValue(7, notif.getQuestionId());
    query.bindValue(8, notif.getAnswerId());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return false;
    }
    return true;
}

//查询某个用户信息
bool Database::queryById(const int id,User& user)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    /*QSqlTableModel model;
    model.setTable("users");
    model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    char* idstr = itoa(id,idstr,10);
    //model->setFilter(QObject::tr("id = %1").arg(idstr));
    model.setFilter("id = 1");
    if(model.select())
    {
        const char* c = ",";
        QSqlRecord record = model.record(0);
        user.setId(record.value("id").toInt());
        user.setName(record.value("name").toString());
        user.setPassword(record.value("password").toString());
        user.setPraisedNum(record.value("praisedNum").toInt());
        user.setAnswerNum(record.value("answerNum").toInt());
        user.setAskNum(record.value("askNum").toInt());
        QString focusstr = record.value("focuslist").toString();
        vector<int>focuslist = split(focusstr,c);
        user.setFocusList(focuslist);
        QString followedstr = record.value("followedlist").toString();
        user.setFollowedList(split(followedstr,c));
        return true;
    }
    else
    {

        return false;
    }*/
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from users where id = %1").arg(id));
    //bool success = query.exec("select * from users where id = 1");
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
           for(int index = 0; index < 7; index++)
               qDebug() << query.value(index) << " ";
           qDebug() << "\n";
            const char* c = ",";
            user.setId(id);
            user.setName(query.value(1).toString());
            user.setPassword(query.value(2).toString());
            user.setPraisedNum(query.value(3).toInt());
            QString answerstr = query.value(4).toString();
            user.setAnswerList(split(answerstr,c));
            QString askstr = query.value(5).toString();
            user.setAnswerList(split(askstr,c));
            QString focusstr = query.value(6).toString();
            vector<int>focuslist = split(focusstr,c);
            user.setFocusList(focuslist);
            QString followedstr = query.value(7).toString();
            user.setFollowedList(split(followedstr,c));
            QString praisestr = query.value(8).toString();
            user.setPraiseList(split(praisestr,c));


            qDebug()<<query.value(2).toString();
            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}
bool Database::queryById(const int id,Question& ques)            //查询问题信息
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from questions where id = %1").arg(id));
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
            const char* c = ",";
            ques.setId(id);
            ques.setTitle(query.value(1).toString());
            ques.setUserId(query.value(2).toInt());
            ques.setContent(query.value(3).toString());
            ques.setTime(query.value(4).toString());

            QString answerstr = query.value(5).toString();
            vector<int>answerlist = split(answerstr,c);
            ques.setAnswerList(answerlist);

            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}

bool Database::queryById(const int id,Answer& ans)            //查询问题信息
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec(QString("select * from answers where id = %1").arg(id));
    qDebug()<< " "<<success;
    if(success)
    {

       if(query.next())
        {
            ans.setId(id);
            ans.setUserId(query.value(1).toInt());
            ans.setQuestionId(query.value(2).toInt());
            ans.setPraisedNum(query.value(3).toInt());
            ans.setContent(query.value(4).toString());
            ans.setTime(query.value(5).toString());

            return true;
        }
        else
           return false;

    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}
vector<Question> Database::queryAllQues()                         //返回所有问题
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from questions");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Question> questions;
        while(query.next())
        {
            Question ques;
            const char* c = ",";
            ques.setId(query.value(0).toInt());
            ques.setTitle(query.value(1).toString());
            ques.setUserId(query.value(2).toInt());
            ques.setContent(query.value(3).toString());
            ques.setTime(query.value(4).toString());

            QString answerstr = query.value(5).toString();
            vector<int>answerlist = split(answerstr,c);
            ques.setAnswerList(answerlist);
            questions.push_back(ques);

        }
        return questions;

    }
    else
    {
        qDebug()<<query.lastError();

    }
}
vector<Answer> Database::queryAllAns()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from answers");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Answer> answers;
        while(query.next())
        {
            Answer ans;
            ans.setId(query.value(0).toInt());
            ans.setUserId(query.value(1).toInt());
            ans.setQuestionId(query.value(2).toInt());
            ans.setPraisedNum(query.value(3).toInt());
            ans.setContent(query.value(4).toString());
            ans.setTime(query.value(5).toString());

            answers.push_back(ans);

        }
        return answers;
    }
}
vector<User> Database::queryAllUser()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from users");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<User> users;
        while(query.next())
        {
            User user;
            const char* c = ",";
            user.setId(query.value(0).toInt());
            user.setName(query.value(1).toString());
            user.setPassword(query.value(2).toString());
            user.setPraisedNum(query.value(3).toInt());
            QString answerstr = query.value(4).toString();
            user.setAnswerList(split(answerstr,c));
            QString askstr = query.value(5).toString();
            user.setAskList(split(askstr,c));
            QString focusstr = query.value(6).toString();
            vector<int>focuslist = split(focusstr,c);
            user.setFocusList(focuslist);
            QString followedstr = query.value(7).toString();
            user.setFollowedList(split(followedstr,c));
            QString praisestr = query.value(8).toString();
            user.setPraiseList(split(praisestr,c));

            users.push_back(user);

        }
        return users;
    }
}

vector<Answer> Database::queryAllAns(vector<int> ids)
{
    Answer ans;
    vector<Answer> answers;
    for (vector<int>::iterator it = ids.begin();it!=ids.end();++it)
    {
        queryById(*it,ans);
        answers.push_back(ans);
    }
    return answers;

}
bool Database::update(User user)   //更新
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update users set id=?,name=?,"
                             "userpassword=?, praisedNum=?,"                           
                             "answerlist=?, asklist=?,"
                             "focuslist=?, followedlist=?,"
                             "praiselist=? where id = %1").arg(user.getId()));

    query.bindValue(0, user.getId());
    query.bindValue(1, user.getName());
    query.bindValue(2, user.getPassword());
    query.bindValue(3, user.getPraisedNum());
    string answerliststr = vectostr(user.getAnswerList());
    query.bindValue(4,answerliststr.c_str());

    string askliststr = vectostr(user.getAskList());
    query.bindValue(5,askliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string focusliststr = vectostr(user.getFocusList());
    query.bindValue(6, focusliststr.c_str());
    //将vector<int>转化成一个字符串存起来
    string followedliststr = vectostr(user.getFollowedList());
    query.bindValue(7,followedliststr.c_str());

    string praiseliststr = vectostr(user.getPraiseList());
    query.bindValue(8,praiseliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("user更新失败"));
          return false;
    }
    return true;
}
vector<Notification> Database::queryAllNotif()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("select * from notifications");
    qDebug()<< " "<<success;
    if(success)
    {
        vector<Notification> notifications;
        while(query.next())
        {
            Notification notif;
            notif.setId(query.value(0).toInt());
            notif.setUserId(query.value(1).toInt());
            notif.setSenderId(query.value(2).toInt());
            notif.setType(query.value(3).toInt());
            notif.setTitle(query.value(4).toString());
            notif.setContent(query.value(5).toString());
            notif.setTime(query.value(6).toString());
            notif.setQuestionId(query.value(7).toInt());
            notif.setAnswerId(query.value(8).toInt());
            notifications.push_back(notif);

        }
        return notifications;
    }
}

bool Database::update(Question ques)   //更新
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update questions set id=?,title=?,"
                             "userId=?, content=?,"
                             "createtime=?, answerlist=?"
                             " where id=%1").arg(ques.getId()));
    //qDebug()<<ques.getId()<<" "<<ques.getTitle()<<" "<<ques.getUserId()<<" "<<ques.getContent()<<" "<<ques.getTime();
    query.bindValue(0, ques.getId());
    query.bindValue(1, ques.getTitle());
    query.bindValue(2, ques.getUserId());
    query.bindValue(3, ques.getContent());
    query.bindValue(4, ques.getTime());
    //将vector<int>转化成一个字符串存起来
    string answerliststr = vectostr(ques.getAnswerList());
    query.bindValue(5,answerliststr.c_str());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("qustion更新失败"));
          return false;
    }
    return true;
}
bool Database::update(Answer ans)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update answers set id=?,userId=?,"
                             "questionId=?,praisedNum=?,content=?,"
                             "createtime=? where id=%1").arg(ans.getId()));
    //qDebug()<<ans.getId()<<" "<<ans.getUserId()<<" "<<ans.getPraisedNum()<<" "<<ans.getContent()<<" "<<ans.getTime();
    query.bindValue(0, ans.getId());
    query.bindValue(1, ans.getUserId());
    query.bindValue(2, ans.getQuestionId());
    query.bindValue(3, ans.getPraisedNum());
    query.bindValue(4, ans.getContent());
    query.bindValue(5, ans.getTime());

    bool success=query.exec();
    if(!success)
    {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("answer更新失败"));
          return false;
    }
    return true;
}


string vectostr(vector<int>list)
{
    string liststr="";
    string str="";
    char* cstr;
    for(vector<int>::iterator it=list.begin();it!=list.end();++it)
    {
        itoa(*it,cstr,10);
        str = cstr;
        liststr =liststr+str;
        if (it!=list.end()-1)
            liststr =liststr+",";
    }
    return liststr;
}

vector<int> split(QString& str,const char* c)
{
    char *cstr, *p;
    vector<int> res;
    //cstr = new char[str.size()+1];
    //strcpy(cstr,str.c_str());
    QByteArray ba = str.toLatin1();
    cstr = ba.data();
    p = strtok(cstr,c);
    //qDebug()<<"split"<<p;
    while(p!=NULL)
    {
        res.push_back(atoi(p));
        p = strtok(NULL,c);
        //qDebug()<<"split"<<p;
    }
    return res;
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
