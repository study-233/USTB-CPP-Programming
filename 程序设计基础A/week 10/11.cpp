/* 11. 查找最大元素 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[200];
    cin.get(str,200);
    int max = 'a';

    for(int i=0;str[i];++i){
        if(str[i]>max){
        max = str[i];
        }
    }
    
    for(int i=0;str[i];++i){
        cout<<str[i];
        if(str[i]==max) cout<<"(max)";   
    }
}