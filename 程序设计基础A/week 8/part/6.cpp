#include  <iostream>
using  namespace  std;
int  sumNumbers(int  x)
{
        if  (x  <  10)
              return  x;
        else
              
return x%10+sumNumbers(x/10);

}
int  main()
{
        int  x;
                cin  >>  x;
                cout  <<  sumNumbers(x);
}