    /**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maps[100][100]={0};
static int res = 0;

void move(int x,int y,int m,int n){
    if(maps[x][y]==1){
        res++;
        maps[x][y]=0;
        if(x>0)
            move(x-1,y,m,n);
        if(y>0)
            move(x,y-1,m,n);
        move(x+1,y,m,n);
        move(x,y+1,m,n);
        
    }

}


int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int m,n;
    cin>>m>>n;
    int x,y;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char s;
            cin>>s;
            switch (s){
            case '.':
                maps[i][j]=1;
                break;
            case '@':
                maps[i][j]=1;
                x=i;y=j;
                break;
            }
        }
    }
    move(x,y,m,n);
    cout<< res;

    return 0;
}
