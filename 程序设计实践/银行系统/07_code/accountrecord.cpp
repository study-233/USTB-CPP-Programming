//accountrecord.cpp
#include "accountrecord.h"
#include "account.h"
#include "date.h"
#include <string>
using namespace std;

AccountRecord::AccountRecord(Date &date,Account *account,double amount,double balance,string &desc)
    :date(date),account(account),amount(amount),balance(balance),desc(desc){};

