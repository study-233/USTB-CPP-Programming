#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double  area(double  a  =  4.0,double  b  =  5.0,double  c  =  6.0);
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
        double  a  =  4.0,b  =  5.0,c  =  6.0;
        cout<<area(a)<<endl;
        cout<<area(a,b)<<endl;
        cout<<area(a,b,c)<<endl;
        return  0;
}
double  area(double  a,double  b,double  c){  
    double s;
    s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
