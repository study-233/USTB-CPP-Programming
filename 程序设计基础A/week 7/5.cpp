#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n){
        cout<<n%10;
        n/=10;
    }
}


