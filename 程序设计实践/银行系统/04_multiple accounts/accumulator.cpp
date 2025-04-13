#include "accumulator.h"


//就一个构造函数，初始状态余额是0，日累积为0
Accumulator::Accumulator(Date date,double value)
: lastDate(date), value(value), sum(0){}

void Accumulator::change(Date date, double _value) {
    sum=sum+value*date.distance(lastDate);//记录上一个过程中的日累积
    value=_value;//更新余额
    lastDate=date;//更新日期
}

//计算利息后，将日累积归0
void Accumulator::reset(Date date,double _value){
    lastDate=date;
    value=_value;
    sum=0;
}
