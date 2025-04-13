/* 7. 逆向输出一个数 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char a[20];
    int p;
    cin>>a;
    p=strlen(a)-1;
    while(p>=0){
        cout<<a[p];
        p--;
    }
}
