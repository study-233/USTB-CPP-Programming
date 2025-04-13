/* 3. 求平均值 */
/* 使用动态数组存放数据 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n;
    double sum=0;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    for(int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    cout<<sum/n;
}

