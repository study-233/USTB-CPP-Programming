#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    if(x>=90) cout<<"A";
    if(x>=80&&x<90) cout<<"B";
    if(x>=70&&x<79) cout<<"C";
    if(x>=60&&x<69) cout<<"D";    
    if(x<60) cout<<"E";    
} 