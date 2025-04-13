#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int x;      //8进制数
    int y=0;      //10进制数
    int a[100];     //存储8进制数各个位数
    cin>>x;
    
    //用栈的思想
    int i=0;
    while(x){           //从低位开始入栈
        a[i]=x%10;
        x/=10;
        i++;
    }
    int j=i-1;

    while(j>=0){        //从高位开始出栈
        y=y*8+a[j];
        j--;
    }
    cout<<y;
}