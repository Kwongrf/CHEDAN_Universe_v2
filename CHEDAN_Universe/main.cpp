<<<<<<< HEAD
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMovie>
#include <QSplashScreen>
#include "signin.h"
#include "global.h"
#include <synchapi.h>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    try{
        Db.createConnection();
        Db.createTable();
        Questions = Db.queryAllQues();
        Answers = Db.queryAllAns();
        Users = Db.queryAllUser();
        Notifications = Db.queryAllNotif();
    }
    catch(...)
    {
        qDebug()<<"loading datas error";

    }


    for(vector<Answer>::iterator it= Answers.begin();it!=Answers.end();++it)
    {
        Answer a= *it;
        qDebug()<<a.getId()<<" "<<a.getContent();
    }
    for(vector<Question>::iterator it= Questions.begin();it!=Questions.end();++it)
    {
        Question a= *it;
        qDebug()<<a.getId()<<" "<<a.getContent();
    }
    for(vector<User>::iterator it= Users.begin();it!=Users.end();++it)
    {
        User a= *it;
        qDebug()<<a.getId()<<" "<<a.getName();
    }

    QPixmap pixmap(".//image/1.gif");
    QSplashScreen splash(pixmap);
    splash.setWindowOpacity(0.7);// 设置窗口透明度
    QLabel label(&splash);
    QMovie mv(".//image/1.gif");
    label.setMovie(&mv);
    mv.start();
    splash.show();
    splash.setCursor(Qt::BlankCursor);

    for(int i=0; i<10000; i+=mv.speed())
    {
        QCoreApplication::processEvents();

        Sleep(mv.speed());

    }
    SignIn signInDlg;
    splash.finish(&signInDlg);
    signInDlg.setAutoFillBackground(true);
    QPalette p_signin;
    QPixmap pixmap_signin(".//image/594_492.png");
    p_signin.setBrush(QPalette::Window, QBrush(pixmap_signin));
    signInDlg.setPalette(p_signin);
    if(signInDlg.exec() == QDialog::Accepted)
    {

        w.setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(".//image/bg.jpg");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        w.setPalette(palette);
        w.show();

        w.showQuestions();
        qDebug()<<"ok";
        return a.exec();
    }
    else     
        return 0;

}
=======
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMovie>
#include <QSplashScreen>
#include "signin.h"
#include "global.h"
#include <synchapi.h>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    try{
        Db.createConnection();
        Db.createTable();
        Questions = Db.queryAllQues();
        Answers = Db.queryAllAns();
        Users = Db.queryAllUser();
        Notifications = Db.queryAllNotif();
    }
    catch(...)
    {
        qDebug()<<"loading datas error";

    }


    for(vector<Answer>::iterator it= Answers.begin();it!=Answers.end();++it)
    {
        Answer a= *it;
        qDebug()<<a.getId()<<" "<<a.getContent();
    }
    for(vector<Question>::iterator it= Questions.begin();it!=Questions.end();++it)
    {
        Question a= *it;
        qDebug()<<a.getId()<<" "<<a.getContent();
    }
    for(vector<User>::iterator it= Users.begin();it!=Users.end();++it)
    {
        User a= *it;
        qDebug()<<a.getId()<<" "<<a.getName();
    }

    QPixmap pixmap(".//image/1.gif");
    QSplashScreen splash(pixmap);
    splash.setWindowOpacity(0.7);// 设置窗口透明度
    QLabel label(&splash);
    QMovie mv(".//image/1.gif");
    label.setMovie(&mv);
    mv.start();
    splash.show();
    splash.setCursor(Qt::BlankCursor);

    for(int i=0; i<10000; i+=mv.speed())
    {
        QCoreApplication::processEvents();

        Sleep(mv.speed());

    }
    SignIn signInDlg;
    splash.finish(&signInDlg);
    signInDlg.setAutoFillBackground(true);
    QPalette p_signin;
    QPixmap pixmap_signin(".//image/594_492.png");
    p_signin.setBrush(QPalette::Window, QBrush(pixmap_signin));
    signInDlg.setPalette(p_signin);
    if(signInDlg.exec() == QDialog::Accepted)
    {

        w.setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(".//image/bg.jpg");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        w.setPalette(palette);
        w.show();

        w.showQuestions();
        qDebug()<<"ok";
        return a.exec();
    }
    else     
        return 0;

}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
