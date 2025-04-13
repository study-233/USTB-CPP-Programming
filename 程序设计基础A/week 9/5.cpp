/* 5. 找出连续4个数之和最大的一段 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int x,i=0;
    int a[1000];
    while(1){
        cin>>x;
        if(x==-1) break;    
        else a[i]=x;
        i++;
    }
    if(i>3){
    int len=i;
    int max=a[0]+a[1]+a[2]+a[3],p=1;
    int j=1;
    while(j<len){
        int temp=0;
        for(int i=0;i<4;i++){
            temp+=a[(j+i)%len];
        }
        if(max<temp){
            p=(j+1)%len;
            max=temp;
        }
        j++;
    }
    cout<<p<<" "<<max;
    }
    else cout<<"invalid input";
}

