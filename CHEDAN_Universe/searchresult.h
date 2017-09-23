<<<<<<< HEAD
#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QDialog>
#include "question.h"
#include "answer.h"
#include "user.h"
namespace Ui {
class SearchResult;
}

class SearchResult : public QDialog
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = 0);
    ~SearchResult();
    bool search(QString str);
    bool search(Question q);
    bool search(Answer a);
    bool search(User u);
    bool search(QDate d);

private:
    Ui::SearchResult *ui;
};

#endif // SEARCHRESULT_H
=======
#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QDialog>
#include "question.h"
#include "answer.h"
#include "user.h"
namespace Ui {
class SearchResult;
}

class SearchResult : public QDialog
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = 0);
    ~SearchResult();
    bool search(QString str);
    bool search(Question q);
    bool search(Answer a);
    bool search(User u);
    bool search(QDate d);

private:
    Ui::SearchResult *ui;
};

#endif // SEARCHRESULT_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
