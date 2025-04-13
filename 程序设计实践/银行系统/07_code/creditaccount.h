//creditaccount.h
#ifndef __CREDITACCOUNT_H__
#define __CREDITACCOUNT_H__
#include "account.h"
#include "date.h"
#include "accumulator.h"
#include <string>


//信用账户
class CreditAccount :public Account{
private:
    Accumulator acc;
    double credit;
    double rate;
    double fee;     //年费，每年需要缴纳一次年费，1月1日扣除
    double interest;        //利息，每月一结算


public:

    double get_debt()const{return getBalance();};
    double get_credit()const{return credit;};
    double get_rate()const{return rate;};
    double get_fee()const{return fee;};

    CreditAccount(const Date &date,string id,string user,double credite,double rate,double fee);
    void deposit(Date &date,double amount,string desc);     //  存钱
    void withdraw(Date &date,double amount,string desc);    //  取钱
    void settle(Date &date);      //计算年息
    string show() const;
    int s_c(){
        return 1;
    }

};


#endif //__CREDITACCOUNT_H__
