/* 6. 判断集合是否相等 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    //存储集合A,B的值
    int A;
    cin>>A;
    int a[A],a1[A]={};
    for(int i=0;i<A;i++){
        cin>>a[i];
    }
    int B;
    cin>>B;
    int b[B],b1[B]={};
    for(int i=0;i<B;i++){
        cin>>b[i];
    }
    //判断集合内相同的元素
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            if(a[i]==b[j]){
                a1[i]=1;    //相同即记为1
                b1[j]=1;
            }
        }
    }
    //统计相同的元素
    int temp1=0,temp2=0;
    for(int i=0;i<A;i++){
        temp1+=a1[i];
    }
    for(int i=0;i<B;i++){
        temp2+=b1[i];
    }
    //如果全部元素相同即输出yes
    if(temp1==A&&temp2==B) cout<<"yes";
    else cout<<"no";
}

