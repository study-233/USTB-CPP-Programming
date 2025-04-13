/*2. 在一维数组中查找最大值*/
    /* 要求用递归实现 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int max(int* a,int low,int high);

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<max(a,0,n-1);
}

int max(int* a,int low,int high){   
    if(low==high) return a[low];    //输出值
    int mid = (low+high)/2;     //取中值 mid
    //  存储左区间最大值和右区间最大值
    int maxl=max(a,low,mid);
    int maxr=max(a,mid+1,high);
    //  返回最大值
    if(maxl>maxr) return maxl;
    return maxr;

}
