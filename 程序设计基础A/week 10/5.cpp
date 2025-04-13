/* 5. 字符串中的大小写字母的替换 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[100];
    cin.get(str,100);
    for(char*p = str;*p;p++){
        if('a'<=*p && *p<='z') cout<<(char)('A'+(*p-'a'));
        else if('A'<=*p && *p<='Z') cout<<(char)('a'+(*p-'A'));
        else cout<<*p;
    }
}

