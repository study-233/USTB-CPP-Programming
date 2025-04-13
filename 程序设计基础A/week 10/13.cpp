/* 13. 按字母顺序输出城市名清单 */
/* 动态申请指针数组 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n;
    cin>>n;
    char** p = new char*[n];    
    for (int i = 0;i<n;i++){
        char str[10];
        cin>>str;
        *(p+i) = new char[10];
        strcpy(*(p+i),str);
    }
    for (int i = 0;i<n-1;i++){
        if (strncmp(*(p+i),*(p+i+1),1)>0){
            char* tp = *(p+i);
            *(p+i) = *(p+i+1);
            *(p+i+1) = tp;
        }
        else if (strncmp(*(p+i),*(p+i+1),1) == 0){
            if (strcmp(*(p+i),*(p+i+1))>0){
                char* tp = *(p+i);
                *(p+i) = *(p+i+1);
                *(p+i+1) = tp;
            }
        }
    }
    for (int i = 0;i<n;i++){
        cout<<*(p+i)<<endl;
    }
 
    for (int i = 0;i<n;i++){
        delete []*(p+i);
    }
    delete []p;
    return 0;
}

