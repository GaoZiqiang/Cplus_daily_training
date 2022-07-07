// 虚函数&虚函数指针&虚函数表&静态绑定&动态绑定
// 详情可参考：https://www.bilibili.com/video/BV1MP4y1Y7qQ?spm_id_from=333.999.0.0
#include <iostream>

using namespace std;

class Base {
public:
    Base() {}
    ~Base() {}
//    void print();// 普通函数只声明不定义
    virtual void show() {};// virtual函数只声明不定义
//    virtual void show() {cout << "Base::show()" << endl;};// virtual函数声明且定义
//public:
//    int mm;
//
//protected:
//    int ma;
};

//class Derive : public Base {
//public:
//    Derive(int data) : Base(data), mb(data) {}
//    virtual void show();
//    virtual void show(int) {cout << "Derive::show()" << endl;}
//
//protected:
//    int mb;
//};

int main() {
    Base base;
    cout << "sizeof(base): " << sizeof(base) << endl;
//    Base d(10);
//    Base *pb = &d;
//
//    pb->show();
//    pb->show(50);
//
//    cout << sizeof(Base) << endl;
//    cout << sizeof(Derive) << endl;
//
//    cout << typeid(pb).name() << endl;// class Base*
//    cout << typeid(*pb).name() << endl;// class Derive
}