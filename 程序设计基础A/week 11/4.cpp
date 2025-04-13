/* 4. 荷兰国旗问题 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    char inStr[256];
    char* str[100];
    int count=0;
    cin.getline(inStr,256);
    str[count] = strtok (inStr," ");
    while(str[count] != NULL){
        count++;
        str[count] = strtok (NULL," ");
    }
    for(int i=0;i<count-1;i++){
        int p=i;
        for(int j=i;j<count;j++){         
            if(strlen(str[j])==3 || strlen(str[p])==4) p=j;
        }
        char* temp = str[i];
        str[i] = str[p];
        str[p] = temp;
    }
    for(int i=0;i<count;i++){
        cout<<str[i]<<" ";
    }
}
