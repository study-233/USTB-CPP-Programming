//step7.cpp

#include "date.h"
#include "account.h"
#include "savingaccount.h"
#include "creditaccount.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace std;

    Date date(2008, 11, 1);//起始日期
    vector<Account *> accounts;//创建账户数组，元素个数为0
    char cmd,type;
    int index_, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account* account;
    Date date1, date2;
    void read_cmd();

struct deleter {
    template <class T> void operator () (T* p) { delete p; }
};

int main() {

    read_cmd();

    cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;
    ofstream ofs;
    ofs.open("commands.txt",ios::app);

    do{

        //显示日期和总金额
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";

        cin>>cmd;

        switch (cmd) {
            case 'a'://增加账户
                try{
                    cin >> type >> id;
                    if(type == 's' || type == 'c'){
                        ofs << endl << cmd << " ";
                        ofs << type << " " << id << " ";
                    }
                    else throw runtime_error("账户类型错误");
                }
                catch (runtime_error& err) {
                    cout << err.what() << endl;
                }

                if (type == 's') {
                    cin >> rate;
                    ofs<<rate;
                    account = new SavingsAccount(date, id, rate);
                }
                else {
                    cin >> credit >> rate >> fee;
                    ofs<<credit<<" "<<rate<<" "<<fee;
                    account = new CreditAccount(date, id, credit, rate, fee);
                }

                accounts.push_back(account);

                break;

            case 'd'://存入现金
                try{
                    cin >> index_ >> amount;
                    getline(cin, desc);
                    if(index_ < 0 || index_ >= accounts.size()){
                        throw runtime_error("The index you input is not exist.");
                    }
                    accounts[index_]->deposit(date, amount, desc);

                    ofs << endl << cmd << " ";
                    ofs<<index_<<" "<<amount<<" ";
                    ofs<<desc;
                }
                catch (runtime_error& err) {
                    cout << err.what() << endl;
                }

                break;

            case 'w'://取出现金

                try{
                    cin >> index_ >> amount;
                    getline(cin, desc);
                    if(index_ < 0 || index_ >= accounts.size()){
                        throw runtime_error("The index you input is not exist.");
                    }
                    accounts[index_]->withdraw(date, amount, desc);

                    ofs << endl << cmd << " ";
                    ofs<<index_<<" "<<amount<<" ";
                    ofs<<desc;
                }
                catch (AccountException& err){
                    cout << err.what() << endl;
                }
                catch (runtime_error& err) {
                    cout << err.what() << endl;
                }

                break;

            case 's'://查询各账户信息

                for (size_t i = 0; i < accounts.size(); i++) {

                    cout << "[" << i << "] ";

                    accounts[i]->show();

                    cout << endl;

                }

                break;

            case 'c'://改变日期

                cin >> day;
                if (day < date.getDay())
                    cout << "You cannot specify a previous day";
                else if (day > date.getMaxDay())
                    cout << "Invalid day";
                else
                    date = Date(date.getYear(), date.getMonth(), day);
                    ofs << endl << cmd << " ";
                    ofs<<day;                    
                break;

            case 'n'://进入下个月

                
                if (date.getMonth() == 12)
                    date = Date(date.getYear() + 1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth() + 1, 1);

                for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
                    (*iter)->settle(date);
                    
                ofs << endl << cmd << " ";
                break;

            case 'q'://查询一段时间内的账目
                try{
                    date1 = Date::read();
                    date2 = Date::read();
                    Account::query(date1, date2);
                }
                catch (DateException & err){
                    cout << err.what() << endl;
                    if(cin.fail()) cin.clear();
                }
            default:
                cout << "程序退出" <<endl;
                break;
        }
    } while (cmd != 'e');

    for_each(accounts.begin(), accounts.end(), deleter());
    ofs.close();
    return 0;

}

void read_cmd(){
    ifstream ifs;
    ifs.open("commands.txt");
    if(!ifs.is_open()){return;}
    while(ifs>>cmd){
        switch (cmd) {
            case 'a'://增加账户
            
                ifs >> type >> id;
                if (type == 's') {
                    ifs >> rate;
                    account = new SavingsAccount(date, id, rate);
                }
                else {
                    ifs >> credit >> rate >> fee;
                    account = new CreditAccount(date, id, credit, rate, fee);
                }
                accounts.push_back(account);
                break;

            case 'd'://存入现金
                ifs >> index_ >> amount;
                getline(ifs,desc);
                accounts[index_]->deposit(date, amount, desc);
                break;

            case 'w'://取出现金
                ifs >> index_ >> amount ;
                getline(ifs,desc);
                accounts[index_]->withdraw(date, amount, desc);
                break;


            case 'c'://改变日期
                ifs >> day;
                date = Date(date.getYear(), date.getMonth(), day);
                break;

            case 'n'://进入下个月

                if (date.getMonth() == 12)
                    date = Date(date.getYear() + 1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth() + 1, 1);
                for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
                    (*iter)->settle(date);
                break;

        }
    }
    ifs.close();
}