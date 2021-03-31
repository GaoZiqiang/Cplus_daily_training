#include <iostream>

using namespace std;

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
B::B(int i) {
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
    C(int i,int j);
    ~C();
    void print() const;

private:
    int c;
};

C::C() {
    c = 0;
    cout << "C's default constructor called" << endl;
}
// C的自定义构造函数，需要对继承来的B的构造函数进行传参
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