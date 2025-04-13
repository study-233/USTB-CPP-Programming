#include <iostream>
#include <stdio.h>
using namespace std;
int mi(int x,int n){
    if(n>1) return mi(x,n-1)*x;
    else return 1;
}
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n,x,sum=0;
    cin>>n;
    int xishu[n];
    for(int i=0;i<n;++i){
        cin>>xishu[i];
    }
    cin>>x;
    for(int i=0;i<n;++i){
        sum+=xishu[i]*mi(x,n-i);
    }
    cout<<sum;
}
