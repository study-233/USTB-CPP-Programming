/**/
#include <bits/stdc++.h>
using namespace std;
class Employee{
    private:
        string name;
    public:
        Employee(string name_):name(name_){}
        void getname(){
            cout<<"name:"<<name<<" ";
        }
};
class Manager:public Employee{
    private:
        string department;
    public:
        Manager(string name_,string department_):Employee(name_),department(department_){}
        void getdepartment(){
                cout<<"department:"<<department;
        }
};
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    Manager manager1("Manager","Human Resource");
    manager1.getname();
    manager1.getdepartment();
    
}
