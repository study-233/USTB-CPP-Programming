#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void GetArea()=0;
};
class Rectangle:public Shape{
    private:
        float l,w;
    public:
        Rectangle(float l_=0,float w_=0): l(l_),w(w_){};
        void GetArea(){
            cout<<l*w<<endl;
        }
};
class Circle:public Shape{
    private:
        float r;
    public:
        Circle(float r_=0):r(r_){};
        void GetArea(){
            cout<<3.14*r*r<<endl;
        }
};
class Square:public Rectangle{
    public:
    Square(float l_):Rectangle(l_,l_){};
};
int main() 
{ 
    float x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    Circle c1(x1);
    Rectangle r1(x2,x3);
    Square s1(x4);
    c1.GetArea();
    r1.GetArea();
    s1.GetArea();
}