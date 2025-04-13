#include <iostream>
using namespace std;
double jiecheng(int x){
    if(x>1) return jiecheng(x-1)*x;
    return 1;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<jiecheng(m+n-2)/jiecheng(m-1)/jiecheng(n-1);

}