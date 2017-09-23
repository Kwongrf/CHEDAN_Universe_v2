<<<<<<< HEAD
#ifndef CHANGEPROFILE_H
#define CHANGEPROFILE_H

#include <QDialog>

namespace Ui {
class ChangeProfile;
}

class ChangeProfile : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeProfile(QWidget *parent = 0);
    ~ChangeProfile();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeProfile *ui;
};

#endif // CHANGEPROFILE_H
=======
#ifndef CHANGEPROFILE_H
#define CHANGEPROFILE_H

#include <QDialog>

namespace Ui {
class ChangeProfile;
}

class ChangeProfile : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeProfile(QWidget *parent = 0);
    ~ChangeProfile();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeProfile *ui;
};

#endif // CHANGEPROFILE_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
