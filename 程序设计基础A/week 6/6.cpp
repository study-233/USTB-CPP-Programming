#include <iostream>
using namespace std;
int main(){
double x,weight;
cin>>x>>weight;
if(x==1) cout<<weight*12.5;
if(x==2) cout<<weight*20.5;
if(x==3) cout<<weight*10.4;
if(x==4) cout<<weight*17.5;
if(x>4||x<1) cout<<"none";
} 