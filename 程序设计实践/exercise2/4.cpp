/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int arry[10];

void move (int *arry, int n, int m){
    while(m){
        int temp=arry[n-1];
        for(int i=n-1;i>0;i--){
            arry[i]=arry[i-1];
        }
        arry[0]=temp;
        m--;
    }
}

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    for(int i=0;i<10;i++){
        cin>>arry[i];
    }
    move(arry,10,3);
    for(int i=0;i<10;i++){
        cout<<arry[i]<<" ";
    }

    return 0;
}
