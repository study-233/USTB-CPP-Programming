//mainwindow.cpp
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "date.h"
#include "account.h"
#include "savingaccount.h"
#include "creditaccount.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QStylePainter>
#include <QStylePainter>

// 全局变量
QString User; // 用户名
Date date(2008, 11, 1); // 起始日期
vector<Account *> accounts; // 创建账户数组，初始元素个数为0

char cmd,type;
int index_, day;
double amount, credit, rate, fee;
string user, id, desc;
Account* account;
Date date1, date2;
ofstream ofs;

QString account_input[5];
QString change_input[3];
int day_change=0;
Date d1 ,d2;
MainWindow *MainWindow::my = nullptr;

// 文件存储格式
// User cmd ...

//读取命令
void MainWindow::read_cmd(){
    ifstream ifs;
    ifs.open("commands.txt");
    if(!ifs.is_open()){
        qDebug()<<"无法打开文件";
        return;
    }
    while(ifs>>cmd){
        switch (cmd) {
        case 'a'://增加账户
            ifs >> user >> type >> id;
            if (type == 's') {
                ifs >> rate;
                account = new SavingsAccount(date, id, user ,rate);
            }
            else {
                ifs >> credit >> rate >> fee;
                account = new CreditAccount(date, id, user, credit, rate, fee);
            }
            accounts.push_back(account);
            my->ui->comboBox_account_1->addItem(QString::fromStdString(id));
            my->ui->comboBox_account_2->addItem(QString::fromStdString(id));

            break;

        case 'd'://存入现金
            ifs >> index_ >> amount;
            getline(ifs,desc);
            accounts[index_]->deposit(date, amount, desc);
            break;

        case 'w'://取出现金
            ifs >> index_ >> amount ;
            getline(ifs,desc);
            accounts[index_]->withdraw(date, amount, desc);
            break;


        case 'c'://改变日期
            ifs >> day;
            date = Date(date.getYear(), date.getMonth(), day);
            break;

        case 'n'://进入下个月

            if (date.getMonth() == 12)
                date = Date(date.getYear() + 1, 1, 1);
            else
                date = Date(date.getYear(), date.getMonth() + 1, 1);
            for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
                (*iter)->settle(date);
            break;

        }
    }
    ifs.close();
}

struct deleter {
    template <class T> void operator () (T* p) { delete p; }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindows)
{
    ui->setupUi(this);
    my = this;
    //设置欢迎语
    QString theHello = "欢迎用户\t"+ User;
    ui->label->setText(theHello);

    //读取文件
    read_cmd();
    //显示提示信息
    show_alert();
    //刷新日期
    refreshdate();
    //写入文件初始化
    ofs.open("commands.txt",ios::app);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//处理命令
void MainWindow::cmdprocess(char cmd){

    //date.show();
    //cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";


    switch (cmd) {
    case 'a'://增加账户
        try{
            // cin >> type >> id;
            type = account_input[0].toStdString().c_str()[0];
            user = User.toStdString();
            id = account_input[1].toStdString();

            if(type == 's' || type == 'c'){
                ofs << endl << cmd << " " << user << " ";
                ofs << type << " " << id << " ";
            }
            else throw runtime_error("账户类型错误");
        }
        catch (runtime_error& err) {
            //cout << err.what() << endl;
        }

        if (type == 's') {
            // cin >> rate;
            rate = account_input[3].toDouble();
            ofs<<rate;
            account = new SavingsAccount(date, id, user, rate);
        }
        else {
            // cin >> credit >> rate >> fee;
            credit = account_input[2].toDouble();
            rate = account_input[3].toDouble();
            fee = account_input[4].toDouble();

            ofs<<credit<<" "<<rate<<" "<<fee;
            account = new CreditAccount(date, id, user, credit, rate, fee);
        }
        //qDebug()<<"here\n";
        if(user == User.toStdString()){ // 用户过滤
            my->ui->textBrowser_output->append(User+ "的"+ QString::fromStdString(id)+ "账号已创建.");
            my->ui->comboBox_account_1->addItem(QString::fromStdString(id));
            my->ui->comboBox_account_2->addItem(QString::fromStdString(id));
            accounts.push_back(account);
        }


        break;

    case 'd'://存入现金
        try{
            // cin >> index_ >> amount;
            index_ = change_input[0].toInt();
            amount = change_input[1].toDouble();
            desc = change_input[2].toStdString();

            if(index_ < 0 || index_ >= accounts.size()){
                throw runtime_error("找不到账户<_>");
            }
            accounts[index_]->deposit(date, amount, desc);

            ofs << endl << cmd << " " ;
            ofs<<index_<<" "<<amount<<" ";
            ofs<<desc;
            show_alert();

            if(accounts[index_]->getUser() == User.toStdString()){ // 用户过滤
                my->ui->textBrowser_output->append(QString::fromStdString(to_string(date.getYear())+"年"+to_string(date.getMonth())+"月"+to_string(date.getDay())+"日"+accounts[index_]->getId()+"存了"+to_string(amount)+"元,原因："+desc));
            }
        }
        catch (runtime_error& err) {
            //cout << err.what() << endl;
            QMessageBox::warning(my,tr("警告"),tr(err.what()));
        }

        break;

    case 'w'://取出现金

        try{
            //cin >> index_ >> amount;
            index_ = change_input[0].toInt();
            amount = change_input[1].toDouble();
            desc = change_input[2].toStdString();

            //getline(cin, desc);
            if(index_ < 0 || index_ >= accounts.size()){
                throw runtime_error("找不到账户<_>");
            }

            accounts[index_]->withdraw(date, amount, desc);

            ofs << endl << cmd << " ";
            ofs<<index_<<" "<<amount<<" ";
            ofs<<desc;
            show_alert();
            if(accounts[index_]->getUser() == User.toStdString()){ // 用户过滤
                my->ui->textBrowser_output->append(QString::fromStdString(to_string(date.getYear())+"年"+to_string(date.getMonth())+"月"+to_string(date.getDay())+"日"+accounts[index_]->getId()+"取了"+to_string(amount)+"元,原因："+desc));
            }
        }
        catch (AccountException& err){
            //cout << err.what() << endl;
            QMessageBox::warning(my,tr("警告"),tr("你有钱吗<_>"));
        }
        catch (runtime_error& err) {
            //cout << err.what() << endl;
            QMessageBox::warning(my,tr("警告"),tr(err.what()));
        }

        break;

    case 's'://查询各账户信息
        static unsigned int num;
        num = 1;
        for (size_t i = 0; i < accounts.size(); i++) {

            //cout << "[" << i << "] ";
            //accounts[i]->show();
            //cout << endl;

            if(accounts[i]->getUser() == User.toStdString()) // 用户过滤
                my->ui->textBrowser_output->append(QString::fromStdString("[" + to_string(num++) + "] " + accounts[i]->show()));

        }

        break;

    case 'c'://改变日期

        //cin >> day;
        day = day_change;

        if (day < date.getDay())
            QMessageBox::warning(my,tr("警告"),tr("时间不能倒流哦 >_<"));
            //cout << "You cannot specify a previous day";
        else if (day > date.getMaxDay())
            QMessageBox::warning(my,tr("警告"),tr("这个日期不行呢 >_<"));
            //cout << "Invalid day";
        else{
            date = Date(date.getYear(), date.getMonth(), day);
            ofs << endl << cmd << " ";
            ofs<<day;
        }
        break;

    case 'n'://进入下个月


        if (date.getMonth() == 12)
            date = Date(date.getYear() + 1, 1, 1);
        else
            date = Date(date.getYear(), date.getMonth() + 1, 1);

        for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
            (*iter)->settle(date);

        ofs << endl << cmd << " ";
        break;

    case 'q'://查询一段时间内的账目
        try{
            date1 = d1;
            date2 = d2;
            //Account::query(date1, date2 ,user);
            my->ui->textBrowser_output->append(QString::fromStdString(Account::query(date1, date2, User.toStdString())));
        }
        catch (DateException & err){
            QMessageBox::warning(my,tr("警告"),tr(err.what()));
        }
    }
}

//创建账户
void MainWindow::on_pushButton_account_clicked()
{
    account_input[1] = ui->lineEdit_ID->text();
    account_input[2] = ui->lineEdit_credit->text();
    account_input[3] = ui->lineEdit_rate->text();
    account_input[4] = ui->lineEdit_fee->text();
    if(account_input[1]==""){
        QMessageBox::warning(this,tr("警告"),tr("请输入账号名"));
        return;
    }
    for(auto &iter : accounts){
        if(iter->getId() == account_input[1].toStdString()){
            QMessageBox::warning(this,tr("警告"),tr("系统中已有重名账号"));
            return;
        }
    }
    if(ui->checkBox_S->isChecked() && !ui->checkBox_C->isChecked()){
        if(account_input[3].toDouble()){
            account_input[0]='s';
            cmdprocess('a');
        }
        else
            QMessageBox::warning(this,tr("警告"),tr("请补全信息"));
    }
    else if(!ui->checkBox_S->isChecked() && ui->checkBox_C->isChecked()){
        if(account_input[2].toDouble() && account_input[3].toDouble() && account_input[4].toDouble()){
            account_input[0]='c';
            cmdprocess('a');
        }
        else
            QMessageBox::warning(this,tr("警告"),tr("请补全信息"));
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("请选择一种账户"));
        return;
    }


}

//存钱
void MainWindow::on_pushButton_deposit_clicked()
{
    change_input[0] = ui->comboBox_account_1->currentText();
    for(unsigned int i=0; i < accounts.size(); i++){
        if(accounts[i]->getId() == change_input[0].toStdString()){
            if(accounts[i]->getUser() != User.toStdString()){
                QMessageBox::warning(this,tr("警告"),tr("这不是你的账号,请不要乱动~_~"));
                return;
            }
            change_input[0] = (char)(i+48);
            change_input[1] = ui->lineEdit_Depositamount->text();
            change_input[2] = ui->lineEdit_Depositdesc->text();
            MainWindow::cmdprocess('d');
            return;
        }
    }
    QMessageBox::warning(this,tr("警告"),tr("找不到该账号>_<"));
}

//取钱
void MainWindow::on_pushButton_withdraw_clicked()
{
    change_input[0] = ui->comboBox_account_2->currentText();
    for(unsigned int i=0; i < accounts.size(); i++){
        if(accounts[i]->getId() == change_input[0].toStdString()){
            if(accounts[i]->getUser() != User.toStdString()){
                QMessageBox::warning(this,tr("警告"),tr("这不是你的账号,请不要乱动~_~"));
                return;
            }
            change_input[0] = (char)(i+48);
            change_input[1] = ui->lineEdit_Withdrawamount->text();
            change_input[2] = ui->lineEdit_Withdrawdesc->text();
            MainWindow::cmdprocess('w');
            return;
        }
    }
    QMessageBox::warning(this,tr("警告"),tr("找不到该账号>_<"));
}

//显示账户信息
void MainWindow::on_pushButton_showaccount_clicked()
{
    MainWindow::cmdprocess('s');
    show_alert();
}

//改变天数
void MainWindow::on_pushButton_Confirmdays_clicked()
{
    day_change = my->ui->lineEdit_days->text().toInt();
    if(day_change){
        MainWindow::cmdprocess('c');
        refreshdate();
    }
    else
        QMessageBox::warning(this,tr("警告"),tr("请输入天数>_<"));
}

//下个月
void MainWindow::on_pushButton_NextMonth_clicked()
{
    MainWindow::cmdprocess('n');
    refreshdate();
}

//查询账目
void MainWindow::on_pushButton_query_clicked()
{
    d1 = Date(ui->dateEdit_1->date().year(), ui->dateEdit_1->date().month(), ui->dateEdit_1->date().day());
    d2 = Date(ui->dateEdit_2->date().year(), ui->dateEdit_2->date().month(), ui->dateEdit_2->date().day());
    MainWindow::cmdprocess('q');
}

//显示还款信息
void MainWindow::show_alert(){
    double debt = 0;
    double income = 0, cost = 0;
    for(unsigned int i=0; i < accounts.size(); i++){
        if(accounts[i]->getUser() == User.toStdString()){
            if(accounts[i]->s_c() && accounts[i]->get_debt() < 0){//信用卡
                debt -= accounts[i]->get_debt();
            }
        }
    }
    //cout << date.getYear()<<date.getMonth()-1<<1
    income = Account::month_income(Date(date.getYear(),date.getMonth(),1),Date(date.getYear(),date.getMonth(),date.getMaxDay()),User.toStdString());
    cost = Account::month_cost(Date(date.getYear(),date.getMonth(),1),Date(date.getYear(),date.getMonth(),date.getMaxDay()),User.toStdString());

    my->ui->label_account->setText(QString::fromStdString("本月应还："+to_string(debt)+" 本月收入："+to_string(income)+" 本月支出"+to_string(cost)));
}

//清屏
void MainWindow::on_pushButton_clear_clicked()
{
    my->ui->textBrowser_output->setText("");
}

//刷新日期
void MainWindow::refreshdate(){
    my->ui->date->setText(QString::fromStdString(date.show()));
}




