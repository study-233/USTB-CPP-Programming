/* 11. 猴子选大王 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int m,n;
    cout<<"input m: ";
    cin>>m;
    cout<<"input n: ";
    cin>>n;
    int monkey[m]={};
    int p=0;
    int num=m;
    while(num){     //num表示剩余猴子数
        int count=n;
        while(count){
            if(monkey[p]==0){count--;}  
            p=(p+1)%m;      //保证猴子围成一圈
        }
        monkey[(p-1+m)%m]=1;    //表示猴子出圈
        num--;
    }
    cout<<"king: "<<(p-1+m)%m+1;    // (p-1+m)%m 指向最后一个猴子的下标
}

