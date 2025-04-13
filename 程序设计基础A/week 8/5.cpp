#include <iostream>
#include <stdio.h>
using namespace std;
int jiecheng(int x){
    if(x>1) return jiecheng(x-1)*x;
    return 1;
}
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<n<<"!="<<jiecheng(n);

}