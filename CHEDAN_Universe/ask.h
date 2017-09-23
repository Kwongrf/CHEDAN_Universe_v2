<<<<<<< HEAD
#ifndef ASK_H
#define ASK_H

#include <QDialog>

namespace Ui {
class Ask;
}

class Ask : public QDialog
{
    Q_OBJECT

public:
    explicit Ask(QWidget *parent = 0);
    ~Ask();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Ask *ui;
};

#endif // ASK_H
=======
#ifndef ASK_H
#define ASK_H

#include <QDialog>

namespace Ui {
class Ask;
}

class Ask : public QDialog
{
    Q_OBJECT

public:
    explicit Ask(QWidget *parent = 0);
    ~Ask();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Ask *ui;
};

#endif // ASK_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
