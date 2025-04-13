/* 9. 蛇形填数 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int n;
    cin>>n;
    int a[n][n];
    int row = 0;
    int col = n-1;
    int left=0,top=0;
    int right=n-1,bottom=n-1;
    int i=1;
    while(i<=n*n){
        row=top;
        while(row<=bottom){
            a[row++][right]=i++;}
        right--;
        col=right;
        while(col>=left){
            a[bottom][col--]=i++;}
        bottom--;        
        row=bottom;
        while(row>=top){
            a[row--][left]=i++;}
        left++;
        col=left;
        while(col<=right){
            a[top][col++]=i++;}
        top++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
}

