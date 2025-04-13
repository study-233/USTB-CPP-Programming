/* 8. 0～99之间的一串随机数 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int seed,b,c,m;
    cin>>seed>>b>>c>>m;
    int a[5];
    a[0]=seed;
    for(int n=1;n<5;n++){
        a[n]=(b * a[n-1]+c)%m;
    }
    for(int n=0;n<5;n++){
        cout<<"a"<<n<<"  "<<a[n]<<endl;
    }
}

