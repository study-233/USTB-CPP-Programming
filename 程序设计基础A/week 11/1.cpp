/* 1. 小球第n次反弹的高度 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    double height = 100 ;
    int n;
    cin>>n;
    while(n){
        height/=2;
        n--;
    }
    cout<<height;
}

