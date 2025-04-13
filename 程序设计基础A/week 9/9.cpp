/* 9. 数字组合 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    for(int i=123;i<=329;i++){  //确保不会产生4位数
        int a[10]={};   //标识9个数字是否都被使用
        int temp=i;
        for(int j=0;j<3;j++){
            a[temp%10]=1;
            a[temp/100]=1;
            a[temp/10%10]=1;
            temp+=i;
        }
        int sum=0;
        for(int i=1;i<10;i++){
            sum+=a[i];
        }
        if(sum==9){
            cout<<i<<" "<<i*2<<" "<<i*3<<endl;
        }
    }
}

