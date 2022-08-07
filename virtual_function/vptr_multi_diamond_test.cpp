// 多继承&&菱形继承时虚函数表测试

#include <iostream>
using namespace std;

typedef void(*FUNC)();
class Base
{
public:
    virtual void func1()
    {
        cout << "Base::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base::func2()" << endl;
    }
private:
    int _b;
};

class Parent1 :public Base
{
public:
    virtual void func1()
    {
        cout << "Parent1::func1()" << endl;
    }
    virtual void func3()
    {
        cout << "Parent1::func3()" << endl;
    }
    virtual void func4()
    {
        cout << "Parent1::func4()" << endl;
    }
    virtual void func5()
    {
        cout << "Parent1::func5()" << endl;
    }
private:
    int _p1;
};

class Parent2 :public Base
{
public:
    virtual void func1()
    {
        cout << "Parent2::func1()" << endl;
    }
    virtual void func3()
    {
        cout << "Parent2::func3()" << endl;
    }
    virtual void func6()
    {
        cout << "Parent2::func6()" << endl;
    }
    virtual void func7()
    {
        cout << "Parent2::func7()" << endl;
    }
private:
    int _p2;
};

class Child :public Parent1, public Parent2
{
public:
    virtual void func1()
    {
        cout << "Child::func1()" << endl;
    }
    virtual void func3()
    {
        cout << "Child::func3()" << endl;
    }
    virtual void func4()
    {
        cout << "Child::func4()" << endl;
    }
    virtual void func6()
    {
        cout << "Child::func6()" << endl;
    }
    virtual void func8()
    {
        cout << "Child::func8()" << endl;
    }
private:
    int _c;
};

void PrintVfptr(int* vptr)
//打印虚函数表
{
    cout << "虚函数表: " << vptr << endl;
    for (int i = 0; vptr[i] != 0; ++i)
    {
        printf("第%d个虚函数：%p  >> ", i, vptr[i]);
        FUNC f = (FUNC)(vptr[i]);
        f();
    }
}
void Test()
{
    Base b;

    Parent1 p1;
    Parent2 p2;

    Child c;

    int* vptr_B = (int*)(*(((int*)(&b))));

    int* vptr_P1 = (int*)(*(((int*)(&p1))));

    int* vptr_P2= (int*)(*(((int*)(&p2))));

    PrintVfptr(vptr_B);
    cout << endl;

    PrintVfptr(vptr_P1);
    cout << endl;

    PrintVfptr(vptr_P2);
    cout << endl;

    int* vptr_C_1 = (int*)(*(((int*)(&c))));
    int* vptr_C_2 = (int*)(*(int*)((char*)(&c) + sizeof(Parent1)));

    PrintVfptr(vptr_C_1);
    cout << endl;
    PrintVfptr(vptr_C_2);
    cout << endl;
}
int main()
{
    Test();
    system("pause");
    return 0;
}