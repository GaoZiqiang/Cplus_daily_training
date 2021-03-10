#include <iostream>

#pragma once

using namespace std;

class Time{
private:
    int hours;
    int minutes;
public:
    Time();// 默认构造器
    Time(int h,int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0,int m = 0);
    Time sum(const Time & t) const;// 求和
    void Show() const;
};