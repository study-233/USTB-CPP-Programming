#include <bits/stdc++.h>
using namespace std;
class Point{    //基类Point类的声明
    public:    //公有函数成员
        void InitP(float xx=0, float yy=0) {X=xx;Y=yy;}
        void Move(float xOff, float yOff) {X+=xOff;Y+=yOff;}
        float GetX() {return X;}
        float GetY() {return Y;}
    private:    //私有数据成员
        float X,Y;
};
class Rectangle:public Point{
    public:
        Point p;
        void Initlw(float l_=0,float w_=0){l=l_;w=w_;}
        float Getl(){return l;}
        float Getw(){return w;}
    private:
        float l;
        float w;

};
int main(){
    float x,y,l,w;
    cin>>x>>y>>l>>w;
    Rectangle R1;
    R1.InitP(x,y);
    R1.Initlw(l,w);
    cin>>x>>y;
    R1.Move(x,y);
    cout<<R1.GetX()<<" "<<R1.GetY()<<" "<<R1.Getl()<<" "<<R1.Getw();

}