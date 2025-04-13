#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__
#include <bits/stdc++.h>
#include "date.h"
using namespace std;


class Accumulator{
    private:
        Date lastDate;      //记录上一次的日期
        double value;       //记录余额
        double sum;         //日累加
    public:
        Accumulator(const Date &date,double value);        //初始化
        double getSum(const Date &date) const {return sum;};       
        void change(Date &date,double value);    
        void reset(const Date &date,double value);
};

#endif