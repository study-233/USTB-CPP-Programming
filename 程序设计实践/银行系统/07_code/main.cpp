//main.cpp
#include "login.h"
#include <QApplication>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#define  endl '\n'

int main(int argc, char *argv[])
{
    //创建数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名字
    db.setDatabaseName("login.db");
    //打开数据库
    if(db.open())
    {
        qDebug()<<"打开数据库成功"<<endl;
    }else
    {
        qDebug()<<"打开数据库失败"<<endl;
    }

    //创建一个存储user和密码的的数据库表
    QString cmd = "create table if not exists userinfo(username varchar(64),password varchar(64))";

    //执行sql语句
    QSqlQuery query;
    if(query.exec(cmd))
    {
        qDebug()<<"创建成功"<<endl;
    }else
    {
        qDebug()<<"创建失败"<<endl;
    }

    QApplication a(argc, argv);
    Login w;
    //打开登录界面
    w.show();
    return a.exec();
}
