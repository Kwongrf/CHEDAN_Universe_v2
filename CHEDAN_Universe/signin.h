<<<<<<< HEAD
#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();

private slots:
    void on_signInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
=======
#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();

private slots:
    void on_signInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
