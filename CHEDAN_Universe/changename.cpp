<<<<<<< HEAD
#include "changename.h"
#include "ui_changename.h"
#include "global.h"
ChangeName::ChangeName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeName)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ChangeName::~ChangeName()
{
    delete ui;
}

void ChangeName::on_buttonBox_accepted()
{
    QString newName = ui->lineEdit->text();
    USER.setName(newName);
    Global::update(USER);
}

void ChangeName::on_buttonBox_rejected()
{
    this->close();
}
=======
#include "changename.h"
#include "ui_changename.h"
#include "global.h"
ChangeName::ChangeName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeName)
{
    ui->setupUi(this);
    QPalette pallete;
    QPixmap pixmap(".//image/small.png");
    pallete.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette( pallete);
}

ChangeName::~ChangeName()
{
    delete ui;
}

void ChangeName::on_buttonBox_accepted()
{
    QString newName = ui->lineEdit->text();
    USER.setName(newName);
    Global::update(USER);
}

void ChangeName::on_buttonBox_rejected()
{
    this->close();
}
>>>>>>> cfdf638c3bdfa8efdbbb0c911ad54fe243c63989
