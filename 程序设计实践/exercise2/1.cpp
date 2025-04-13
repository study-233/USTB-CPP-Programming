/**/
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    char* str=new char[4000];
    char* st=new char[4000];    
    int flag=0,count=0;
    cin>>str>>st;
    int lstr=strlen(str);
    int lst=strlen(st);
    for(int i=0;i<=lstr-lst;i++){
        if(str[i]==st[0]){
            flag=1;
            for(int j=0;j<lst;j++){
                if(str[i+j]!=st[j]){
                    flag=0;
                    break;
                }
            }
            if(flag) count++;
        }
    }
    cout<<count;
}
