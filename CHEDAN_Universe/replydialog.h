<<<<<<< HEAD
#ifndef REPLYDIALOG_H
#define REPLYDIALOG_H
#include "notification.h"
#include <QDialog>

namespace Ui {
class ReplyDialog;
}

class ReplyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplyDialog(QWidget *parent = 0);
    ~ReplyDialog();

    void setNotif(Notification notif);
    Notification getNotif();
    void showMessage();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ReplyDialog *ui;
    Notification notif;
};

#endif // REPLYDIALOG_H
=======
#ifndef REPLYDIALOG_H
#define REPLYDIALOG_H
#include "notification.h"
#include <QDialog>

namespace Ui {
class ReplyDialog;
}

class ReplyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplyDialog(QWidget *parent = 0);
    ~ReplyDialog();

    void setNotif(Notification notif);
    Notification getNotif();
    void showMessage();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ReplyDialog *ui;
    Notification notif;
};

#endif // REPLYDIALOG_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
