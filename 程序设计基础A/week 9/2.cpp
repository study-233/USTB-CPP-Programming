/* 2. 找出最大值和最小值 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int a[8],p=0;
    //存储
    while(cin>>a[p]){
        p++;
    }
    //初始化最大值与下标
    int max=a[0];
    //寻找最大值
    for(int i=0;i<8;i++){
        if(max<a[i]) max=a[i];
    }
    cout<<max<<endl;
    //寻找下标
    for(int j=0;j<8;j++){
        if(max==a[j]) cout<<j<<" ";
    }
}

