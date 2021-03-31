/*test.cpp --类的三种继承方式*/
#include <iostream>

using namespace std;

class A {
public:
    void setA(int);
    void showA() const;
private:
    int a;
};

class B {
public:
    void setB(int);
    void showB() const;
private:
    int b;
};

class C : public A,private B {
public:
    void setC(int,int,int);
    void showC() const;
private:
    int c;
};

void A::setA(int x) {
    a = x;
}
void A::showA() const {
    cout << "showA() is " << a << endl;
}

void B::setB(int x) {
    b = x;
}
void B::showB() const {
    cout << "showB() is " << b << endl;
}

void C::setC(int x,int y,int z) {
    // 派生类成员可以直接访问基类的公有成员
    setA(x);
    setB(y);
    c = z;
}
void C::showC() const {
    cout << "a of showC() is ";
    showA();
    cout << "b of showC() is ";
    showB();
    cout << "c of showC() is " << c << endl;
}

int main() {
    C obj;

    obj.setA(1);
    obj.showA();

    obj.setC(1,2,3);
    obj.showC();

    // obj.setB(2);// inaccessible
}