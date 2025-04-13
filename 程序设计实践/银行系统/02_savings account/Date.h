#ifndef __DATE_H__
#define  __DATE_H__


class Date{
    private:
        int year;
        int month;
        int day;
        int totalDays;
    public:
        Date(int date,int month,int day);
        void show();
        int getMaxDay() const;       //获得当月有多少天
        bool isLeapYear() const{      //判断当年是否为闰年
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        }
        int distance(const Date& date) const{   //计算两个日期之间是多少天
            return totalDays - date.totalDays;
        }
        int getYear() const { return year; }
        int getMonth() const { return month; }
        int getDay() const { return day; }
};


#endif
