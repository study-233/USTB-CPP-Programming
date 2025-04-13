#include "creditaccount.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

CreditAccount::CreditAccount(Date date, string id, double credite, double rate, double fee)
: Account(date,id),acc(date,0),credit(credite),rate(rate),fee(fee) {} //对父类，以及类对象初始化


//完成对类的，展示内容

// 信用账户存钱操作
void CreditAccount::deposit(Date date, double amount, string desc){

    //cout<<getBalance()<<endl;
    record(date,amount,desc);
    acc.change(date,getBalance() > 0 ? 0 : getBalance());

}

//信用账户取钱操作
//取钱操作需要和信用对比一下
void CreditAccount::withdraw(Date date, double amount, string desc) {

    if(credit+getBalance()-amount>=0){
        record(date,-amount,desc);
        acc.change(date,getBalance() > 0 ? 0 : getBalance());
    }
    else{ cout<<"信用额度不足！！"<<endl; }
}

//结算利息
void CreditAccount::settle(Date date) {
    acc.change(date,getBalance() > 0 ? 0 : getBalance());
    interest=acc.getSum(date)*rate; //计算利息
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

void CreditAccount::show() {        //子类需要重写
    cout << getId() << "\tBalance: " << getBalance()<<"\t"<<"Available credit:"<<credit+getBalance();

}
