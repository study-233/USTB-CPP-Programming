/*1. 定义一个Student类*/
#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string m_name;
    int m_age;
    int m_id;
    student(string name,int age,int id):m_name(name),m_age(age),m_id(id){}
    void getname(){
        cout<<"Name:"<<m_name;
    };
    void getage(){
        cout<<" Age:"<<m_age;
    };
    void getid(){
        cout<<" No:"<<m_id;
    };
};


int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string name;
    int age,id;
    cin>>name>>age>>id;

    student stu(name,age,id);
    
    stu.getname();
    stu.getage();
    stu.getid();

}

