/**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=10005;
int n;
int x,y,z;
ll X[10005],Y[10005],Z[10005],nums[10005],num;

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>X[i]>>Y[i]>>Z[i];
	}
	for(int j=0;j<n;j++){
        num=0;
        for(int i = 0 ; i < n ; ++i){
            num += abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + abs(Z[j] - Z[i]);
        }
        nums[j]=num;
    }
    sort(nums,nums+n);

    cout<<nums[0];
    return 0;
}