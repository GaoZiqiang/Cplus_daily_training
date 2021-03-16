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

    // 测试
    //t.hours = sum.hours;

    return sum;// 函数返回值为Time对象
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1,tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;// 调用对象本身
    diff.hours = (tot2 - tot1) / 60;
    diff.minutes = (tot2 - tot1) % 60;

    return diff;
}

//Time Time::operator*(double mult) const {// 参数mult是待夸大的倍数
//    Time result;
//    long totalminutes = hours * 60 * mult + minutes * mult;
//    result.hours = totalminutes / 60;
//    result.minutes = totalminutes % 60;
//
//    return result;
//}
// 这里是右乘的重载函数的定义 A = B * 2
Time Time::operator*(double mult) const {
    Time result;
    long totalminutes = hours * 60 * mult + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;

    return result;
}

// 友元函数<<的定义 不理解为什么用指针函数
ostream & operator<<(ostream & os,const Time & t) {
    os << t.hours << " hours " << t.minutes << " minutes ";
    return os;
}

void Time::Show() const {
    cout << hours << " hours," << minutes << " minutes";
}
