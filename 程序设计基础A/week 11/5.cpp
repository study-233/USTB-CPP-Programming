/* 5. 字符串匹配 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    char s[1000];
    char t[100];
    cin>>s>>t;
    int slen=strlen(s);
    int tlen=strlen(t);
    int i=0;
    for(;i<=slen-tlen;i++){
        int j=0;
        for(;j<tlen;j++){
            if(s[i+j] != t[j]) break;
        }
        if(j==tlen){
            cout<<"find at "<<i+1;
            break;
        }
    }
    if(i==slen-tlen+1) cout<<"can't find";
    
}

