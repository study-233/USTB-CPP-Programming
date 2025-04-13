//savingaccount.cpp
#include "savingaccount.h"
#include "date.h"
#include <string>

using namespace std;


SavingsAccount::SavingsAccount(const Date &date, string id, string user,double rate)
: Account(date,id,user),acc(date,0){ //对父类，以及类对象初始化
    this->rate=rate;
}

// 储蓄账户存钱操作
void SavingsAccount::deposit(Date &date, double amount, string desc){

    record(date,amount,desc);
    acc.change(date,getBalance());

}

//储蓄账户取钱操作
void SavingsAccount::withdraw(Date &date, double amount, string desc){

    if(amount <= getBalance()) {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
    else throw AccountException(this);
}

//结算利息
void SavingsAccount::settle(Date &date) {

    if(date.getMonth()==1){
        acc.change(date,0);
        interest=acc.getSum(date)*rate/(date-(Date(date.getYear() - 1, 1, 1))); //计算年息
        record(date,interest,"interest");//在余额中加上利息
    }

}
