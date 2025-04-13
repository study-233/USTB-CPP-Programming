#include <iostream>
using namespace std;

class my_base{
        int a,b;
    public:
        my_base(int x,int y){
            a=x;
            b=y;
        }
        virtual void show(){   //定义虚函数show()
            cout<<a<<" "<<b<<endl;
        }
};
class my_class:public my_base{
    int c;
    public:
        my_class(int a_,int b_,int c_):my_base(a_,b_),c(c_){}
        void show(){
            my_base::show();
            cout<<c;
        }
};
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    my_class m(a,b,c);
    m.show();
}