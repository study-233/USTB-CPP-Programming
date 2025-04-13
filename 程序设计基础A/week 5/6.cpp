#include <iostream>
using namespace std;
int main()
{
    int head,feet,t;
    cin>>head>>feet;
    for(t=head;t>=0;t--)
        if(((head-t)*2+t*4)==feet) cout<<"rabbit="<<t<<",chicken="<<head-t;

} 