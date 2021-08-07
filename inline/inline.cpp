#include <iostream>

// 内联函数定义
inline double square(double x) { return x * x;}// 整个函数的定义放在一行

int main() {
    using namespace std;

    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "c++ squared: " << square(c++) << endl;// 线先计算square(c)，再做c++
    cout << "Now c1:" << c << endl;
    cout << "++c squared: " << square(++c) << endl;
    cout << "Now c2:" << c << endl;
}