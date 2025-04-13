#include <iostream>
using namespace std;
int main(){
char x;
cin>>x;
if((x<='Z'&&x>='A')||(x<='z'&&x>='a')) cout<<"char";
if(x<='9'&&x>='0') cout<<"digit";
if((!((x<='Z'&&x>='A')||(x<='z'&&x>='a')))&&(!(x<='9'&&x>='0'))) cout<<"other";



} 