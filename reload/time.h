/*运算符重载，可简化接口设计，统一运算*/
/*类的友元函数，访问权限与成员函数相同的非成员函数*/
/*方法和友元只是表达接口的两种不同机制*/
#ifndef TIME_H_
#define TIME_H_

#include <iostream>
#include <fstream>

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
    friend Time operator+(Time & t1,const Time & t2) { return t1 + t2;};
    // 重载减法运算符
    Time operator-(const Time & t) const;

    // 重载乘法运算符 实现倍数mult在右边 A = B * 2
    Time operator*(double n) const;// n为要乘以/增加的倍数
    // 乘法友元函数 实现倍数mult在左边 A = 2 * B 友元函数不属于类的成员函数，但是可以访问类的成员变量
    // 解释：这里的t*m中的m位于右边，相当于调用了上边那个乘法重载，实际上是将上边的乘法友元函数函数作为了内联函数
    friend Time operator*(double m,const Time & t) { return t * m;}

    // 重载<<运算符 使用ostream参数和Time参数，但是是Time类的友元函数，而不一定是ostream类的友元函数
    friend ostream & operator<<(ostream & os,const Time & t);

    void Show() const;
};
#endif