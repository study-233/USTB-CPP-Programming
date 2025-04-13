/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

char s[25][25];
int maps[25][25];
int i,j,w,h,ans;
int a,b;
void dfs(int i,int j)
{
    maps[i][j]=1;
    if(i+1<h&&s[i+1][j]=='.'&&maps[i+1][j]==0){
        ans++;
        dfs(i+1,j);
    }
    if(j+1<w&&s[i][j+1]=='.'&&maps[i][j+1]==0){
        ans++;
        dfs(i,j+1);
    }
    if(i-1>=0&&s[i-1][j]=='.'&&maps[i-1][j]==0){
        ans++;
        dfs(i-1,j);
    }
    if(j-1>=0&&s[i][j-1]=='.'&&maps[i][j-1]==0){
        ans++;
        dfs(i,j-1);
    }
}

int main()
{
    while(cin>>w>>h){
        ans=1;
        memset(maps,0,sizeof(maps));
        
        for(i=0;i<h;i++)
            cin>>s[i];
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(s[i][j]=='@'){
                    a=i;b=j;
                }
            }
        }
        dfs(a,b);
        cout<<ans;
    }
    return 0;
}