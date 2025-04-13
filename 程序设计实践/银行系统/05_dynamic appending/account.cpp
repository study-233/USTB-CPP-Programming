//account.cpp
#include "account.h"
#include "accountrecord.h"
#include "date.h"
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//静态变量初始化为0
double Account::total = 0;
multimap<Date, AccountRecord> recordMap;		//所有账目
multimap<Date, AccountRecord> Account::recordMap;

//Account类相关成员函数的实现
Account::Account(const Date &date, string id)
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
void Account::record(Date &date,double amount,string desc) {
    amount = floor(amount * 100 + 0.5) / 100;    //保留两位小数
    balance+=amount;
    total+=amount; //总的余额记录在这里，是包含信用账户的贷款的，且信用账户的余额是负数
    AccountRecord acr(date,this,amount,balance,desc);
    recordMap.insert({date, acr});
    date.show();
    cout << "\t#" << getId()<<"\t"<<amount<<"\t"<<getBalance() <<"\t"<<desc<< endl;

}

//  查询
void Account::query(Date &date1,Date &date2){
    for(Date date=date1;date <= date2;date++){
        auto it = recordMap.find(date);
        if(it != recordMap.end()){
            for(int k = 0;k != recordMap.count(date);k++,it++)
                it->second.show();
        }

    }
};