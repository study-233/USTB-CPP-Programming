/* 10. 求子串的出现次数 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[100];
    cin.get(str,100);
    int count=0;
    for(int i=0;str[i];++i){
        if(str[i]=='b'&&str[i+1]=='d') count++;
    }
    cout<<count;
}