/**/
#include <bits/stdc++.h>
using namespace std;
class Point{
    public:
        virtual void print(){
            cout<<"This is Point"<<endl;
        }
};
class Point3d:public Point{
    public:
        void print(){
            cout<<"This is 3D Point";
        }
};
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    Point point;
    Point3d point3d;
    point.print();
    point3d.print();
    return 0;

}
