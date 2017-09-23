<<<<<<< HEAD
#ifndef NOTICEWINDOW_H
#define NOTICEWINDOW_H

#include <QWidget>
#include <vector>
namespace Ui {
class NoticeWindow;
}

class NoticeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeWindow(QWidget *parent = 0);
    ~NoticeWindow();
    void showNotice();

private slots:


    void on_noticeButton_toggled(bool checked);

    void on_praiseButton_toggled(bool checked);

    void on_focusButton_toggled(bool checked);

    void on_messageButton_toggled(bool checked);


    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::NoticeWindow *ui;
};

#endif // NOTICEWINDOW_H
=======
#ifndef NOTICEWINDOW_H
#define NOTICEWINDOW_H

#include <QWidget>
#include <vector>
namespace Ui {
class NoticeWindow;
}

class NoticeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeWindow(QWidget *parent = 0);
    ~NoticeWindow();
    void showNotice();

private slots:


    void on_noticeButton_toggled(bool checked);

    void on_praiseButton_toggled(bool checked);

    void on_focusButton_toggled(bool checked);

    void on_messageButton_toggled(bool checked);


    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::NoticeWindow *ui;
};

#endif // NOTICEWINDOW_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
