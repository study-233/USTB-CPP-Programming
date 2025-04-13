#include <iostream>
using namespace std;
int sushu(int x){
    if(x==1) return false;
    for(int i=x-1;i>1;i--){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int oushu,p;
    cin>>oushu;
    for(p=oushu;p>=oushu/2;p--)
        if(sushu(p)&&sushu(oushu-p)) cout<<p<<" + "<<oushu-p<<" ="<<oushu<<endl;

    return 0;
    
}
