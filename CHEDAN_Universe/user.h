<<<<<<< HEAD
#ifndef USER_H
#define USER_H


#include <QString>
#include <vector>

using namespace std;

class User
{
public:
    User();

    int getId();
    void setId(int id);
    QString getName();
    void setName(QString name);
    QString getPassword();
    void setPassword(QString password);
    int getPraisedNum();
    void setPraisedNum(int n);
    vector<int> getFocusList();
    void setFocusList(vector<int> focuslist);
    void handleFocusList(int id,bool method);
    vector<int> getFollowedList();
    void setFollowedList(vector<int> followedlist);
    void handleFollowedList(int id,bool method);
    vector<int> getPraiseList();
    void setPraiseList(vector<int> praiselist);
    void handlePraiseList(int id,bool method);

    vector<int> getAnswerList();
    void setAnswerList(vector<int> answerlist);
    void handleAnswerList(int id,bool method);
    vector<int> getAskList();
    void setAskList(vector<int>asklist);
    void handleAskList(int id,bool method);


private:
    int id;
    QString name;
    QString password;
    int praisedNum;
    vector<int> focuslist;//只存放id
    vector<int> followedlist;
    vector<int> praiselist;
    vector<int> answerlist;
    vector<int> asklist;

};

#endif // USER_H
=======
#ifndef USER_H
#define USER_H


#include <QString>
#include <vector>

using namespace std;

class User
{
public:
    User();

    int getId();
    void setId(int id);
    QString getName();
    void setName(QString name);
    QString getPassword();
    void setPassword(QString password);
    int getPraisedNum();
    void setPraisedNum(int n);
    vector<int> getFocusList();
    void setFocusList(vector<int> focuslist);
    void handleFocusList(int id,bool method);
    vector<int> getFollowedList();
    void setFollowedList(vector<int> followedlist);
    void handleFollowedList(int id,bool method);
    vector<int> getPraiseList();
    void setPraiseList(vector<int> praiselist);
    void handlePraiseList(int id,bool method);

    vector<int> getAnswerList();
    void setAnswerList(vector<int> answerlist);
    void handleAnswerList(int id,bool method);
    vector<int> getAskList();
    void setAskList(vector<int>asklist);
    void handleAskList(int id,bool method);


private:
    int id;
    QString name;
    QString password;
    int praisedNum;
    vector<int> focuslist;//只存放id
    vector<int> followedlist;
    vector<int> praiselist;
    vector<int> answerlist;
    vector<int> asklist;

};

#endif // USER_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
