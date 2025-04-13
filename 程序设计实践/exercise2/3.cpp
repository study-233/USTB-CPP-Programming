/**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Func(int *A, int nSize){
    sort(A,A+nSize);
    int p=nSize;
    for(int i=nSize-1;i>=0;i--){
        cout<<A[i]<<" ";
        if(A[i]==0 && p==nSize) p=i;
    }
    cout<<endl;
    return nSize-p-1;
}

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int A[10000];
    int i=0;
    while(cin>>A[i]) i++;
    cout<<Func(A,i);
    return 0;
}