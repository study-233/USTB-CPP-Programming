/* 1. 比较两个字符串是否相同 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char a[100];
    char b[100];
    cin.getline(a,100);
    cin.getline(b,100);
    if(strcmp(a,b)) cout<<"NO";
    else cout<<"YES";

}

