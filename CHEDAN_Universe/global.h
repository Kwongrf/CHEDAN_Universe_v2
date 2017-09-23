<<<<<<< HEAD
#ifndef GLOBAL_H
#define GLOBAL_H

#include "database.h"
#include <vector>
using namespace std;


class Global
{
public:
    Global();
    static User getUser(int id);
    static Question getQuestion(int id);
    static Answer getAnswer(int id);
    static Notification getNotification(int id);

    static void update(User user);
    static void update(Question ques);
    static void update(Answer ans);

    static void insert(User user);
    static void insert(Question ques);
    static void insert(Answer ans);
    static void insert(Notification notif);

};

extern Database Db;
extern User USER;
extern vector<Question> Questions;
extern vector<Answer> Answers;
extern vector<User> Users;
extern vector<Notification> Notifications;
#endif // GLOBAL_H
=======
#ifndef GLOBAL_H
#define GLOBAL_H

#include "database.h"
#include <vector>
using namespace std;


class Global
{
public:
    Global();
    static User getUser(int id);
    static Question getQuestion(int id);
    static Answer getAnswer(int id);
    static Notification getNotification(int id);

    static void update(User user);
    static void update(Question ques);
    static void update(Answer ans);

    static void insert(User user);
    static void insert(Question ques);
    static void insert(Answer ans);
    static void insert(Notification notif);

};

extern Database Db;
extern User USER;
extern vector<Question> Questions;
extern vector<Answer> Answers;
extern vector<User> Users;
extern vector<Notification> Notifications;
#endif // GLOBAL_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
