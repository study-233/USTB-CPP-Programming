#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
    int n,m,line=100,ans;

	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		int mp[n+1];
		for(int i=1;i<=n;i++) cin>>mp[i];
		if(m>=n){
			cout<<100<<endl;
			continue;
		}
		mp[0]=0;
		mp[n+1]=line+1;
		int r=m;
		while(r<=n){
			ans=max(ans,mp[r+1]-mp[r-m]-1); 
			r++;
		}
		cout<<ans<<endl;

	}
	return 0;
}