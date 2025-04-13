/**/
#include <bits/stdc++.h>
using namespace std;
class DATE{
    public:
        int year,month,day;
        void set_date(int,int,int);
        void disp_date();
};
void DATE::set_date(int year_,int month_,int day_){
    year=year_;
    month=month_;
    day=day_;
}
void DATE::disp_date(){
    cout<<year<<'.'<<month<<'.'<<day;
}
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int year,month,day;
    DATE date0;
    cin>>year>>month>>day;
    date0.set_date(year,month,day);
    date0.disp_date();
}
