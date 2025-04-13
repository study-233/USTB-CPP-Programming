//date.h
#ifndef __DATE_H__
#define  __DATE_H__

#include <iostream>
using namespace std;

class Date{
    private:
        int year;
        int month;
        int day;
        int totalDays;

    public:

        Date() = default;
        Date(int date,int month,int day);


        string show() const;

        //判断当年是否为闰年
        bool isLeapYear() const{
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        }

        int getYear() const { return year; }
        int getMonth() const { return month; }
        int getDay() const { return day; }

        //获得当月有多少天
        int getMaxDay() const{
            static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
            
            if (month==2 && isLeapYear()){
                return 29;
            }
            return MonthDay[month];
        }

        static Date read();

        //重置运算符

        Date& operator+=(int day);
        Date operator+(int day);

        Date& operator-=(int day);
        Date operator-(int day);


        //++d，前置++
        Date& operator++();
        //d++，后置++
        Date operator++(int);
        //前置--
        Date& operator--();
        //后置--
        Date operator--(int);

        //两个日期相减：d1-d2
        int operator-(const Date& d);

        bool operator<(const Date& d)const;
        bool operator<=(const Date& d);
        bool operator>(const Date& d);
        bool operator>=(const Date& d);
        bool operator==(const Date& d);
        bool operator!=(const Date& d);

};

class DateException : public exception {
    public:
        const char *what() const noexcept override{
            return "日期错误，请重新输入";
        }
};

#endif  //__DATE_H__
