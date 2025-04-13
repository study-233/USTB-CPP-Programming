#include<iostream>
#include<cstring>
using  namespace  std;
float  factorial(int  n)
{
    static  int  product=1;
    
if(n==1) return 1;
product=factorial(n-1)*n;

    return  product;
}
  int  main()
  {
          int  n=1;
          float  sum=0,temp;
          do  {
                
temp=(n+1)/factorial(n);
sum+=temp;
n++;

        }while(temp>1e-6);
        cout<<sum<<endl;
        return  0;
  }