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

// 拷贝构造
String& String::String(const String& str) {
    this->m_data = new char[sizeof(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);

    return *this;
}

// 拷贝赋值
String& String::operator=(const String& str) {
    if (*this == str) return *this;

    delete[] this->m_data;

    this->m_data = new char[sizeof(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);

    return *this;
}


#include <assert.h>

void strcpy(char* dest, char* src) {
    assert(dest != NULL && src != NULL);// 要同时满足

    char* destCopy = dest;
    while (*src != '\0') {
        *destCopy++ = *src++;
    }

    return;
}