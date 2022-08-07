// c++父类虚函数被子类虚函数覆盖后，如何直接调用父类的虚函数？

#include <iostream>

using namespace std;

class fa{
public:
    virtual void show(){cout << "fa" << endl;}
};

class son : public fa{
public:
    void show(){cout << "son" << endl;}
};

typedef void (*func)(void);

int main()
{
    son boy;
    fa * ptrfa;
    ptrfa = &boy;

    fa one;
    fa two;

    /******测试信息******/
//    printf("子类show函数地址%x\n", *(int *)*(int *)&boy);
//    printf("父类show函数地址%x\n", *(int *)*(int *)&one);
//    printf("父类show函数地址%x\n", *(int *)*(int *)&two);

//    int showptr = 0x42d970;    //这个值反汇编得来的，每次编译可能不同，这是fa::show函数的真正内存所在
//    func fff;
//    memcpy((char *)&fff, (char*)&showptr, sizeof(int));
//    fff();
    /************/


    //如下调用
    // 父类的虚函数被子类覆盖后，若指针强行调用父类的虚函数，编译器直接帮你在函数所在区找到函数，
    // 直接调用call，简单暴力而优雅......
    (*ptrfa).fa::show();
    return 0;
}