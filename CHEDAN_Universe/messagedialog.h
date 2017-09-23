<<<<<<< HEAD
#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = 0);
    ~MessageDialog();

    int getReceiverId();
    void setReceiverId(int id);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MessageDialog *ui;
    int receiverId;
};

#endif // MESSAGEDIALOG_H
=======
#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = 0);
    ~MessageDialog();

    int getReceiverId();
    void setReceiverId(int id);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MessageDialog *ui;
    int receiverId;
};

#endif // MESSAGEDIALOG_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
