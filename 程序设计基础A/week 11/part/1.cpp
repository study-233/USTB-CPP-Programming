/* 1. 学生信息基本操作（结构体）*/
#include <bits/stdc++.h>
using namespace std;
struct Student{
    int num;
    string name;
    int score;
};
void  output_message(Student  stu);
void  output_title();

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int  n;
    cout<<"The  number  of  student:"<<endl;
    cin>>n;

    //从键盘读入n个学生的数据，并累加总成绩
    Student* stu = new Student[n];
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>stu[i].num>>stu[i].name>>stu[i].score;
        sum+=stu[i].score;
    }

    //输出显示全部学生的信息和全班平均分
    cout<<"\nAll  students:\n";
            output_title();
    for(int i=0;i<n;i++){
        output_message(stu[i]);
    }    
    cout<<"\naversge=\n"<<sum/n<<endl;

    //查找最高分和最低分学生并输出显示其信息
    int max=0,min=0;
    int a[n],j=0;
    for(int i=0;i<n;i++){
        if(stu[i].score>stu[max].score) max=i;
        else if(stu[i].score<stu[min].score) min=i;
        if(stu[i].score<60){
            a[j]=i;
            j++;
        }
    }
    if(j>0){
        cout<<"\nFail students:\n";
        output_title();
        for(int i=0;i<j;i++){
        output_message(stu[a[i]]);
        }
    }
    cout<<"max_score student:\n";
    output_title();
    output_message(stu[max]);
    cout<<"min_score student:\n";
    output_title();
    output_message(stu[min]);   
    return  0;
}
void  output_title(){
        cout<<setw(10)<<"Number"<<setw(10)<<"Name"<<setw(10)<<"Score\n";
}
void  output_message(Student  stu){
        cout<<setw(10)<<stu.num<<setw(10)<<stu.name<<setw(10)<<stu.score<<endl;
}  