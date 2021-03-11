/*运算符重载，可简化接口设计，统一运算*/
#ifndef TIME_H_
#define TIME_H_

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
    //Time sum(const Time & t) const;
    // 重载加法运算符
    Time operator+(const Time & t) const;// 转换为一个适用于Time类的加法重载运算符
    // 重载减法运算符
    Time operator-(const Time & t) const;
    Time operator*(double n) const;// n为要乘以/增加的倍数
    void Show() const;
};
#endif