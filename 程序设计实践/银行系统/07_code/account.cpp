//account.cpp
#include "account.h"
#include "accountrecord.h"
#include "date.h"
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//静态变量初始化为0
double Account::total = 0;
multimap<Date, AccountRecord> Account::recordMap; //所有账目

//Account类相关成员函数的实现
Account::Account(const Date &date, string id, string user)
    : id(id), balance(0), User(user){
    date.show();
    //cout << "\t#" << id << " created" << endl;
}
//构造函数，记录创建日期，账户id，以及年利率


//展示id和余额
string Account::show() const {
    return  string(id) + "\tBalance: " + to_string(balance);
}

//改变余额
void Account::record(Date &date,double amount,string desc) {
    amount = floor(amount * 100 + 0.5) / 100;    //保留两位小数
    balance+=amount;
    total+=amount;  //总的余额记录在这里，是包含信用账户的贷款的，且信用账户的余额是负数
    AccountRecord acr(date,this,amount,balance,desc);
    recordMap.insert({date, acr});
    date.show();
    //cout << "\t#" << getId()<<"\t"<<amount<<"\t"<<getBalance() <<"\t"<<desc<< endl;

}

//  查询
string Account::query(Date &date1,Date &date2, string user){

    std::vector<AccountRecord> records; //存符合日期的数据，用于排序
    string temp="按日期排序:\n";
    for(auto & it : recordMap){
        if(date1 <= it.first && date2 >= it.first && it.second.account->getUser() == user){
            temp += it.first.show() + "\t" + it.second.account->getId() + "\t" + to_string(it.second.amount) + "\t" +
                        to_string(it.second.balance) + "\t" + it.second.desc + "\n";
            records.push_back(it.second);
        }
    }

    temp += "按交易金额排序:\n";
    std::sort(records.begin(), records.end(), [](const AccountRecord& a, const AccountRecord& b) {
        return b.amount < a.amount; // 从大到小排序
    });
    for (const auto& record : records) {
        temp += record.date.show() + "\t" + record.account->getId() + "\t" + to_string(record.amount) + "\t" +
                to_string(record.balance) + "\t" + record.desc + "\n";
    }

    return temp;
};

//本月支出 统计
double Account::month_cost(Date day1, Date day2, string user){
    double cost = 0;
    for(auto & it : recordMap){
        if(day1 <= it.first && day2 >= it.first  && it.second.account->getUser() == user){
            if(it.second.amount < 0) cost += it.second.amount;
        }
    }
    return -cost;
}

//本月收入 统计
double Account::month_income(Date day1, Date day2, string user){
    double income = 0;
    for(auto & it : recordMap){
        if(day1 <= it.first && day2 >= it.first  && it.second.account->getUser() == user){
            if(it.second.amount > 0) income += it.second.amount;
        }
    }
    return income;
}
