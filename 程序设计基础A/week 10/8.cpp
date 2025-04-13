/* 8. 统计字符的出现次数 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[500];
    int num[26]={};
    cin.getline(str,500);
    for(int p=0;str[p];p++){
        if('A'<=str[p] && str[p]<='Z') num[str[p]-'A']++;
        if('a'<=str[p] && str[p]<='z') num[str[p]-'a']++;
    }
    int flag=1;
    for(int i=0;i<26;i++){
        cout<<char('A'+i)<<':'<<num[i]<<',';
        if(flag==10){
            cout<<endl;
            flag=0;  
        }
        flag++;
    }
}

