//accountrecord.cpp
#include "accountrecord.h"
#include "account.h"
#include "date.h"
#include <string>
#include <iostream>
using namespace std;

AccountRecord::AccountRecord(Date &date,Account *account,double amount,double balance,string &desc)
:date(date),account(account),amount(amount),balance(balance),desc(desc){};

void AccountRecord::show() {
    this->date.show();
    cout << "\t#" << this->account->getId()<<"\t"<<amount<<"\t"<< balance <<"\t"<< desc << endl;
}