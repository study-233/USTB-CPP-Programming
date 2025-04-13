/* 12. 周期串 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[80];
    cin.get(str,80);
    int cycle=1;
    int len=strlen(str);
    while(cycle<=len){
        int flag=1;
        if(len%cycle==0){
            for(int j=0;j<len-cycle;j=j+cycle){
                for(int i=0;i<cycle;i++){
                    if(str[j+i] != str[j+i+cycle]) flag=0;
                }
            }
            if(flag){
                cout<<cycle;
                break;
            }
        }
        cycle++;
    }
    


}

