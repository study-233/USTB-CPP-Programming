//account.cpp
#include "account.h"
#include "date.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

//静态变量初始化为0
double Account::total = 0;

//Account类相关成员函数的实现
Account::Account(Date date, string id)
: id(id), balance(0){
    date.show();
	cout << "\t#" << id << " created" << endl;
}
//构造函数，记录创建日期，账户id，以及年利率


//展示id和余额
void Account::show() const {
	cout << id << "\tBalance: " << balance;
}

//改变余额
void Account::record(Date date,double amount,string desc) {

    amount = floor(amount * 100 + 0.5) / 100;
    balance+=amount;
    total+=amount; //总的余额记录在这里，是包含信用账户的贷款的，且信用账户的余额是负数
    date.show();
    cout << "\t#" << getId()<<"\t"<<amount<<"\t"<<getBalance() <<"\t"<<desc<< endl;
}

