/* 4. 查找 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int a[8];
    int num;
    for(int i=0;i<8;i++){
        cin>>a[i];
    }
    cin>>num;
    int flag=1;
    for(int i=0;i<8;i++){
        if(num==a[i]){
        cout<<i+1;
        flag=0;
        }
    }
    if(flag) cout<<"cannot find";
}

