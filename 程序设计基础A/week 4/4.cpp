#include <iostream>

using namespace std;

const float R = 8.5;

#define  PI  3.14159

int main()

{

 float a,b;

 a= 2 * PI * R;

 b=PI * R * R;

 cout << "圆周长=" << a <<",圆面积=" << b << endl;

 return 0;

}