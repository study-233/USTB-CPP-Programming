/* 6. 字符串反序 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[100];
    cin.get(str,100);
    int len = strlen(str);
    for(int i=0;i<len/2;++i){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    cout<<str;
}

