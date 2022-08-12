// strcopy()仅用于字符串复制

#include <cstddef>
#include <assert.h>
#include <iostream>

char* strcopy(char* dest, char* src) {
    assert(dest != NULL && src != NULL);

    char* destCopy = dest;// 不能在dest上进行赋值操作
    while ((*destCopy++ = *src++) != '\0');
//    while ((*(destCopy++) = *(src++)) != '\0');// ++的优先级高于*

    return dest;
}

// 测试
int main() {
    char* dest = new char[100];
    char* src = new char[10];

    src = "abcdef";

    strcopy(dest, src);
    std::cout << dest << std::endl;

    return 0;
}