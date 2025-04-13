/* 3. 桶排序 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define NUM 100
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int bucket[NUM]={};
    int x;
    for(int i=0;i<10;i++){
        cin>>x;
        bucket[x]+=1;
    }
    for(int i=0;i<NUM;i++){
        while(bucket[i]){
            cout<<i<<" ";
            bucket[i]--;
        }
        
    }
}

