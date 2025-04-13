#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a,b,c,d,x1,x2,jp,ip;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if(d==0){  
        x1 = -b/(2*a);
        cout<<"has two equal roots:"<<endl<<"x1=x2="<<x1;
    }
    if(d>0){
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        cout<<"has two real roots:"<<endl<<"x1="<<x1<<","<<"x2="<<x2;
    }
    if(d<0){
        jp = 0-b/(2*a);
        ip = sqrt(-d)/(2*a);
        cout<<"has two complex roots:"<<endl;
        cout<<"x1="<<jp<<"+"<<ip<<"i"<<endl;
        cout<<"x2="<<jp<<"-"<<ip<<"i";
    }

}
