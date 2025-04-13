/* 7. 连接两个字符串 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char s1[100];
    char s2[100];
    cin.getline(s1,100);
    cin.getline(s2,100);
    strcat(s1,s2);
    cout<<s1;
}

