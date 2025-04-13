#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n,x;
    cin>>n;
    x=n-1;
    while(x*x>=n){
        if(n%x==0){
            cout<<"NO";
            break;
        }
        x--;
    }
    if(n==1) cout<<"NO";
    else if(x*x<n) cout<<"YES";
}