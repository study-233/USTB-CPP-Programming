//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include <string>
#include <map>
using namespace std;

class AccountRecord;

//基本的账户类
class Account { //账户类
private:
    string id;			//账号
    double balance;		//余额
    //对于储蓄账户来说，一直都是正值；
    //对于信用账户来说这 欠款时是负值
    string User;        //用户名
	static double total;	//所有账户的总金额

    static multimap<Date, AccountRecord> recordMap;		//所有账目

public:
	//构造函数
    Account(const Date &date, string id, string User);// 由派生类来实现
    virtual string show() const;
	virtual void deposit(Date &date, double amount, string desc)=0;
	virtual void withdraw(Date &date, double amount, string desc)=0;
	virtual void settle(Date &date)=0;
    virtual int s_c() = 0; //s = 0, c = 1;
    virtual double get_debt() const = 0;

    void record(Date &date,double amount,string desc);		//记录每一次操作

    string getUser() const {return User; };
    string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() {return total;}

    static string query(Date &date1,Date &date2,string user);
    static double month_cost(Date day1, Date day2, string user);
    static double month_income(Date day1, Date day2, string user);

};

class AccountException : public exception{
private:
    Account* account;
public:
    explicit AccountException(Account *account): account(account){};
    const char *what() const noexcept override{
        string s1 = "余额不足:";
        string s2 = account->getId();
        string s3 = to_string(account->getBalance());
        static string s4 = s1+s2+"\tbalance:"+s3;
        return s4.c_str();
    }
};

#endif //__ACCOUNT_H__
