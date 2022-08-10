// c++父类虚函数被子类虚函数覆盖后，如何直接调用父类的虚函数？

#include <iostream>

using namespace std;

class fa{
public:
    virtual void show(){cout << "fa" << endl;}
    void print() {cout << "print" << endl;}
};

class son : public fa{
public:
    void show(){cout << "son" << endl;}
};

typedef void (*func)(void);

int main()
{
    son boy;
    fa * ptrfa;
    ptrfa = &boy;

    fa one;
    fa two;

    // 如下调用
    // 父类的虚函数被子类覆盖后，若指针强行调用父类的虚函数，编译器直接帮你在函数所在区找到函数，
    // 直接调用call，简单暴力而优雅......
//    (*ptrfa).fa::show();
    (*ptrfa).fa::print();
    return 0;
}