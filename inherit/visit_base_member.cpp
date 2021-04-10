/*visit_base_member.cpp --访问基类成员*/
// 面对两个问题 二义性问题和冗余
// 1 基基同名时--二义性问题 解决方法：基类名::成员
// 2 基派同名时--同名隐藏,优先使用本派生类成员 无需解决
#include <iostream>

using namespace std;

class Base1 {// 基类Base1
public:
    int var;
    void fun() {cout << "Member of Base1" << endl;}
};

class Base2 {// 基类Base2
public:
    int var;
    void fun() {cout << "Member of Base2" << endl;}
};

class Derived : public Base1,public Base2 {
public:
    int var;// 与基类同名数据成员
    void fun() {cout << "Member of Derived" << endl;}// 与基类同名函数成员
};

int main() {
    Derived d;
    Derived *p = &d;

    d.var = 1;// 选择调用本派生类成员 默认的
    d.fun();

    d.Base1::var = 2;// 使用作用域分辨标识符
    d.Base1::fun();// 访问Base1基类成员

    d.Base2::var = 3;
    d.Base2::fun();
}