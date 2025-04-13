#include  <iostream>
using  namespace  std;
class  Student{
        private  :
                char  *name;
                int  age;
                char  *no;
        public  :
                Student(char*  name,int  age  ,  char*  no);
                char* getName(){
                    return name;
                }
                int getAge(){
                    return age;
                }
                char* getNo(){
                    return no;
                }
    int my_strlen(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void my_strcpy(char* dest, const char* src) {
        int i = 0;
        while ((dest[i] = src[i]) != '\0') {
            i++;
        }
    }
};

Student::Student(char*  na,int  ag  ,  char*  n)
{
    name=new char[my_strlen(na)+1];
    no=new char[my_strlen(n)+1];
    age=ag;
    my_strcpy(name,na);
    my_strcpy(no,n);
}

int  main()
{
        char  name[20];
        int  age;
        char  no[20];
        cin  >>  name  >>  age  >>  no;
        Student  stu(name,  age,  no);
        cout<<"Name:"<<stu.getName()<<"  Age:"<<stu.getAge()<<"  No:"<<stu.getNo()<<"\n";
        return  0;
}