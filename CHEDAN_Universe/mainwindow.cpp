<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "question.h"
#include "quesanswindow.h"
#include "ask.h"
#include "userdatawindow.h"
#include "signin.h"
#include "focuswindow.h"
#include "searchresult.h"
#include "noticewindow.h"
#include <QMessageBox>
#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1140,640);
    this->setFixedSize(1140,640);

    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showQuestions()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("题主")<<tr("回答数")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    //ui->tableWidget->show();

    //vector<Question> questions = Db.queryAllQues();
//    int flag=0;
//    int row = 0;
//    for(vector<Question>::reverse_iterator rit = Questions.rbegin();rit!=Questions.rend();++rit)
//    {
//        Question ques = *rit;
//        ui->tableWidget->setRowCount(row+1);
//        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ques.getId())));
//        ui->tableWidget->setItem(row,1,new QTableWidgetItem(ques.getTitle()));
//        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Global::getUser(ques.getUserId()).getName()));
//        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ques.getAnswerList().size())));
//        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ques.getTime()));

//        //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
//        row++;
//        flag=1;
//    }

//    for(int row = 0;row < Questions.size();row++)
//    {
//        for(int col = 0;col<5;col++)
//            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
//    }

//    if(flag==0)
//         ui->tableWidget->setRowCount(0);
//    ui->tableWidget->show();

    //实现分页
   this->on_homepageButton_clicked();

    int max = Questions.size()/10+1;
    int min = 1;
    //设置QLineEdit只能输入数字
    QIntValidator* validator = new QIntValidator(min,max,this);
    ui->pageNum->setValidator(validator);

}




void MainWindow::on_askQuesButton_clicked()
{
    Ask askDlg;
    askDlg.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg3.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    askDlg.setPalette(palette);
    if(askDlg.exec() ==  QDialog::Accepted)
    {
        this->showQuestions();
    }
}


void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    QuesAnsWindow *quesansWindow = new QuesAnsWindow;

    quesansWindow->show();
    quesansWindow->showQuesAnswers(id);
}

void MainWindow::on_searchButton_clicked()
{
    QString searchStr = ui->searchEdit->text();
    if(searchStr!="")
    {
        SearchResult *sr = new SearchResult;
        sr->search(searchStr);
        sr->exec();
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入搜索内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }


}
void MainWindow::on_searchButton_2_clicked()
{
    QDate date = ui->dateEdit->date();
    //QDateTime t = QDateTime::fromString(searchStr,"yyyy-MM-dd");
    SearchResult *sr = new SearchResult;
    sr->search(date);
    sr->exec();
}

void MainWindow::on_userDataButton_clicked()
{
    UserdataWindow userdataWindow;//实际上是Dialog

    USER = Global::getUser(USER.getId());//更新USER
    userdataWindow.setUserId(USER.getId());
    userdataWindow.showAllDatas();
    userdataWindow.exec();
}

void MainWindow::on_freshButton_clicked()
{
    this->showQuestions();
}

void MainWindow::on_signoutButton_clicked()
{
    QMessageBox box (QMessageBox::NoIcon,tr("注销"),tr("确定注销?"),QMessageBox::Yes|QMessageBox::No,this);
    box.setIconPixmap(QPixmap(".//image/signout.png"));
    QIcon icon(".//image/out.ico");
    box.setWindowIcon(icon);
    box.setButtonText(QMessageBox::Yes,QString("确定"));
    box.setButtonText(QMessageBox::No,QString("取消"));
    if(box.exec()==QMessageBox::Yes)
    {
        this->hide();
        SignIn signin;
        signin.setAutoFillBackground(true);
        QPalette p_signin;
        QPixmap pixmap_signin(".//image/594_492.png");
        p_signin.setBrush(QPalette::Window, QBrush(pixmap_signin));
        signin.setPalette(p_signin);
        signin.show();

        if(signin.exec()==QDialog::Accepted)
          this->show();
        else
          this->close();
    }
}

void MainWindow::on_focusButton_clicked()
{
     FocusWindow* fw = new FocusWindow;//这里坑！！
     qDebug()<<"0";

     fw->setAutoFillBackground(true);
     QPalette pallete;
     QPixmap pixmap(".//image/bg7.jpg");
     pallete.setBrush(QPalette::Window, QBrush(pixmap));
     fw->setPalette( pallete);qDebug()<<"21";
     fw->show();qDebug()<<"22";
     fw->showTable(1);qDebug()<<"23";
     qDebug()<<"20";
}

void MainWindow::on_followedButton_clicked()
{
    FocusWindow* fw = new FocusWindow;//这里坑！！
    qDebug()<<"0";

    fw->setAutoFillBackground(true);
    QPalette pallete;
    QPixmap pixmap(".//image/bg7.jpg");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    fw->setPalette( pallete);qDebug()<<"21";
    fw->show();qDebug()<<"22";
    fw->showTable(0);qDebug()<<"23";
    qDebug()<<"20";
}

void MainWindow::on_homepageButton_clicked()
{
    qrit = Questions.rbegin();

    this->on_nextpageButton_clicked();
    page = 1;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"homepage";
}

void MainWindow::on_lastpageButton_clicked()
{
    if (qrit!=Questions.rend())
        qrit-=10;
    else
    {
        int n = Questions.size()%10;
        qrit-=10+n;
    }

    this->on_nextpageButton_clicked();
    if(page>1)
        page--;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"lastpage";
}

void MainWindow::on_nextpageButton_clicked()
{
    int row=0;
    while(qrit!=Questions.rend()&&row<10)
    {
        Question ques = *qrit;
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ques.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(ques.getTitle()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Global::getUser(ques.getUserId()).getName()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ques.getAnswerList().size())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ques.getTime()));
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
        row++;
        qrit++;
    }
    ui->tableWidget->show();
    if(qrit!=Questions.rend())
    {
        page++;
        ui->pageNum->setText(QString::number(page));
        qDebug()<<"nextpage";
    }
}

void MainWindow::on_endpageButton_clicked()
{
    int p = Questions.size()/10;
    qrit = Questions.rbegin();
    qrit+=10*p;
    this->on_nextpageButton_clicked();
    page = p+1;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"endpage";

}

void MainWindow::on_gotopageButton_clicked()
{
    bool* ok = NULL;
    QString pst = ui->pageNum->text();
    int p = pst.toInt(ok,10);
    qrit = Questions.rbegin();
    qrit+=10*(p-1);
    this->on_nextpageButton_clicked();
    page = p;
    ui->pageNum->setText(QString::number(page));

}



void MainWindow::on_noticeButton_clicked()
{
    NoticeWindow *nw = new NoticeWindow;
    nw->show();
}
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "question.h"
#include "quesanswindow.h"
#include "ask.h"
#include "userdatawindow.h"
#include "signin.h"
#include "focuswindow.h"
#include "searchresult.h"
#include "noticewindow.h"
#include <QMessageBox>
#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1140,640);
    this->setFixedSize(1140,640);

    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showQuestions()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFont(QFont("微软雅黑", 10, QFont::Bold ));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<tr("ID")<<tr("问题")<<tr("题主")<<tr("回答数")<<tr("时间");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    //ui->tableWidget->show();

    //vector<Question> questions = Db.queryAllQues();
//    int flag=0;
//    int row = 0;
//    for(vector<Question>::reverse_iterator rit = Questions.rbegin();rit!=Questions.rend();++rit)
//    {
//        Question ques = *rit;
//        ui->tableWidget->setRowCount(row+1);
//        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ques.getId())));
//        ui->tableWidget->setItem(row,1,new QTableWidgetItem(ques.getTitle()));
//        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Global::getUser(ques.getUserId()).getName()));
//        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ques.getAnswerList().size())));
//        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ques.getTime()));

//        //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
//        row++;
//        flag=1;
//    }

//    for(int row = 0;row < Questions.size();row++)
//    {
//        for(int col = 0;col<5;col++)
//            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
//    }

//    if(flag==0)
//         ui->tableWidget->setRowCount(0);
//    ui->tableWidget->show();

    //实现分页
   this->on_homepageButton_clicked();

    int max = Questions.size()/10+1;
    int min = 1;
    //设置QLineEdit只能输入数字
    QIntValidator* validator = new QIntValidator(min,max,this);
    ui->pageNum->setValidator(validator);

}




void MainWindow::on_askQuesButton_clicked()
{
    Ask askDlg;
    askDlg.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(".//image/bg3.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    askDlg.setPalette(palette);
    if(askDlg.exec() ==  QDialog::Accepted)
    {
        this->showQuestions();
    }
}


void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    bool* ok = NULL;
    int id =ui->tableWidget->item(index.row(),0)->text().toInt(ok,10);

    QuesAnsWindow *quesansWindow = new QuesAnsWindow;

    quesansWindow->show();
    quesansWindow->showQuesAnswers(id);
}

void MainWindow::on_searchButton_clicked()
{
    QString searchStr = ui->searchEdit->text();
    if(searchStr!="")
    {
        SearchResult *sr = new SearchResult;
        sr->search(searchStr);
        sr->exec();
    }
    else
    {
        QMessageBox fail(QMessageBox::NoIcon, "失败", "请输入搜索内容");
        fail.addButton("确定", QMessageBox::AcceptRole);
        fail.exec();
    }


}
void MainWindow::on_searchButton_2_clicked()
{
    QDate date = ui->dateEdit->date();
    //QDateTime t = QDateTime::fromString(searchStr,"yyyy-MM-dd");
    SearchResult *sr = new SearchResult;
    sr->search(date);
    sr->exec();
}

void MainWindow::on_userDataButton_clicked()
{
    UserdataWindow userdataWindow;//实际上是Dialog

    USER = Global::getUser(USER.getId());//更新USER
    userdataWindow.setUserId(USER.getId());
    userdataWindow.showAllDatas();
    userdataWindow.exec();
}

void MainWindow::on_freshButton_clicked()
{
    this->showQuestions();
}

void MainWindow::on_signoutButton_clicked()
{
    QMessageBox box (QMessageBox::NoIcon,tr("注销"),tr("确定注销?"),QMessageBox::Yes|QMessageBox::No,this);
    box.setIconPixmap(QPixmap(".//image/signout.png"));
    QIcon icon(".//image/out.ico");
    box.setWindowIcon(icon);
    box.setButtonText(QMessageBox::Yes,QString("确定"));
    box.setButtonText(QMessageBox::No,QString("取消"));
    if(box.exec()==QMessageBox::Yes)
    {
        this->hide();
        SignIn signin;
        signin.setAutoFillBackground(true);
        QPalette p_signin;
        QPixmap pixmap_signin(".//image/594_492.png");
        p_signin.setBrush(QPalette::Window, QBrush(pixmap_signin));
        signin.setPalette(p_signin);
        signin.show();

        if(signin.exec()==QDialog::Accepted)
          this->show();
        else
          this->close();
    }
}

void MainWindow::on_focusButton_clicked()
{
     FocusWindow* fw = new FocusWindow;//这里坑！！
     qDebug()<<"0";

     fw->setAutoFillBackground(true);
     QPalette pallete;
     QPixmap pixmap(".//image/bg7.jpg");
     pallete.setBrush(QPalette::Window, QBrush(pixmap));
     fw->setPalette( pallete);qDebug()<<"21";
     fw->show();qDebug()<<"22";
     fw->showTable(1);qDebug()<<"23";
     qDebug()<<"20";
}

void MainWindow::on_followedButton_clicked()
{
    FocusWindow* fw = new FocusWindow;//这里坑！！
    qDebug()<<"0";

    fw->setAutoFillBackground(true);
    QPalette pallete;
    QPixmap pixmap(".//image/bg7.jpg");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    fw->setPalette( pallete);qDebug()<<"21";
    fw->show();qDebug()<<"22";
    fw->showTable(0);qDebug()<<"23";
    qDebug()<<"20";
}

void MainWindow::on_homepageButton_clicked()
{
    qrit = Questions.rbegin();

    this->on_nextpageButton_clicked();
    page = 1;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"homepage";
}

void MainWindow::on_lastpageButton_clicked()
{
    if (qrit!=Questions.rend())
        qrit-=10;
    else
    {
        int n = Questions.size()%10;
        qrit-=10+n;
    }

    this->on_nextpageButton_clicked();
    if(page>1)
        page--;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"lastpage";
}

void MainWindow::on_nextpageButton_clicked()
{
    int row=0;
    while(qrit!=Questions.rend()&&row<10)
    {
        Question ques = *qrit;
        ui->tableWidget->setRowCount(row+1);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(ques.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(ques.getTitle()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Global::getUser(ques.getUserId()).getName()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(ques.getAnswerList().size())));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ques.getTime()));
        for(int col = 0;col<5;col++)
            ui->tableWidget->item(row,col)->setTextColor(QColor(220,220,220));
        //qDebug()<<QString::number(ques.getId())<<" "<<ques.getTitle()<<" "<<ques.getTime()<<" "<<row;
        row++;
        qrit++;
    }
    ui->tableWidget->show();
    if(qrit!=Questions.rend())
    {
        page++;
        ui->pageNum->setText(QString::number(page));
        qDebug()<<"nextpage";
    }
}

void MainWindow::on_endpageButton_clicked()
{
    int p = Questions.size()/10;
    qrit = Questions.rbegin();
    qrit+=10*p;
    this->on_nextpageButton_clicked();
    page = p+1;
    ui->pageNum->setText(QString::number(page));
    qDebug()<<"endpage";

}

void MainWindow::on_gotopageButton_clicked()
{
    bool* ok = NULL;
    QString pst = ui->pageNum->text();
    int p = pst.toInt(ok,10);
    qrit = Questions.rbegin();
    qrit+=10*(p-1);
    this->on_nextpageButton_clicked();
    page = p;
    ui->pageNum->setText(QString::number(page));

}



void MainWindow::on_noticeButton_clicked()
{
    NoticeWindow *nw = new NoticeWindow;
    nw->show();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
