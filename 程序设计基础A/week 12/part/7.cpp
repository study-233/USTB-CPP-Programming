#include  <iostream>      //  包含头文件iostream
#include  <cstring>
using  namespace  std;    //  使用命名空间std
class  Course
{
public:
        //  成员函数定义
        Course();
        Course(int  pId,  char*  pName,  int  pHours,  char*  pTeacherInCharge);
        void setCourse(int  pId,  char*  pName,  int  pHours,  char*  pTeacherInCharge);
        void printCourse();
        ~Course();
private:
        int  id;
        char*  name;
        int  hours;
        char*  teacherInCharge;
};
Course::Course(){
        cout<<"Constructed  without  Parameters."<<endl;
}
Course::Course(int  pId,  char*  pName,  int  pHours,  char*  pTeacherInCharge){

        id=pId;
        name=new char[strlen(pName)+1];
        teacherInCharge=new char[strlen(pTeacherInCharge)+1];
        strcpy(name,pName);
        strcpy(teacherInCharge,pTeacherInCharge);
        hours=pHours;

        cout<<"Constructed  with  Parameters."<<endl;

}
void  Course::setCourse(int  pId,  char*  pName,  int  pHours,  char*  pTeacherInCharge){

        id=pId;
        name=new char[strlen(pName)+1];
        teacherInCharge=new char[strlen(pTeacherInCharge)+1];
        strcpy(name,pName);
        strcpy(teacherInCharge,pTeacherInCharge);
        hours=pHours;


}
Course::~Course()
{
            delete[]  name;
            delete[]  teacherInCharge;
            cout<<"Deconstructed."<<endl;
}
void  Course::printCourse()
{
                cout<<"id:  "<<id<<",  "
                <<"name:  "<<name<<",  "
                <<  "hours:  "<<hours<<",  "
                <<  "teacherInCharge:  "<<teacherInCharge
                <<endl  ;                
}
int  main()
{
            Course  c[3];
            c[0].setCourse(1001,"Math",56,"zhangsan");
            c[1].setCourse(1002,"C++",64,"lisi");
            c[2].setCourse(1003,"History",48,"wangwu");
            Course*  pCourse=new  Course(1004,"DataStructure",72,"zhaoliu");
            c[0].printCourse();
            c[1].printCourse();
            c[2].printCourse();
            pCourse->printCourse();
            delete  pCourse;
            return  0;
}