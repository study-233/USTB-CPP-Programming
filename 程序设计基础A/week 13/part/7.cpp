#include  <iostream>      //  包含头文件iostream
#include  <cstring>
using  namespace  std;    //  使用命名空间std

//Employee的定义
class Employee{
    private:
        int id;
        char * name;
        int age;
        static int count;
        static float allAges;
    public:
        Employee(int,char*,int);
        ~Employee();
        void printStat();
        void printEmployee();
};
Employee::Employee(int  pId,char*  pName,int  pAge)
{
//对成员数据赋值
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            id=pId;
            age=pAge;
            count++;
            allAges+=age;
  cout<<"Constructed  with  all  parameters."<<endl;
}
//静态成员初始化
int Employee::count=0;
float Employee::allAges=0;
Employee::~Employee()
{
            delete []name;
            cout<<"Deconstructed."<<endl;
}
void  Employee::printEmployee()
{
            cout<<"id:  "<<id<<",  "
            <<"name:  "<<name<<",  "
            <<"age:  "<<age<<endl;
}
void  Employee::printStat()
{
        cout<<"The  number  of  employees  is:  "<<count<<endl;
        cout<<"The  average  age  is:  "<<(float)(allAges)/count<<endl;
}
int  main()
{
          Employee  e1(1001,"zhangsan",22);
          Employee  e2(1002,"lisi",23);
          Employee  e3(1003,"wangwu",25);
          Employee  e4(1004,"zhouliu",20);
          e1.printStat();
          return  0;
}