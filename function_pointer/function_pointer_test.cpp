// 测试函数指针
// 函数指针的本质--一个变量
// 参考：https://www.zhihu.com/zvideo/1433792635044048898

#include <iostream>

using namespace std;

// 定义函数指针
typedef void(*func_ptr)(int);

// 待引用函数指针的函数
void func(int param) {
    cout << "this is func(), and param = " << param << endl;
}

void func1() {
    func_ptr func_p = &func;// 引用函数func()
    (func_p)(5);// 不解引用调用func()
    (*func_p)(5);// 解引用调用func()
}

void func2() {
    long a = (long)&func;// 获取func()函数的地址--将其赋值给long a--地址本身也是一个长整型数
    (*(func_ptr)a)(52);// 解引用调用func()--先进行一个地址类型转换
}

int main() {
    func1();
//    func2();
}