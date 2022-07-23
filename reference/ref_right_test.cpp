// 右值引用测试
#include <vector>

void f(int& n) {// 左值引用
    n += 1; // 编译失败，const左值引用不能修改指向变量
}

void f2(int && n) {// 右值引用
    n += 1; // ok
}

int main() {
    int a = 10;
//    f(5);
    f2(std::move(a));
}