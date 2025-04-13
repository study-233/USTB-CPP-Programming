//登录注册
//login.cpp
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMovie>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#define  endl '\n'

extern QString User;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

//登录
void Login::on_Login_clicked()
{
    QString username = this->ui->lineEdit_user->text();
    QString password = this->ui->lineEdit_pass->text();
    //创建model
    QSqlTableModel *model = new QSqlTableModel;
    //绑定表
    model->setTable("userinfo");
    //过滤数据
    model->setFilter(QString("username='%1' and password='%2'").arg(username,password));
    //查询
    model->select();
    //结果
    int row = model->rowCount();
    User = username;
    s = new MainWindow;
    if(row>0){
        qDebug()<<"登录成功"<<endl;
        //打开主界面
        s->show();
        this->hide();
    }
    else{
        QMessageBox::about(NULL,"","用户名或密码错误");
        s->deleteLater();
        qDebug()<<"登录失败"<<endl;
    }

}

//注册
void Login::on_Sign_clicked()
{
    QString username = this->ui->lineEdit_user->text();
    QString password = this->ui->lineEdit_pass->text();
    QSqlQuery query;

    query.prepare("select username from userinfo where username=:username");
    query.bindValue(":username", username);
    query.exec();

    if(query.next())
    {
        QMessageBox::about(NULL,"警告","账号已注册");
    }
    else{
        QString cmd = QString("insert into userinfo(username,password)values('%1','%2')").arg(username,password);
        query.exec(cmd);
        //qDebug()<<"insert suc"<<endl;
    }

}

