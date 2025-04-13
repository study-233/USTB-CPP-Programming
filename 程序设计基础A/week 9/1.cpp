/* 1. 考：求最小公倍数 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n,i=0;
    cin>>n;
    int a[n];
    while(cin>>a[i]){
        i++;
    }
    int num=a[0];
    while(1){
        i=0;
        int temp=n;
        int flag=true;
        while(temp){
            if((num%a[i])!=0){  //判断是否为最大公倍数
                flag=false;
                break;
            }
            i++;
            temp--;
        }
        if(flag) break; //如果找到跳出循环
        num++;
    }
    cout<<num;
}

