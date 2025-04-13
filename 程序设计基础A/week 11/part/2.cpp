#include <bits/stdc++.h>
using namespace std;
struct  Person  {
    char  name[20];
    long  id;
    float  salary;
};

Person  allone[6]={{"jone",12345,339.0},{"david",13916,449.0},{"marit",27519,311.0},{"jasen",42876,623.0},{"peter",23987,400.0},{"yoke",12335,511.0}};

int  main()
{
    Person  *temp;
    int  i,j;
    Person*  index[6];
    //初始化索引数列
    for(i=0;i<6;i++){
        index[i] = allone+i;
    }
    //排序
    for(i=1;i<6;i++){
        for (j=0;j<6-i;j++){
            if(index[j]->salary > index[j+1]->salary){
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }


    for(int  k=0;k<6;k++){
        cout  <<  index[k]->name  <<  "  "<<  index[k]->id  <<  "  "  <<  index[k]->salary  <<  endl;        
    }
    return  0;
}