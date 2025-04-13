/* 4. 相邻字符相等判断 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[80];
    cin.get(str,80);
    char*p = str;
    for(;*p;p++){
        if(*p==*(p+1)){
            cout<<"YES";
            break;
        }
    }
    if(*p==0) cout<<"NO";
}

