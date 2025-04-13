/* 3. 删除字符串中的字符 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[100];
    cin.get(str,100);
    while(strchr(str,'T') != NULL){     //当 str 中有 T 时
        for(char* p = strchr(str,'T');*p;p++){      //把 T 后的字符向前移动
            *p = *(p+1);
        }
    }
    cout<<str;
}

