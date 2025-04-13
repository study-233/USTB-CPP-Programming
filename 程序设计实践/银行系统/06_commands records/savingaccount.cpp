#include "savingaccount.h"
#include "date.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


SavingsAccount::SavingsAccount(const Date &date, string id, double rate)
: Account(date,id),acc(date,0){ //对父类，以及类对象初始化
    this->rate=rate;
}

// 储蓄账户存钱操作
void SavingsAccount::deposit(Date &date, double amount, string desc){

    record(date,amount,desc);
    acc.change(date,getBalance());

}

//储蓄账户取钱操作
void SavingsAccount::withdraw(Date &date, double amount, string desc){

    record(date,-amount,desc);
    acc.change(date,getBalance());
}

//结算利息
void SavingsAccount::settle(Date &date) {

    if(date.getMonth()==1){
        acc.change(date,0);
        interest=acc.getSum(date)*rate/(date-(Date(date.getYear() - 1, 1, 1))); //计算年息
        record(date,interest,"interest");//在余额中加上利息
    }

}

