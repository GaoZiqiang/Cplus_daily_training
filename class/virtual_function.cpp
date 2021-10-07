// 虚函数、虚函数表指针、虚函数表

#include "apue.h"

class Base {
    // size 4
private:

public:
    // size 0
    void func() {}

    // size 8
    // virtual function
    // 看不见的成员变量--虚函数表指针
    // pubic:
    // void *vptr;// 虚函数表指针(virtual table pointer)--8个字节

    // 虚函数的生成时机和生成原因
    // 生成时机：当类中存在一个虚函数>=1时 虚函数表virtual table for A

    // 虚函数表指针被赋值的时间
    // 在构造器中 编译器为vptr赋值
    // vptr = &A::vftable;
    virtual void vfunc() {
        printf("Base类的vfunc()\n");
    }

    // 类对象在内存中的布局

};

class Derived : public Base {
private:

public:
    void func() {}
    virtual void vfunc() {
        printf("Derived类的vfunc()\n");
    }
};

int main() {
    Base base;
    printf("sizeof(base)： %d\n", sizeof(base));

    Derived derived;
    printf("sizeof(derived)： %d\n", sizeof(derived));

    // 多态
    // 父类指针指向子类对象
    Base *base1 = new Derived();
    base1->vfunc();

    // 父类引用绑定子类对象
    Derived derived1;
    Base &base2 = derived1;
    base2.vfunc();

}