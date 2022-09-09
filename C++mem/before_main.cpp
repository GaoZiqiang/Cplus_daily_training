// 实现在main函数之前执行一段代码

/*
 * 在main函数之前执行代码
 * 想要知道如何在main函数之前执行代码，首先就要搞明白，在面函数之前，程序到底做了啥？
 * 简单来说，main函数之前，主要做了这些：
 *  1 配置堆栈
 *  2 初始化静态和全局变量
 *  3 为未初始化部分的全局变量赋值
 *  4 运行全局构造器
 *  5 将main函数的参数（argv，argc等）传递给main函数
 *
 * 这些基本都是变量、环境的配置。因此，如果想执行一段代码，最简单的办法就只有一个了：利用构造函数。
 * 大方向敲定，那么剩下的小细节无非就是类放在哪的问题了。
 *  1 全局变量
 *  2 静态变量
 *  3 include文件中的全局或静态变量
 *  4 namespace中
 *
 * */
#include <bits/stdc++.h>

using namespace std;

class A{
public:
    A(){
        cout << "before main()" << endl;
    }
    ~A(){
        cout << "after main()" << endl;
    }
};

A a; //全局变量

int main(){
    cout << "this is in main()" << endl;
    return 0;
}
