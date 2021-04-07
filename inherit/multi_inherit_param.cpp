/*multi_inherit_param.cpp --多继承构造器以及析构函数*/
// 规则
// 派生类名::派生类名(参数表):
// 基类名1(基类1初始化参数表)
// 基类名2(基类2初始化参数表)
// ... ...
// 基类名n(基类n初始化参数表)
// 本类成员初始化列表
// {}
#include <iostream>

using namespace std;

class Base1 {// 基类Base1，构造函数有参数
public:
    Base1(int i) {cout << "Constructing Base1 " << i << endl;}
    ~Base1() {cout << "Destructing Base1" << endl;}
};

class Base2 {// 基类Base2，构造函数有参数
public:
    Base2(int j) {cout << "Constructing Base2 " << j << endl;}
    ~Base2() {cout << "Destructing Base2" << endl;}
};

class Base3 {// 基类Base3，构造函数没有参数
public:
    Base3() {cout << "Constructing Base3 " << endl;}
    ~Base3() {cout << "Destructing Base3" << endl;}
};

class Derived : public Base2,public Base1,public Base3 {// 注意基类的顺序
public:
    Derived(int a,int b,int c,int d) : Base1(a),member2(d),member1(c),Base2(b) {}// 因为Base3构造器没有参数
private:
    Base1 member1;
    Base2 member2;
    Base3 member3;
};

int main() {
    Derived obj(1,2,3,4);
    return 0;
}

