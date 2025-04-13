#include  <iostream>      //  包含头文件iostream
#include  <cstring>
using  namespace  std;    //  使用命名空间std

//Engineer类的定义
class Engineer
{
private:
    int Id;
    char* Name;
    char* Position;
public:
    Engineer(){};
    Engineer(int pid,const char* pname,const char* pposition){
        Id=pid;
        Name=new char[strlen(pname)+1];
        Position=new char[strlen(pposition)+1];
        strcpy(Name,pname);
        strcpy(Position,pposition);        
    }
    void setEngineer(int pid,const char* pname,const char* pposition){
        Id=pid;
        Name=new char[strlen(pname)+1];
        Position=new char[strlen(pposition)+1];
        strcpy(Name,pname);
        strcpy(Position,pposition);
    };
    void printEngineer();
    ~Engineer();
};
Engineer::~Engineer(){
    delete []Name;
    delete []Position;
    cout<<"destructing..."<<"\n";
}
void  Engineer::printEngineer  ()
{
    cout<<"id:  "<<Id<<",  name:  "<<Name<<",  position:  "<<Position<<endl;
}
int  main()
{
        Engineer  e[4];
        e[0].setEngineer(1001,"wanghan","lecture");    
                e[1].setEngineer(1002,"zhangqing","lecture");
                e[2].setEngineer(1003,"zhaojing","professor");
                e[3].setEngineer(1004,"yaolin","professor");
        Engineer  *  pE1  =new  Engineer(1005,"fangwei","professor");
        Engineer  *  pE2  =new  Engineer(1006,"huangling","professor");
        e[0].  printEngineer  ();
        e[1].  printEngineer  ();
        e[2].  printEngineer  ();
        e[3].  printEngineer  ();
        pE1->printEngineer  ();
        pE2->printEngineer  ();
        delete  pE1,  pE2;
        return  0;
}