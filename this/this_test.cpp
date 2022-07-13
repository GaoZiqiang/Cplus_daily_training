#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <argz.h>
#include <typeinfo>

using namespace std;

class A
{
public:
    int get() const{return i;}
    void set(int x){this->i=x;cout<<"this指针保存的内存地址为:"<<this<<endl;}
    static void show() {cout << "static A::show(): " << __func__ << __LINE__ << endl;}
private:
    int i;
};

int main()
{
    A a;
    a.set(9);
    cout<<"对象a所在的内存地址为:"<<&a<<endl;
    cout<<"对象a所保存的值为:"<<a.get()<<endl;
    A::show();
    cout << "typeid(A::show()).name():" << typeid(A::show()).name() << endl;
    cout << "typeid(a.get()).name():" << typeid(a.get()).name() << endl;

    cout<<endl;
    A b;
    b.set(999);
    cout<<"对象b所在的内存地址为:"<<&b<<endl;
    cout<<"对象b所保存的值为:"<<b.get()<<endl;
    return 0;
}