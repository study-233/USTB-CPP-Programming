#include <iostream>
using namespace std;
int main()
{
    int x,t;
    cin>>x;
    if(x/100000)
    {
        cout<<"a bad number";
    }
    else
    {
        for(t=10000;t;t/=10)
        {
            if(x/t) 
            cout<<t<<":"<<x/t%10<<" ";
        }

    }
    return 0;
}