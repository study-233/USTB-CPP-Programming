//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include "accountrecord.h"
#include <string>
#include <map>
using namespace std;

class AccountRecord;
//最基本的账户类
class Account { //账户类
private:
    string id;			//账号
	double balance;		//余额
	//对于储蓄账户来说，这个余额是正值； 对于信用账户来说这个余额是负值
	
	static double total;	//所有账户的总金额

	static multimap<Date, AccountRecord> recordMap;		//所有账目

public:
	//构造函数
	Account(const Date &date, string id);// 由派生类来实现
    virtual void show() const;
	virtual void deposit(Date &date, double amount, string desc)=0;
	virtual void withdraw(Date &date, double amount, string desc)=0;
	virtual void settle(Date &date)=0;


    void record(Date &date,double amount,string desc);		//记录每一次操作

    string  getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() {return total;}

	static void query(Date &date1,Date &date2);


};

#endif 

