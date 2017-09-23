<<<<<<< HEAD
#ifndef INVITEDIALOG_H
#define INVITEDIALOG_H

#include <QDialog>

namespace Ui {
class InviteDialog;
}

class InviteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InviteDialog(QWidget *parent = 0);
    ~InviteDialog();
    void showFocus();
    void showFollowed();
    void showAll();

    int getQuestionId();
    void setQuestionId(int id);
private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);



    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();


private:
    Ui::InviteDialog *ui;
    int questionId;
};

#endif // INVITEDIALOG_H
=======
#ifndef INVITEDIALOG_H
#define INVITEDIALOG_H

#include <QDialog>

namespace Ui {
class InviteDialog;
}

class InviteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InviteDialog(QWidget *parent = 0);
    ~InviteDialog();
    void showFocus();
    void showFollowed();
    void showAll();

    int getQuestionId();
    void setQuestionId(int id);
private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);



    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();


private:
    Ui::InviteDialog *ui;
    int questionId;
};

#endif // INVITEDIALOG_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
