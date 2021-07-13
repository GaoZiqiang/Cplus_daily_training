#include <iostream>
using namespace std;
class A
{
public :
    // 验证虚函数和普通方法重载的不同
    void eat() {
    cout << "A's eat()" << endl;
}

    virtual void foo()
    {
        cout << " A's foo() " << endl;
        bar();
    }
    virtual void bar()
    {
        cout << " A's bar() " << endl;
    }
};
class B: public A
{
public :
    // 验证虚函数和普通方法重载的不同
    void eat() {
    cout << "B's eat()" << endl;
}
    void foo()
    {
        cout << " B's foo() " << endl;
//        A::foo();
    }
    void bar()
    {
        cout << " B's bar() " << endl;
    }
};
int main()
{
    B bobj;// 派生类对象
    A * aptr;// 基类指针
    aptr = & bobj;// 将基类指针指向派生类对象
    // 验证虚函数的作用
    // 如果在基类中没有将foo()方法声明为虚方法,aptr -> foo()将根据指针的类型(A *)调用A::foo()
    // 因此在编译时可以将foo()关联到A::foo()

    // 如果在基类中将foo()方法声明为虚方法,aptr -> foo()将根据对象的类型(B)B::foo()
    // 在程序执行时将foo()关联到B::foo()
    aptr -> foo();// 执行的是B::foo()
    // 验证虚函数和普通方法重载的不同
    aptr -> eat();// 执行的是A::eat()
//    A aobj = * aptr; //转化为A类对象
//    aobj.foo();
}
