#include <iostream>
using namespace std;

int main()

{

    int x=0165,a=323,b=-1;

    char c;
    c=a;
    cout << "x=" << x << endl;
    cout << "c=" << c << endl;
    cout <<"a:"<< a <<","<< hex << a <<"," << oct << a << endl;
    cout <<"b:"<< dec << b << ","<< hex << b <<",";cout << oct << b <<","<< dec << (unsigned) b << endl;

    return 0;

}