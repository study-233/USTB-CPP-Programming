/* 12. 开灯问题 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    int light[n+1]={};  //0表示关
    for(int i=1;i<=k;i++){
        int off_light=i;
        while(off_light<=n){
            light[off_light]^=1;    //按下开关 0，1变换
            off_light+=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(light[i]==1) cout<<i<<" ";
    }
}

