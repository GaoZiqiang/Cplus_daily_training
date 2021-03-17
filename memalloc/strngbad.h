#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad {
private:
    char * str;// string字符串指针
    int len;
    // 类对象个数/字符串个数
    static int num_strings;// 注意：此为静态类成员变量

public:
    StringBad(const char * s);
    StringBad();// 默认构造器
    ~StringBad();// 析构函数
    // 友元函数
    friend std::ostream & operator << (std::ostream & os,const StringBad & st);
};
#endif