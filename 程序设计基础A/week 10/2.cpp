/* 2. 在字符数组中查找指定字符 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[50];
    cin.get(str,50);
    if(strchr(str,'s') != NULL) cout<<strchr(str,'s')-str;
    else cout<<-1;
}

