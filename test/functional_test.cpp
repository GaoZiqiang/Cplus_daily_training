/*std::function 是一种通用、多态的函数封装，它的实例可以对任何可以调用的目标实体进行存储、复制和调用操作，
 * 它也是对 C++中现有的可调用实体的一种类型安全的包裹（相对来说，函数指针的调用不是类型安全的），简而言之，
 * std::function 就是函数的容器。*/
#include<iostream>
#include<functional>

int foo(int x, int y)
{
    return x+y;
}

int main()
{
    //function包装了一个返回值为int，参数为两个int类型的函数
    std::function<int (int,int)> func = foo;
    std::cout << func(10,20) << std::endl;
}