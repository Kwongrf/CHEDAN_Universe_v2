<<<<<<< HEAD
#ifndef FOCUSWINDOW_H
#define FOCUSWINDOW_H

#include <QWidget>

namespace Ui {
class FocusWindow;
}

class FocusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FocusWindow(QWidget *parent = 0);
    void showTable(bool type);
    ~FocusWindow();


public slots:
    void onBtnClicked(void);

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::FocusWindow *ui;
};

#endif // FOCUSWINDOW_H
=======
#ifndef FOCUSWINDOW_H
#define FOCUSWINDOW_H

#include <QWidget>

namespace Ui {
class FocusWindow;
}

class FocusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FocusWindow(QWidget *parent = 0);
    void showTable(bool type);
    ~FocusWindow();


public slots:
    void onBtnClicked(void);

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::FocusWindow *ui;
};

#endif // FOCUSWINDOW_H
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
