/* 8. 发工资 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int num(int n){
    int count=0;
    while(n){
        if(n>=100) n-=100;
        else if(n>=50) n-=50;
        else if(n>=10) n-=10;
        else if(n>=5) n-=5;
        else if(n>=2) n-=2;
        else n-=1;
        count++;
    }
    return count;
}
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n,sum=0;
    cin>>n;
    int slary[n];
    for(int i=0;i<n;i++){
        cin>>slary[i];
    }
    for(int i=0;i<n;i++){
        sum+=num(slary[i]);
    }
    cout<<sum;
}

