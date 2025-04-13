/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int N,L;
    cin >> N >> L;
    int tree[N];
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }
    sort(tree,tree + N);
    for(int i = tree[0]; i < tree[N]; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(tree[j] > i){
                sum += tree[j] - i;
            }
        }
        if(sum == L){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

