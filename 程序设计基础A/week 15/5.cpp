#include <iostream>
using namespace std;

class Account {

    public:

    Account(int accNumber, float balan) {
        acntNumber = accNumber;
        balance = balan;
        pNext = nullptr;

        // Update the linked list of accounts and the count.
        if (pFirst) {
            Account *cur = pFirst;
            while (cur->pNext) {
                cur = cur->pNext;
            }
            cur->pNext = this;
        } else {
            pFirst = this;
        }
        ++count;
    };

    virtual void Withdrawal(float amount) = 0; // 取款

    void Deposit(float amount) {
        balance += amount;
    }

    int AccountNo() {
        return acntNumber;
    }

    void Display() {
        cout << acntNumber << " " << balance << endl;
    }

    static Account* First(){
        return pFirst;
    }

    Account* Next(){
        return pNext;
    }

    static int NumOfAccount(){
        return count;
    }

    virtual void SetRemit(int re) {} // 汇款

    protected:

    static int count; // 用户数量
    static Account* pFirst; // 第一个账户指针

    Account* pNext; // 下一个账户指针
    int acntNumber; // 账号
    float balance;
};

int Account::count = 0;
Account* Account::pFirst = nullptr;

class Savings:public Account {
    public:
        Savings(int accNumber, float balan) : Account(accNumber, balan){
        }

        virtual void Withdrawal(float amount) {
            if (balance < amount)
                cout <<acntNumber<< " Insufficient balance" << endl;
            else
                balance -= amount;
        }
};

class Checking:public Account {
    public:
        Checking(int accNumber, float balan) : Account(accNumber, balan){
        }

        virtual void Withdrawal(float amount) {
            if (balance < amount)
                cout <<acntNumber<< " Insufficient balance" << endl;
            else
                balance -= amount;
        }

        virtual void SetRemit(int re) {
            if (re != 1) {
                if (balance < 30)
                    cout <<acntNumber<< " Insufficient balance" << endl;
                else
                    balance -= 30;
            }
        }
};

int main(){
    Account *a1 = new Savings(1, 200);
    Account *a2 = new Checking(2, 500);
    a1->Display();
    a1->Withdrawal(100);
    a1->Deposit(50);
    a1->Display();
    a2->Deposit(200);
    a2->SetRemit(0);
    a2->Withdrawal(300);
    a2->Display();
    a2->Withdrawal(500);
    cout << Account::NumOfAccount() << endl;
    a1->Withdrawal(50);
    a1->Display();
    return 0;
}