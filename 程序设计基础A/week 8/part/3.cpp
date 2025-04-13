#include<iostream>
#include<cmath>
using  namespace  std;
int distance(int a1,int b1,int a2,int b2){
return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

double distance(double c1,double d1,double c2,double d2){
return sqrt((c1-c2)*(c1-c2)+(d1-d2)*(d1-d2));
}

int  main()
{
        int  a1,b1,a2,b2;
        cin  >>  a1  >>  b1  >>  a2  >>  b2;
        float  c1,d1,c2,d2;
        cin  >>  c1  >>  d1  >>  c2  >>  d2;
        cout  <<  distance(a1,b1,a2,b2)  <<  endl;
        cout  <<  distance(c1,d1,c2,d2)  <<  endl;
        return  0;
}