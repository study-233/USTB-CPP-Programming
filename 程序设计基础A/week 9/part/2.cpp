/* 计算机将数据进行升序排列(从小到大) */
/* 在函数中创建动态数组保存数据 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void mySort(int*& pa,int n){
    pa = new int[n];
    for(int i=0;i<n;i++){
        cin>>pa[i];
    }
    for(int i=n-1;i;i--){
        for(int j=0;j<i;j++){
            if(pa[j]>pa[j+1]){
                int temp=pa[j];
                pa[j]=pa[j+1];
                pa[j+1]=temp;
            }
        }
    }
}
int main(){
    freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int  i,n;
    int *  a  =  0;
    cin  >>  n;
    mySort(a,  n);
    for(i=0;i<n;i++)
    cout<<a[i]<<"  ";
    cout<<endl;
    delete  [] a;
    return  0;
}
