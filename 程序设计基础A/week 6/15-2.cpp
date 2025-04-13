#include <iostream>
using namespace std;
int main(){
int x,y=0,count;
cin>>count;
for (int i = 0; i < count; i++){
    cin>>x;
    if(x>y){
    y=x;
    }  
}
cout<<y;
} 