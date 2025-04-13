//savingaccount.h
#ifndef __SAVINGACCOUNT_H__
#define __SAVINGACCOUNT_H__
#include "account.h"
#include "date.h"
#include "accumulator.h"
#include <string>


//储蓄账户
class SavingsAccount:public Account { //Account的派生类
private:
    Accumulator acc; //用来计算
    double rate;
    double interest; //存储利息

public:
    double get_rate()const{return rate;};

    SavingsAccount(const Date &date,string id,string user,double rate); //构造函数
    //自类和父类，构造函数的关系

    double get_debt()const{return 0;};
    void deposit(Date &date,double amount,string desc);     //存钱
    void withdraw(Date &date,double amount,string desc);    //取钱
    void settle(Date &date);      //计算年息
    int s_c(){
        return 0;
    }


};

#endif //__SAVINGACCOUNT_H__
