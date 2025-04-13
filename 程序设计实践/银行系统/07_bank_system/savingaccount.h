//savingaccount.h
#ifndef __SAVINGACCOUNT_H__
#define __SAVINGACCOUNT_H__
#include "account.h"        // 需要派生
#include "date.h"           //需要使用Date
#include "accumulator.h"    //用来记录利息
#include <string>

//储蓄账户
class SavingsAccount:public Account { //Account的派生类
private:
    Accumulator acc;//用来计算
    double rate;
    double interest{}; //存储利息

public:
    double get_rate()const{return rate;};

    SavingsAccount(const Date &date,string id,double rate); //构造函数
    //自类和父类，构造函数的关系

    void deposit(Date &date,double amount,string desc); //  存钱
    void withdraw(Date &date,double amount,string desc);    //  取钱
    void settle(Date &date);      //计算年息



};

#endif //__SAVINGACCOUNT_H__