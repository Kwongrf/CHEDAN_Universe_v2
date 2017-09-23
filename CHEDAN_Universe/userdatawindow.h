<<<<<<< HEAD
#ifndef USERDATAWINDOW_H
#define USERDATAWINDOW_H

#include "user.h"
#include <QDialog>

namespace Ui {
class UserdataWindow;
}

class UserdataWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserdataWindow(QWidget *parent = 0);
    ~UserdataWindow();
    void showAllDatas();
    void showUserDatas();
    void showQuestions();
    void showAnswers();
    int getUserId();
    void setUserId(int id);

private slots:
    void on_changePassButton_clicked();

    void on_changeNameButton_clicked();


    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_tableWidget_2_doubleClicked(const QModelIndex &index);


    void on_messageButton_clicked();

private:
    Ui::UserdataWindow *ui;
    int userId;
};

#endif // USERDATAWINDOW_H
=======
#ifndef USERDATAWINDOW_H
#define USERDATAWINDOW_H

#include "user.h"
#include <QDialog>

namespace Ui {
class UserdataWindow;
}

class UserdataWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserdataWindow(QWidget *parent = 0);
    ~UserdataWindow();
    void showAllDatas();
    void showUserDatas();
    void showQuestions();
    void showAnswers();
    int getUserId();
    void setUserId(int id);

private slots:
    void on_changePassButton_clicked();

    void on_changeNameButton_clicked();


    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_tableWidget_2_doubleClicked(const QModelIndex &index);


    void on_messageButton_clicked();

private:
    Ui::UserdataWindow *ui;
    int userId;
};

#endif // USERDATAWINDOW_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
