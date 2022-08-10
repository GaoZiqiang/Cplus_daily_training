// 单继承时虚函数表测试

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

class Derive :public Base
{
public:
    virtual void func1()
    {
        cout << "Derive::func1()" << endl;
    }
    virtual void func3()
    {
        cout << "Derive::func3()" << endl;
    }
    virtual void func4()
    {
        cout << "Derive::func4()" << endl;
    }
private:
    int _d;
};

//打印虚函数表
void PrintVfptr(int* vptr)
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
    Derive d;

    int* vptrBase = (int*)(*(int*)(&b));
    int* vptrDeri = (int*)(*(int*)(&d));

    PrintVfptr(vptrBase);
    cout << endl;
    PrintVfptr(vptrDeri);

}

int main()
{
    Test();
    system("pause");
    return 0;
}