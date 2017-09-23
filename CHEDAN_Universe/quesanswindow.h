<<<<<<< HEAD
#ifndef QUESANSWINDOW_H
#define QUESANSWINDOW_H

#include <QWidget>
#include "question.h"
#include "user.h"
#include "answer.h"
#include <vector>
namespace Ui {
class QuesAnsWindow;
}

class QuesAnsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QuesAnsWindow(QWidget *parent = 0);
    ~QuesAnsWindow();

    void showQuesAnswers(int id);
    void freshTable();
    void setAsker(User user);
    void setQuestion(Question question);
    void setAnswers(vector<Answer> answers);
    void setAnswerer(User user);
    void setCurAnswer(Answer ans);
    User getAnswerer();
    Answer getCurAnswer();
    vector<Answer> getAnswers();
    User getAsker();
    Question getQuestion();

    void showAnswer(int id);

private slots:
    void on_answerQuesButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    //void on_praiseButton_toggled(bool checked);

    //void on_focusTZButton_toggled(bool checked);

   // void on_focusDZButton_toggled(bool checked);

    void on_freshButton_clicked();

    //void on_praiseButton_clicked(bool checked);

    void on_praiseButton_clicked();

    void on_focusTZButton_clicked();

    void on_focusDZButton_clicked();

    void on_inviteButton_clicked();

    void on_aboutTZButton_clicked();

    void on_aboutDZButton_clicked();

    void on_commentButton_clicked();

private:
    Ui::QuesAnsWindow *ui;

    User asker;
    User answerer;
    Answer curAnswer;
    Question question;
    vector<Answer> answers;
};

#endif // QUESANSWINDOW_H
=======
#ifndef QUESANSWINDOW_H
#define QUESANSWINDOW_H

#include <QWidget>
#include "question.h"
#include "user.h"
#include "answer.h"
#include <vector>
namespace Ui {
class QuesAnsWindow;
}

class QuesAnsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QuesAnsWindow(QWidget *parent = 0);
    ~QuesAnsWindow();

    void showQuesAnswers(int id);
    void freshTable();
    void setAsker(User user);
    void setQuestion(Question question);
    void setAnswers(vector<Answer> answers);
    void setAnswerer(User user);
    void setCurAnswer(Answer ans);
    User getAnswerer();
    Answer getCurAnswer();
    vector<Answer> getAnswers();
    User getAsker();
    Question getQuestion();

    void showAnswer(int id);

private slots:
    void on_answerQuesButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    //void on_praiseButton_toggled(bool checked);

    //void on_focusTZButton_toggled(bool checked);

   // void on_focusDZButton_toggled(bool checked);

    void on_freshButton_clicked();

    //void on_praiseButton_clicked(bool checked);

    void on_praiseButton_clicked();

    void on_focusTZButton_clicked();

    void on_focusDZButton_clicked();

    void on_inviteButton_clicked();

    void on_aboutTZButton_clicked();

    void on_aboutDZButton_clicked();

    void on_commentButton_clicked();

private:
    Ui::QuesAnsWindow *ui;

    User asker;
    User answerer;
    Answer curAnswer;
    Question question;
    vector<Answer> answers;
};

#endif // QUESANSWINDOW_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
