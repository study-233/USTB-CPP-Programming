#include <iostream>
#include <stdio.h>
using namespace std;
int count=0;
int cal_step(int n){
    if(n==1){
        cout<<endl;
        return count;
    }
    else if(n%2==0){
        n/=2;
        cout<<n<<" ";
        count++;
        return cal_step(n);
    }
    else{
        n=3*n+1;
        cout<<n<<" ";
        count++;
        return cal_step(n);
    }
    
}
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n;
    cin>>n;
    cout<<cal_step(n);
}
