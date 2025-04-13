#include<iostream>
#include<cmath>
using  namespace  std;
int  is_prime(int  x)
{
int n;
n=x-1;
while(n*n>=x){
        if(x%n==0){
            return 0;
        }
        n--;
}
if(x==1) return 0;
return 1;

}
int  main()
{
        int  i,m;
        cin  >>  m;
        for(i  =  m-2;  i  >=  3;  i--)
        if(is_prime(i)  &&  is_prime(i+2))
        {
                cout  <<  i  <<  "  "  <<  i+2;
                break;
        }
        return  0;
}