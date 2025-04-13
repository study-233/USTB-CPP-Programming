#include <iostream>
using namespace std;
double xiaqi(int m,int n){ // 从（m,n）格处向后退，寻找路径，到达（1，1）
    if(m==1){
        if(n==1) 
        return 1; //到达（1，1） 返回 1 ，代表一条路径
        else
        return xiaqi(m,n-1); //到达（1，*) 只能向左移动
    }
    else{
        if(n==1)
        return xiaqi(m-1,n); //到达（*。1) 只能向上移动
        else
        return xiaqi(m-1,n)+xiaqi(m,n-1); //可以向左或者向上
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<xiaqi(m,n);
}