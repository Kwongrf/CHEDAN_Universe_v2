<<<<<<< HEAD
#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QDialog>

namespace Ui {
class ChangeName;
}

class ChangeName : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeName(QWidget *parent = 0);
    ~ChangeName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeName *ui;
};

#endif // CHANGENAME_H
=======
#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QDialog>

namespace Ui {
class ChangeName;
}

class ChangeName : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeName(QWidget *parent = 0);
    ~ChangeName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeName *ui;
};

#endif // CHANGENAME_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
