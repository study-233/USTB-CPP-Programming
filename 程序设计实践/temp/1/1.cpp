/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const short month_day[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool leap_year(int year){
    return year%400 == 0 or (year%4 == 0 and year%100 != 0);
}

int first_day(int year, int month){
    int days = 0;
    for(int i = 1850; i < year; i++)
        days += leap_year(i)? 366: 365;
    for(int i = 1; i < month; i++)
        days += month_day[leap_year(year)][i];
    return ((days+2)%7 == 0)? 7: (days+2)%7;
}

int main(){
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    for(int year = y1; year <= y2; year++){
        int weekday = first_day(year, a), 
            date = 1 + (b-1)*7 + ((c-weekday) >= 0? (c-weekday): (7+c-weekday));
        if(date > month_day[leap_year(year)][a])
            cout << "none" << endl;
        else
            printf("%d/%02d/%02d\n", year, a, date);
    }
    return 0;
}