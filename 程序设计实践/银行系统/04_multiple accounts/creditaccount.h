#ifndef __CREDITACCOUNT_H__
#define __CREDITACCOUNT_H__
#include "account.h"        // 需要派生
#include "date.h"           //需要使用Date
#include "accumulator.h"    //用来记录利息
#include <string>
//信用账户，能够在信用额度内消费，需要支付利息
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

    CreditAccount(Date date,string id,double credite,double rate,double fee);
    void deposit(Date date,double amount,string desc);     //  存钱
    void withdraw(Date date,double amount,string desc);    //  取钱
    void settle(Date date);      //计算年息
    void show();

};

#endif 

