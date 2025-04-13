//login.h
#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"

#include <QWidget>
using namespace std;

namespace Ui {
class login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_Login_clicked();

    void on_Sign_clicked();

private:
    Ui::login *ui;
    MainWindow *s;

};

#endif // LOGIN_H
