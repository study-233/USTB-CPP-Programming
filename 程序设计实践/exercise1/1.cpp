/**/
#include <bits/stdc++.h>
using namespace std;
int a[16];
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string x;
    cin>>x;
    for(int i=0;i<16;i++){
        a[i]=x[i]-'0';
    }
    int ans=0;
    if(a[0]==0){
        for(int i=0;i<16;i++){
            ans=ans*2+a[i];
        }
        cout<<ans;
    }
    else{
        for(int i=0;i<16;i++){
            ans=ans*2+(a[i]+1)%2;
        }
        ans++;
        cout<<-ans;
    }

}
