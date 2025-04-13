/**/
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n,p;
    cin>>n;
    p=n-1;
    if(n<=1) cout<<'N';
    while(p>1){
        if(n%p==0){
            cout<<'N';
            break;
        }
        p--;
    }
    if(p==1) cout<<'Y';
}
