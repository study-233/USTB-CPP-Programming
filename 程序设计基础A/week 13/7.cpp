/**/
#include <bits/stdc++.h>
using namespace std;
class Rational{
    private:
        int x,y;
    public:
        int age,weight;
        Rational(int x_=0,int y_=1): x(x_),y(y_){}
        void Add(Rational,Rational);
        void Sub(Rational,Rational);
        void Mul(Rational,Rational);
        void Div(Rational,Rational);
        void Print();
        void PrintFloat();
};
void Rational::Add(Rational a,Rational b){
    x=a.x*b.y + a.y*b.x;
    y=a.y*b.y;
}
void Rational::Sub(Rational a,Rational b){
    x=a.x*b.y - a.y*b.x;
    y=a.y*b.y;
}
void Rational::Mul(Rational a,Rational b){
    x=a.x*b.x;
    y=a.y*b.y;
}
void Rational::Div(Rational a,Rational b){
    x=a.x*b.y;
    y=a.y*b.x;
}
void Rational::Print(){
    cout<<x<<"/"<<y<<endl;
}
void Rational::PrintFloat(){
    cout<<double(x)/y<<endl;
}
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin>>x>>y;
    Rational r1(x,y);
    cin>>x>>y;
    Rational r2(x,y);
    Rational r3;
    r3.Add(r1,r2);
    r3.Print();
    r3.Sub(r1,r2);
    r3.PrintFloat();
    r3.Mul(r1,r2);
    r3.Print();
    r3.Div(r1,r2);
    r3.PrintFloat();

}
