/* 10. 亲和数 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    int m1=0,n1=0;
    if(n>m){    //保证m>n
        int temp;
        temp=n;
        n=m;
        m=temp;
    }
    for (int i = 1; i < m; i++){    //遍历寻找约数
        if(n%i==0 && n!=i) n1+=i;
        if(m%i==0) m1+=i;
    }
    if(m1==n && n1==m) cout<<"YES";
    else cout<<"NO";
}

