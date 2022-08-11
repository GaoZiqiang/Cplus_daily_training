#ifndef STRING_H_
#define STRING_H_

#include <string.h>

class String {
public:
    String(const char* cstr = 0);
    // 编译器默认拷贝构造/赋值函数一个字节一个字节的拷贝到另一个对象中去
    // 拷贝构造--创建一个新的对象-->构造
    String(const String& str);
    // 拷贝赋值--不用创建新对象
    String& operator=(const String& str);
    ~String();
    inline char* get_c_str() const {return this->m_data;}
private:
    char* m_data;
};


#endif