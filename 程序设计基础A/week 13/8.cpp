/**/
#include <bits/stdc++.h>
using namespace std;
class MyRectangele{
    private:
        int xUp,yUp,xDown,yDown;
    public:
        void getW();
        void getH();
        void Area();
        MyRectangele(){
            xUp=0;
            yUp=0;
            xDown=0;
            yDown=0;
        }
        MyRectangele(int,int);
};
MyRectangele::MyRectangele(int xDown_,int yDown_){
    xUp=0;
    yUp=0;
    xDown=xDown_;
    yDown=yDown_;    
}
void MyRectangele::getW(){
    if((xDown-xUp)>(yDown-yUp)) cout<<"width="<<yDown-yUp<<" ";
    else cout<<"width="<<xDown-xUp<<" ";
}
void MyRectangele::getH(){
    if((xDown-xUp)>(yDown-yUp)) cout<<"height="<<xDown-xUp<<" ";
    else cout<<"height="<<yDown-yUp<<" ";
}
void MyRectangele::Area(){
    cout<<"area="<<(xDown-xUp)*(yDown-yUp);
}
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int xDown,yDown;
    cin>>xDown>>yDown;
    MyRectangele r1(xDown,yDown);
    r1.getW();
    r1.getH();
    r1.Area();
}
