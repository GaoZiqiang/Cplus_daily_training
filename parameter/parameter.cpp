/*formal_parameter.cpp --测试值传递和引用传递*/
#include <iostream>

int value_fact(int val) {
    int ret = 1;

    while(val > 1) {
        ret *= val--;
    }

    //输出ret，证明值传递不改变形参
    // std::cout << "val is " << val << std::endl;

    return ret;
}

int cation_fact(int &val) {
    int ret = 1;

    while(val > 1) {
        ret *= val--;
    }

    //输出ret，证明值传递不改变形参
    // std::cout << "val is " << val << std::endl;

    return ret;
}

int pointer_fact(int *val) {
    int ret = 1;

    while(*val > 1) {
        ret *= *val--;
    }

    //输出ret，证明值传递不改变形参
    // std::cout << "val is " << val << std::endl;

    return ret;
}

// 常量引用--不想拷贝，但又不想改变引用对象的值
// 比较两个string对象的长度
bool isShorter(const string &s1,const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    int val = 3;
    value_fact(val);
    //输出val，证明值传递不改变形参
    std::cout << "val after passing by value is " << val << std::endl;

    // 输出&val，证明引用传递不会改变指针的地址
    std::cout << "address of val before is " << &val << std::endl;
    cation_fact(val);// 引用传参的形式与指针传参不一样
    // 输出val，证明引用传递改变形参
    std::cout << "val after passing by ciation is " << val << std::endl;
    std::cout << "address of val after is " << &val << std::endl;

    // 输出&val，证明指针传递不会改变指针的地址
    std::cout << "address of val before is " << &val << std::endl;
    // 输出val，证明指针传递改变形参
    pointer_fact(&val);
    std::cout << "val after passing by pointer is " << val << std::endl;
    std::cout << "address of val after is " << &val << std::endl;


    return 0;
}
