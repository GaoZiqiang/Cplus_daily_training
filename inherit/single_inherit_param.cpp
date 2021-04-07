/*single_inherit_param.cpp --单继承时构造函数的定义语法，派生类的构造器，基类只有一个的情况*/
// 格式如下:
// 派生类名::派生类名(基类所需形参,本类新增成员所需形参):基类名(基类形参列表),本类成员初始化列表
#include <iostream>

using namespace std;

// 基类
class B {
public:
    B();// 默认构造函数
    B(int i);// 自定义构造函数
    ~B();
    void print() const;

private:
    int b;
};

B::B() {
    b = 0;
    cout << "B's default constructor called" << endl;
}
B::B(int i) {// B的自定义够赞函数有一个参数i
    b = i;
    cout << "B's constructor called" << endl;
}
B::~B() {
    cout << "B's destructor called" << endl;
}
void B::print() const {
    cout << "print b:" << b << endl;
}

class C : public B {
public:
    C();
    C(int i,int j);// 其中参数i为基类B的参数，j为本类的参数
    ~C();
    void print() const;

private:
    int c;
};

C::C() {
    c = 0;
    cout << "C's default constructor called" << endl;
}
// C的自定义构造函数，需要对继承来的B的构造函数B(int i)进行传参
// 格式如下:
// 派生类名::派生类名(基类所需形参,本类新增成员所需形参):基类名(基类形参列表),本类成员初始化列表
C::C(int i,int j) : B(i),c(j) {// 问题：为什么用小写的c(j)而不是大写的C(j)?
    cout << "C's constructor called" << endl;
}
C::~C() {
    cout << "C's destructor called" << endl;
}
void C::print() const {
    B::print();
    cout << "print c:" << c << endl;
}

int main() {
    C obj(5,6);
    obj.print();

    cout << "main()函数的最后一句话" << endl;
}