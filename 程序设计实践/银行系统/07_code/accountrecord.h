//accountrecord.h
#ifndef __ACCOUNT_RECORD__
#define __ACCOUNT_RECORD__

#include <string>
#include "date.h"
#include "account.h"
using namespace std;

class Account;
class AccountRecord{        //账目记录
    public:
        AccountRecord(Date &date,Account *account,double amount,double balance,string &desc);
        Date date;
        const Account *account;
        double amount;
        double balance;
        string desc;
};



#endif //__ACCOUNT_RECORD__
