/**/
#include <bits/stdc++.h>
using namespace std;
int a[]={10, 22, 46, 55, 60, 70, 88, 89, 90, 99};
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int key=60;
    int l=0,r=9;
    while(l<=r){
        int mid=(l+r)/2;    
        if(a[mid]==key){
            cout<<mid+1;
            break;
        }
        else if(a[mid]<key){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(l>r) cout<<"Not find";
}
