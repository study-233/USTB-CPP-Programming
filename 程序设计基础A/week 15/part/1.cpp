#include<iostream>
#include<string.h>
const  double  pi=3.14;  //定义常量pi
using  namespace  std;
class  circle
{
        //写成纯虚函数
    double radius;
public:
    virtual void setradius(double r){ radius = r; }
    virtual double getarea(){ return pi * radius * radius; }

};
class  table
{        
    double height;
public:
    void setheight(double h){ height = h; }
    double getheight(){ return height; }

};
class  roundtable:public  circle,public  table
{
    string color;
public:
    void setcolor(string c){ color = c; }
    string getcolor(){ return color; }

};
int  main()
{
    roundtable rt;
    double r, h;
    string c;
    
    cin >> r >> h >> c;

    rt.setradius(r);
    rt.setheight(h);
    rt.setcolor(c);

    cout << rt.getarea() << endl;
    cout << rt.getheight() << endl;
    cout << rt.getcolor() << endl;

        return  0;
}