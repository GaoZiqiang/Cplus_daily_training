// 手动实现memcopy()函数

#include <cstddef>
#include <iostream>

template <typename T>
void* memcopy(void* dest, const void* src, size_t count) {// 优化：srr地址不可修改
    void* destCopy = dest;// 不能在dest上进行赋值操作

    while (count-- > 0) {
        *(T*)destCopy++ = *(T*)src++;
//        (T*)destCopy++;
//        (T*)src++;
    }

    return dest;
}

// 测试
int main() {
//    // int类型
//    int* dest = new int[100];
//    int* src = new int[10];
//
////    src = "abcdef";
//    src[0] = 1;
//    src[1] = 2;
//    src[2] = 3;
//    src[3] = 4;
//
//
//    memcopy<int>(dest, src, 10);
//    std::cout << dest[0] << std::endl;
//    std::cout << dest[1] << std::endl;
//    std::cout << dest[2] << std::endl;
//    std::cout << dest[3] << std::endl;

    // char类型
    char* dest = new char[100];
    char* src = new char[10];

    src = "abcdef";


    memcopy<char>(dest, src, 10);
    std::cout << dest << std::endl;

    return 0;
}
