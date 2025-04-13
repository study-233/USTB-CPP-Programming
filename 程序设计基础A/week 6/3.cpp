#include <iostream>
using namespace std;
int main(){
char grade;
cin>>grade;
switch(grade)
{
    case('A'): cout<<"85~100";break;
    case('B'): cout<<"70~84";break;
    case('C'): cout<<"60~69";break;
    case('D'): cout<<"0~60";break;
}
if(grade<'A'||grade>'D') cout<<"error";


} 