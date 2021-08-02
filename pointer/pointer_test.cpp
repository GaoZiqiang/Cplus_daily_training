#include <stdio.h>
#include <iostream>

using namespace std;

int main() {



    int updates = 6;
    /*错误示范*/
    //int* p_updates = updates;// 错误，原因：指针p_updates还未初始化，因此还不能赋值
    int* p_updates;
    p_updates = &updates;


    printf("updates: %d\n",updates);
    printf("p_updates: %d\n",*p_updates);

    printf("address of updates: %0x\n",&updates);
    printf("value of p_updates: %0x\n",p_updates);

    updates += 1;
    printf("new updates: %d\n",updates);
    printf("new p_updates: %d\n",*p_updates);

    *p_updates = updates;
    *p_updates += 1;
    printf("new new updates: %d\n",updates);
    printf("new new p_updates: %d\n",*p_updates);

    printf("address of updates: %0x\n",&updates);
    printf("value of p_updates: %0x\n",p_updates);

//    p_updates += 0x0000000000000001;
//    printf("new value of p_updates: %0x\n",p_updates);


    printf("address of p_updates: %0x\n",&p_updates);


    int *pt = &updates;

    long fw = 100000000;
    //long* fellow = NULL;// 指针初始为NULL在g++编译器中不行
    long *fellow;
    fellow = new long;
    //fellow = &fw;

    *fellow = 10000000000;// 常量2333333的地址未知，因此此时的指针变量*fellow相当于野指针

    printf("fellow: %0x\n",fellow);
    printf("*fellow: %lld\n",*fellow);
//
     delete(fellow);// delete用于删除动态分配的内存
    //printf("address of 2333333: %0x\n",&2333333);

//    int a = 10;
//    printf("address of a: %0x\n",&a);
    double persons[4] = {0.1,0.32,0.11,0.474};
    printf("persons: %f\n",persons[0]);
//    persons = {0.1,0.32,0.11,0.474};


    /*关于重复delete的问题*/
    int* p = new int;
    printf("address of p: %0x\n",p);
    *p = 5;
    printf("value of *p: %d\n",*p);
    delete p;// delete删除/抹除的只是p指针指向的内存空间的内容，而其指向的内存空间的地址不变
    printf("address2 of p: %0x\n",p);
    printf("value of *p: %d\n",*p);
    // 因为第一次delete p之后，p指针指向的内存空间的内容已经被抹除，因此再delete一次会出错
    //delete p;  //本句会导致程序出错

    int ducks = 12;
    int* birddog;
    birddog = &ducks;
    // int* birddog = &ducks;
    printf("birddog: %0x\n",birddog);
    printf("&birddog: %0x\n",&birddog);

    // 将整数赋值给指针 直接讲一个地址赋值给指针
    int* pts;
    pts = (int*)0xB8000000;// 强制类型转换
    printf("pts: %0x\n",pts);
    // printf("*pts: %d\n",*pts);

    int aa = 10;
    int* paa = &aa;
    *paa = (int)10.2;

    printf("*paa: %d\n",*paa);



    /* new分配内存
     * delete释放内存空间
     *
     * 切记/易错点：
     * 使用delete作用的是指针所指向的地址，而不是指针本身，即，delete删除的是指针所指向的内存（里的东西），并不会删除指针本身
     * 指针本身（那个地址）还是存在的，被删除的是那个地址里的东西
     *
     * 要点：
     * 1 new和delete要配对使用，否则会发生内存泄漏
     * 2 不可重复释放已经释放的内存
     * 3 不能使用delete释放 声明变量 所获得的内存
     * 4 对空指针使用delete也是安全的
     * */
    int* ps = new int;
    *ps = 1001;

    printf("*ps: %d\n",*ps);
    printf("ps before deleting: %0x\n",ps);

    /*释放掉ps指向的内存--注意是释放指针ps指针所指向的内存，而不是删除指针ps本身*/
    delete ps;
    // 释放掉ps指向的内存后，ps所指向的内存的地址不变
    printf("ps after deleting: %0x\n",ps);
    // 重复释放
    //delete ps;// 因为第一次delete p之后，p指针指向的内存空间的内容已经被抹除，因此再delete一次会出错

    /*使用delete释放声明变量所获得的内存*/
    int jugs = 5;
    int * pi = &jugs;
    // delete pi;

    /*空指针--地址为0/值为0的指针成为空指针*/
    int* ppnull = NULL;
    printf("ppnull: %0x\n",ppnull);
    // delete空指针
    delete ppnull;

    /*验证delete删除的是指针所指向的内存空间，而不是指针本身*/
    int * pss = new int;
    *pss = 10;
    int * pq = ps;// 指针pq和pss指向同一块内存

    printf("*pps before deleting pq: %d\n",*pss);
    delete pq;
    printf("*pps after deleting pq: %d\n",*pss);


    /* 使用new来创建动态数组
     * 使用new创建数组：
     * 在程序运行阶段需要数组，则创建它；如果不需要要，则不创建。
     * 还可以在程序运行时选择/确定数组的长度。 动态联编。
     *
     * 一、使用new创建动态数组
     *
     * 二、使用指针访问动态数组
     *
     * */

    // new运算符返回第一个数组元素的 地址，并将这个地址赋值给指针psome
    int * psome = new int[3];
    psome[0] = 0;
    psome[1] = 1;
    psome[2] = 2;
    // 访问数组第一个元素的方式就有两种
    printf("num one elem: %d\n",*psome);
    printf("num one elem: %d\n",psome[0]);

    // 指针向后移动一个元素-- 移动4个字节
    psome = psome + 1;
    printf("num one elem after psome + 1: %d\n",*psome);
    printf("num one elem after psome + 1: %d\n",psome[0]);
    // 继续访问其他元素
    printf("num two elem: %d\n",psome[1]);

    // 释放动态数组：delete []psome-- 应释放整个数组，而不仅仅是指针指向的元素
    psome = psome - 1;// 注意：psome一定要重新指向元数组的头--第一个元素的位置--否则在delete时会将第一个元素漏掉
    delete [] psome;// 否则在delete时会将第一个元素漏掉


}