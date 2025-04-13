/* 7. 公共子序列 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    char s1[1000];
    char s2[1000];
    char t[100];
    cin>>s1>>s2>>t;
    int s1len=strlen(s1);
    int s2len=strlen(s2);
    int tlen=strlen(t);
    int flag1=0,flag2=0;
    for(int i=0;i<=s1len-tlen;i++){
        int j=0;
        for(;j<tlen;j++){
            if(s1[i+j] != t[j]) break;
        }
        if(j==tlen){
            flag1=1;
            break;
        }
    }
    for(int i=0;i<=s2len-tlen;i++){
        int j=0;
        for(;j<tlen;j++){
            if(s2[i+j] != t[j]) break;
        }
        if(j==tlen){
            flag2=1;
            break;
        }
    }
    if(flag1 && flag2) cout<<"yes";
    else cout<<"no";
}

