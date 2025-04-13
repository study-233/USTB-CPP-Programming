#include "account.h"
#include "date.h"
#include <bits/stdc++.h>
using namespace std;

double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(const Date &date,const string & id_,double rate_):lastDate(date),id(id_),rate(rate_),balance(0),accumulation(0){
    lastDate.show();
    cout<<"\t#"<<id<<" created"<<endl;
};

double SavingsAccount::accumulate(const Date &date){
    return accumulation + balance * date.distance(lastDate);
};

void SavingsAccount::record(const Date &date,double amount,const string & desc){
    accumulation=accumulate(date);
    lastDate=date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance+=amount;
    total+=amount;
    lastDate.show();
    cout<<"\t#"<<id<<"\t";
    cout.setf(ios::left);
    cout.width(5);
    cout<<amount<<"   "<<balance<<"\t"<<desc<<endl;
};

void SavingsAccount::show(){
    cout<<id<<"\tBalance: "<<balance;
};

void SavingsAccount::deposit(const Date &date,double amount,const string & desc){
    record(date,amount,desc);
};

void SavingsAccount::withdraw(const Date &date,double amount,const string & desc){
    if(amount>balance)
        cout<<"not enough money"<<endl;
    else    
        record(date,-amount,desc);
};

void SavingsAccount::settle(const Date &date){
    double interest=accumulate(date)*rate/date.distance(Date(date.getYear() - 1, 1, 1)); //计算年息
    if(interest!=0)
        record(date,interest,"interest");
    accumulation=0;
};


