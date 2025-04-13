#include <iostream>
using namespace std;
int lifang(int n){
    if(n>1) return lifang(n-1)+n*n*n;
    if(n==1) return 1;
    return 0;
}
int main(){
    int n;
    cin>>n;
    cout<<lifang(n);
}
