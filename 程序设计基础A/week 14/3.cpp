#include<iostream>
using namespace std;
class A 
{ 
public: int n; 
}; 
class B: virtual public A{}; 
class C: virtual public A{}; 
class D:public B,public C 
{ 
    int getn()  	{ return n; } 
}; 
int main() 
{ 
    D d; 
    d.n=10; 
    cout<<d.n<<endl; 
    return 0;
}