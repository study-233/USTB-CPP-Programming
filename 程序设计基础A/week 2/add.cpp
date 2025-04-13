#include <iostream>
using namespace std;
int Add(int x,int y);

int Add(int x,int y)
{
    return x+y;
}

int main()
{
    int x,y,z;
    cin>>x>>y;
    z=Add(x,y);
    cout<<z;

    return 0;
}
