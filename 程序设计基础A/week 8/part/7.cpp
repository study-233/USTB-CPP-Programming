#include  <iostream>
using  namespace  std;
int mod(int a,int b){
return a%b;
}

int mod(double a,double b){
int c,d;
if(a<0) c=(int)(a-0.5);
else c=(int)(a+0.5);
if(b<0) d=(int)(b-0.5);
else d=(int)(b+0.5);
return c%d;
}

int  main(){
        cout<<"mod(8,3)="<<mod(8,3)<<endl;
        cout<<"mod(8.2,3.6)="<<mod(8.2,3.6)<<endl;
        cout<<"mod(-8.2,-2.6)="<<mod(-8.2,-2.6)<<endl;
        return  0;
}