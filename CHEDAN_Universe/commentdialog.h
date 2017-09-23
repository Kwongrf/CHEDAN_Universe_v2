<<<<<<< HEAD
#ifndef COMMENTDIALOG_H
#define COMMENTDIALOG_H

#include <QDialog>

namespace Ui {
class CommentDialog;
}

class CommentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommentDialog(QWidget *parent = 0);
    ~CommentDialog();

    void showComments();

    void setAnswerId(int id);
    int getAnswerId();

    void setAnswererId(int id);
    int getAnswererId();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CommentDialog *ui;

    int answerId;
    int answererId;

};

#endif // COMMENTDIALOG_H
=======
#ifndef COMMENTDIALOG_H
#define COMMENTDIALOG_H

#include <QDialog>

namespace Ui {
class CommentDialog;
}

class CommentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommentDialog(QWidget *parent = 0);
    ~CommentDialog();

    void showComments();

    void setAnswerId(int id);
    int getAnswerId();

    void setAnswererId(int id);
    int getAnswererId();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CommentDialog *ui;

    int answerId;
    int answererId;

};

#endif // COMMENTDIALOG_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
