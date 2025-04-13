#include <iostream>
using namespace std;
int main(){
int begin=1,end=0,i=0;
while(i!=5){
    end=begin;
    while(i!=5){
        if(end%5==1){
            i++;
            end=end/5*4;
        }
        else {
            i=0;
            begin++;
            break;
        }
    }
}
cout<<begin;
    




}
