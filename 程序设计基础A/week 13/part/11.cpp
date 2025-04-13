#include  <iostream>      
#include  <cstring>
using  namespace  std;    
class  BusinessManager
{
public:
            BusinessManager()
            {
                        cout<<"BusinessManager  Constructed  without  any  parameter."<<endl;
            }
            BusinessManager(int  pId,char*  pName,int  age);
            void  setBusinessManager(int  pId,char*  pName,int  pAge);
          ~BusinessManager();
            void  printBusinessManager();
private:
            int  id;
            char*  name;
            int  age;
};
BusinessManager::BusinessManager(int  pId,char*  pName,int  pAge)
{
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;

            cout<<"BusinessManager  Constructed  with  all  parameters."<<endl;
}
void  BusinessManager::setBusinessManager(int  pId,char*  pName,int  pAge)
{
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;


}
BusinessManager::~BusinessManager()
{

delete []name;


            cout<<"BusinessManager  Deconstructed."<<endl;
}
void  BusinessManager::printBusinessManager()
{
cout<<"id:  "<<id<<",  "<<"name:  "<<name<<",  "<<"age:  "<<age<<endl;
}
class  TechnicalManager{
public:
            TechnicalManager()
            {
                cout<<"TechnicalManager  Constructed  without  any  parameter."<<endl;
            }
            TechnicalManager(int  pId,char*  pName,int  pAge);
            void  setTechnicalManager(int  pId,char*  pName,int  pAge)
            {
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;

            }
          ~TechnicalManager();
            void  printTechnicalManager();
private:
            int  id;
            char*  name;
            int  age;
};
TechnicalManager::TechnicalManager(int  pId,char*  pName,int  pAge)
{
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;



            cout<<"TechnicalManager  Constructed  with  all  parameters."<<endl;
}
TechnicalManager::~TechnicalManager()
{

delete []name;

            cout<<"TechnicalManager  Deconstructed."<<endl;
}
void  TechnicalManager::printTechnicalManager()
{
            cout<<"id:  "<<id<<",  "
                      <<"name:  "<<name<<",  "
                      <<"age:  "<<age<<endl;
}
class  Employee
{
public:
            Employee()
            {
                        cout<<"Employee  Constructed  without  any  parameter."<<endl;
            }
            Employee(int  pId,char*  pName,int  age);
            ~Employee();
            void  setEmployee(int  pId,char*  pName,int  age);
            void  printEmployee();
private:
            int  id;
            char*  name;
            int  age;
};
Employee::Employee(int  pId,char*  pName,int  pAge)
{
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;
            cout<<"Employee  Constructed  with  all  parameters."<<endl;
}
void  Employee::setEmployee(int  pId,char*  pName,int  pAge)
{
            id=pId;
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            age=pAge;
}
Employee::~Employee()
{
delete []name;
            cout<<"Employee  Deconstructed."<<endl;
}
void  Employee::printEmployee()
{
            cout<<"id:  "<<id<<",  "
                      <<"name:  "<<name<<",  "
                      <<"age:  "<<age<<endl;
}
class  Team
{
public:
            Team()
            {
                        cout<<"Team  Constructed."<<endl;
            }
            void  printTeam()
            {
                bm.printBusinessManager();
                tm.printTechnicalManager();
                for(int i=0;i<6;i++){
                    e[i].printEmployee();
                }
            }
public:
            BusinessManager  bm;
            TechnicalManager  tm;
            Employee  e[6];
};
int  main()
{
            Team  t;
            t.bm.setBusinessManager(1001,"zhangsan_BM",32);
            t.tm.setTechnicalManager(1002,"lisi_TM",31);
            t.e[0].setEmployee(2000,"wang0_EMP",24);
            t.e[1].setEmployee(2001,"wang1_EMP",22);
            t.e[2].setEmployee(2002,"wang2_EMP",23);
            t.e[3].setEmployee(2003,"wang3_EMP",22);
            t.e[4].setEmployee(2004,"wang4_EMP",25);
            t.e[5].setEmployee(2005,"wang5_EMP",20);
            t.printTeam();
            return  0;
}