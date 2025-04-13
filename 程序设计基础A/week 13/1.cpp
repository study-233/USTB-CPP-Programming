#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

class A{
public: 

    static int count;//用来统计构造函数被调用的次数

    A(){count++;}
	int showcount(){
	return count;
	};
	
};

int A::count=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int _ = 1;
	cin>>_;	//Don't forget this!
	
	A a;
	cout<<a.showcount()<<endl;
	A b;
	cout<<b.showcount();
	
	return 0;
}