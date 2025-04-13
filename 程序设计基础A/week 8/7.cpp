#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int year,N;
    cin>>year>>N;
    while(N){
        if(((year%4==0)&&!(year%100==0))||year%400==0){
            N--;
        }
        year++;
    }
    cout<<year-1;

}
