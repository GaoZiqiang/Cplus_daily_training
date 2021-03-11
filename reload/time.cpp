#include <iostream>
#include "time.h"

using namespace std;

Time::Time(){
    hours = minutes = 0;
}

Time::Time(int h,int m){
    hours = h;
    minutes = m;
}

void  Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}
// 加法重载运算符
Time Time::operator+(const Time &t) const {
    Time sum;// 创建临时对象
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;

    return sum;// 函数返回值为Time对象
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1,tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.hours = (tot2 - tot1) / 60;
    diff.minutes = (tot2 - tot1) % 60;

    return diff;
}

Time Time::operator*(double mult) const {
    Time result;
    long totalminutes = hours * 60 * mult + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;

    return result;
}

void Time::Show() const {
    cout << hours << " hours," << minutes << " minutes";
}
