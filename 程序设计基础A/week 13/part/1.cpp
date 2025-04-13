#include  <iostream>      
#include  <cstring>
using  namespace  std;    
class  Manager
{
    private:
        int id;
        char* name;
        int age;
    public:
        Manager(int,char*,int);
        ~Manager();
        friend void printManager(Manager&);

};
Manager::Manager(int  pId,char*  pName,int  pAge)
{
            name=new char[strlen(pName)+1];
            strcpy(name,pName);
            id=pId;
            age=pAge;
            cout<<"Constructed  with  all  parameters."<<endl;
}
Manager::~Manager()
{
            delete []name;
            cout<<"Deconstructed."<<endl;
}
void  printManager(Manager&  manager)
{
            cout<<"id:  "<<manager.id<<",  "
                      <<"name:  "<<manager.name<<",  "
                      <<"age:  "<<manager.age<<endl;
}
int  main()
{
            Manager  m1(1001,"zhangsan",22);
            printManager(m1);
            return  0;
}