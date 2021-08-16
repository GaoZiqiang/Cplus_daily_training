// funtemp.cpp--函数模板

// 为什么使用函数模板
// 答：如果需要将同一算法用于不同类型的函数，可使用函数模板。

// 工作原理：
// 使用泛型来定义函数，通过将类型作为参数传递给模板，可使编译器生成该类型的函数，并在程序中使用。

// 定义一个函数模板:

//template <typename AnyType>// template <class T>
//void Swap(AnyType &a, AnyType &b) {
//    Anytype temp;
//    temp = a;
//    a = b;
//    b = temp;
//}

#include <iostream>

using namespace std;

// 声明函数原型--模板并非函数定义
template <typename T>
void Swap(T &a, T &b);

template <typename T>
void printName(T x);

int main() {
    // 显式实例化
    template void Swap<char>(char &, char &);// 报错了

    int i = 10;
    int j = 20;
    // 隐式实例化--生成特定类型的函数定义
    Swap(i,j);// 编译器生成Swap()的一个实例--生成函数定义，该实例使用int类型
    cout << "Now i, j = " << i << j <<endl;

    double x = 24.5;
    double y = 81.7;
    Swap(x,y);// 编译器生成Swap()的一个实例，该实例使用double类型--该模板实例是一个函数定义
    cout << "Now x, y = " << x << y <<endl;

    char g = 'g';
    char h = 'h';
    Swap(g,h);
    cout <<"Now g, h = " << g << "," << h << endl;

    printName(x);
}

template <typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void printName(T x){
    cout << "name is " << x << endl;
}