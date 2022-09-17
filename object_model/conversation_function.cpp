#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

class Fraction {
public:
    Fraction(int num, int den) : m_numerator(num), m_denominator(den) {}
    // 转换函数
//    operator double() const {
//        return (double(m_numerator) / double(m_denominator));
//    }

    operator int() const {
        return m_numerator + m_denominator + 1;
    }

    operator string() const {
        char buf1[10], buf2[10];
        snprintf(buf1, 10, "%d", m_numerator);
        printf("buf1: %s\n", buf1);
        snprintf(buf2, 10, "%d", m_denominator);
        printf("strcat: %s\n", string(strcat(buf1, buf2)));
        return string(strcat(buf1, buf2));
    }

private:
    int m_numerator;// 分子
    int m_denominator;// 分母
};

int main() {
//    Fraction f(3, 5);
//    double d = 4 + f;
//
//    printf("d = %f\n", d);
//    cout << "d = " << d << endl;
//    char buf[10];
//    int a = 100;
//    snprintf(buf, 10, "%d", a);
//    printf("buf: %s\n", buf);

//    Fraction st(3, 5);
//
//    int res = 10 + st;

//    printf("res: %d\n", res);
    Fraction st(3, 5);
//    printf("st: %f\n", st);
////
    string tst = "hello";

    string res = tst + st;
//////
//    string stt = strcat(tst, st.c_str());

//    string a = "hello";
//    string b = "world";
//    string c = a + b;

    shared_ptr sp = new Fraction(3, 5);

}