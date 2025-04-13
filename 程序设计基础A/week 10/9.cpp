/* 9. 加密 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[100];
    cin.get(str,100);
    for(int i=0;str[i];++i){
        if('A'<=str[i] && str[i]<='Z') cout<<char((str[i]-'A'+3)%26+'A');
        else if('a'<=str[i] && str[i]<='z') cout<<char((str[i]-'a'+3)%26+'a');
        else cout<<str[i];
    }
}
