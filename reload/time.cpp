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

Time Time::sum(const Time &t) const {
    Time sum;// 创建临时对象
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;

    return sum;// 函数返回值为Time对象
}

void Time::Show() const {
    cout << hours << " hours," << minutes << " minutes";
}
