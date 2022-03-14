#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

using namespace std;

class complex {
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}
    complex& operator+=(const complex& r);
    friend ostream& operator<<(ostream& os, const complex& x);// 定义为友元函数
    double real() const {return this->re;}
    double imag() const {return this->im;}
private:
    double re, im;
    friend complex& __doapl(complex*, const complex& r);
};
#endif