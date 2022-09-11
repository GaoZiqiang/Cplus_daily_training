#include "string.h"

String::String(const char *cstr) {
    if (cstr != nullptr) {
        this->m_data = new char[strlen(cstr) + 1];// 结束符'\0'
        strcpy(this->m_data, cstr);
    } else {// cstr为空
        this->m_data = new char[1];
        *(this->m_data) = '\0';
    }
}

String::~String() {
    delete[] this->m_data;
}

// 拷贝构造(构造：原来不存在，直接创建新的字符串空间)
String::String(const String& str) {
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
}

// 拷贝赋值(赋值：原来存在，所以需要先删除再创建新的字符串空间)
String& String::operator=(const String& str) {
    // 自我赋值
    if (this == &str)
        return *this;

    // 先把自己原来的m_data清掉
    delete[] this->m_data;
    // 再申请新的m_data
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);// 来源端拷贝到目的端

    return *this;
}