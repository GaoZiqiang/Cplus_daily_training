#ifndef TEMPLATE2_LIB_H_
#define TEMPLATE2_LIB_H_
#include <iostream>

using std::cout;

// 库开发人员
class Library {
public:
    Library() {}
    virtual ~Library() {}// 虚析构函数

public:
    void run() {
        step1();

        step2();// 支持变化-->虚函数的多态调用

        step3();

        step4();// 支持变化-->虚函数的多态调用

        step5();
    }

protected:
    void step1() {
        cout << "lib step1\n";
    }

    void step3() {
        cout << "lib step3\n";
    }

    void step5() {
        cout << "lib step5\n";
    }

    // 虚函数
    virtual void step2() = 0;
    virtual void step4() = 0;
};
#endif