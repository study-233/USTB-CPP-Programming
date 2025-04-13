#include <iostream>
using namespace std;
int main(){
int begin=1,num=0,i=0;
while(1){
num=begin;
for(;i<5;i++){
    if(num%4==0) num=num/4*5+1;
    else{
    i=0;
    break;     
    }
 
}
if(i==5){
cout<<num;
break;
}
else 
num=0;
begin++;
}

}