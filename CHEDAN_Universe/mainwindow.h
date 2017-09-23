<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
#include "global.h"
#include "quesanswindow.h"
#include "ask.h"
#include "userdatawindow.h"
#include <vector>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showQuestions();

private slots:
    void on_askQuesButton_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_searchButton_clicked();

    void on_userDataButton_clicked();

    void on_freshButton_clicked();

    void on_signoutButton_clicked();

    void on_focusButton_clicked();

    void on_homepageButton_clicked();

    void on_lastpageButton_clicked();

    void on_nextpageButton_clicked();

    void on_endpageButton_clicked();

    void on_gotopageButton_clicked();

    void on_searchButton_2_clicked();

    void on_followedButton_clicked();

    void on_noticeButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Question>::reverse_iterator qrit;
    int page;
};

#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
#include "global.h"
#include "quesanswindow.h"
#include "ask.h"
#include "userdatawindow.h"
#include <vector>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showQuestions();

private slots:
    void on_askQuesButton_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_searchButton_clicked();

    void on_userDataButton_clicked();

    void on_freshButton_clicked();

    void on_signoutButton_clicked();

    void on_focusButton_clicked();

    void on_homepageButton_clicked();

    void on_lastpageButton_clicked();

    void on_nextpageButton_clicked();

    void on_endpageButton_clicked();

    void on_gotopageButton_clicked();

    void on_searchButton_2_clicked();

    void on_followedButton_clicked();

    void on_noticeButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Question>::reverse_iterator qrit;
    int page;
};

#endif // MAINWINDOW_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
