//creditaccount.cpp
#include "creditaccount.h"
#include <string>

using namespace std;

CreditAccount::CreditAccount(const Date &date, string id,string user, double credite, double rate, double fee)
: Account(date,id,user),acc(date,0),credit(credite),rate(rate),fee(fee) {}


// 信用账户存钱操作
void CreditAccount::deposit(Date &date, double amount, string desc){

    //cout<<getBalance()<<endl;
    record(date,amount,desc);
    acc.change(date,getBalance());

}

//信用账户取钱操作
void CreditAccount::withdraw(Date &date, double amount, string desc) {

    if(credit+getBalance()-amount>=0){
        record(date,-amount,desc);
        acc.change(date,getBalance());
    }
    else{ 
        throw AccountException(this);
    }
}

//结算利息
void CreditAccount::settle(Date &date) {
    acc.change(date,getBalance());
    interest=acc.getSum(date)*rate/(date-(Date(date.getYear() - 1, 1, 1))); //计算利息
    //那个rate指的是日利率，按日欠款计息，将日累积直接乘以日利率就是利息

    if(date.getMonth()==1 && date.getDay()==1){
        record(date,interest,"interest");
        record(date,-fee,"annual fee");//在余额中加上利息
    
    }
    else{
        record(date,interest,"interest");//在余额中加上利息
    }
    interest=0;
    acc.reset(date,getBalance());
}

string CreditAccount::show() const {
    return  getId() + "\tBalance: " + to_string(getBalance()) + "\t" + "Available credit:" + to_string(credit + getBalance());

}
