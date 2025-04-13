#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
class A{
    public:
        static int count;
        A();
        ~A();
};
int A::count=0;
A::A(){
    count++;
    cout<<count<<endl;
}
A::~A(){
    count--;
    cout<<count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int _ = 1;
	cin>>_;	//Don't forget this!
	
	A a;
	
	return 0;
}