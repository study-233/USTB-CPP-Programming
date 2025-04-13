#include  <iostream>
using  namespace  std;
int  compute(int  n,  int  k)  
{
        
if(k==1) return n;

        else  
        {
        
return compute(n-1,k-1)*n/k;

        }
}
int  main()
{
        int  m,  n;
        cin  >>  m  >>  n;
        cout  <<  compute(m,  n);
        return  0;
}