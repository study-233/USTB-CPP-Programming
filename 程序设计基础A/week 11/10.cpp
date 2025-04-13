/* 10. 折半查找 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int a[]={1, 3, 5, 7, 9, 11, 13, 15,17, 19};
    int l=0;
    int r=9;
    int key;
    cin>>key;
    while (l<=r){
        int k = (l+r)/2;
        if(a[k]==key){cout<<"yes";break;}
        else if(a[k]<key) l=k+1;
        else r=k-1;
    }
    if(l>r) cout<<"no";
    return 0;
}

