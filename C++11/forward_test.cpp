// 左值引用 右值引用
// 完美转发

#include <iostream>
using namespace std;

//重载被调用函数，查看完美转发的效果
void otherdef(int & t) {// 左值引用--实参应为左值
    cout << "lvalue\n";
}
void otherdef(const int & t) {// 右值引用--实参应为右值/或者通过move(左值)函数
    cout << "rvalue\n";
}

//实现完美转发的函数模板
template <typename T>
void function(T&& t) {// 这里T&&根据传入的实参类型，将引用推导为左值引用或右值引用
    otherdef(forward<T>(t));// forward<T>(t)函数根据T的类型，将t转换为左值或右值
}

int main()
{
    function(5);// 实参为右值 T&&推导为右值引用
    int x = 1;
    function(x);// 实参为左值 T&&推导为左值引用
    return 0;
}