#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(){
int y=0,x=10,time=100,p=1;
while(1){

    for(int i=0;i<y;i+=p) cout<<"\n";
    for(int i=0;i<x;i++) cout<<" ";
    cout<<"*";
    Sleep(time);    
    system("cls");
    y++;
    if(y==20) p=-1;
    if(y==0) p=1;
}
system("pause");
}
