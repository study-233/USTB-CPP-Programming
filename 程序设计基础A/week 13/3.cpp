#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
class Clock

{

public:

 void SetTime(int NewH=0, int NewM=0, int NewS=0);

 void ShowTime();

private:

 int Hour,Minute,Second;

};



void Clock::SetTime(int NewH, int NewM, int NewS)

{

 Hour=NewH;

 Minute=NewM;

 Second=NewS;

}



inline void Clock::ShowTime()

{

 cout<<Hour<<":"<<Minute<<":"<<Second<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int _ = 1;
	cin>>_;	//Don't forget this!
	
	Clock myClock;
    myClock.SetTime(8,30,30);
    myClock.ShowTime();
	
	return 0;
}