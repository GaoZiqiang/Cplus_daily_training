// 多继承时虚函数表测试

#include <iostream>
using namespace std;

typedef void(*FUNC)();
class Base
{
public:
    virtual void func1() = 0;
    virtual void func2() = 0;
};

class Base1:public Base
{
public:
    virtual void func1()
    {
        cout << "Base1::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base1::func2()" << endl;
    }
private:
    int _b1;
};

class Base2: public Base
{
public:
    virtual void func1()
    {
        cout << "Base2::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base2::func2()" << endl;
    }
private:
    int _b2;
};


class Derive : public Base1, public Base2
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

void PrintVfptr(Base* b)
{
    int* vTable1 = (int*)(*(int*)b);
    cout << "虚函数表指针:" << vTable1 << endl;
    for (int i = 0; vTable1[i] != 0; ++i)
    {
        printf("第%d个虚函数指针: %p   >>", i, vTable1[i]);
        FUNC f = (FUNC)vTable1[i];
        f();
    }
    //int* vTable2 = (int*)(*((int*)b + sizeof(Base1) / 4));
    int* vTable2 = (int*)(*((int*)((char*)b + sizeof(Base1))));
    cout << "虚函数表指针:" << vTable2 << endl;
    for (int i = 0; vTable2[i] != 0; ++i)
    {
        printf("第%d个虚函数指针: %p   >>", i, vTable2[i]);
        FUNC f = (FUNC)vTable2[i];
        f();
    }
}

void Test()
{
    Base1 b1;
    Base2 b2;
    Derive d;
    PrintVfptr(&b1);
    cout << endl;
    PrintVfptr(&b2);
    cout << endl;
    PrintVfptr((Base1*)&d);
}

int main()
{
    Test();
    system("pause");
    return 0;
}