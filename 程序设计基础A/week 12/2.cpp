/**/
#include <bits/stdc++.h>
using namespace std;
class Point{
   public:
    Point(int xx=0, int yy=0)  {X=xx;Y=yy;} //构造函数
    Point(const Point &p); //复制构造函数
    int GetX() {return X;}
    int GetY() {return Y;}
    private:
    int X,Y;
};
   
Point::Point(const Point &p){
    X=p.X;
    Y=p.Y;
}
   
void fun1(Point p){
    cout<<p.GetX()<<endl;
}
   
Point fun2(){
    Point A(1,2);
    return A;
}
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    Point A(4,5);
    Point B(A);
    cout<<B.GetX()<<"\n";
    fun1(B);
    B=fun2();
    cout<<B.GetX();
}


