#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    char x;
    char str1[]="`1234567890-=";
    char str2[]="QWERTYUIOP[]\\";
    char str3[]="ASDFGHJKL;'";
    char str4[]="ZXCVBNM,./";
    while(scanf("%c",&x)!=EOF){
        if(x=='`'||x=='Q'||x=='A'||x=='Z'||x==' ') cout<<x;
        else if(strchr(str1,x)!=NULL) printf("%c",str1[strchr(str1,x)-str1-1]);
        else if(strchr(str2,x)!=NULL) printf("%c",str2[strchr(str2,x)-str2-1]);
        else if(strchr(str3,x)!=NULL) printf("%c",str3[strchr(str3,x)-str3-1]);
        else if(strchr(str4,x)!=NULL) printf("%c",str4[strchr(str4,x)-str4-1]);
        else break;
    }
}
