#include "date.h"
#include <bits/stdc++.h>
using namespace std;

const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };

Date::Date(int year=0,int month=0,int day=0):year(year),month(month),day(day){

    if (day <= 0 || day > getMaxDay()){
        cout << "Invalid date:";
        show();
        cout << endl;
        exit(1);
    }

	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	if (isLeapYear() && month > 2) totalDays++;
};

void Date::show(){
    cout<<year<<'-'<<month<<'-'<<day;
};


int Date::getMaxDay() const
{
		if (isLeapYear() && month == 2)
			return 29;
		else
			return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}



