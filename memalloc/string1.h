/*修改并增强String类的功能*/
#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>

// 不太理解
using std::ostream;
using std::istream;

class String {
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;// 输入字符串长度限制

public:
    // 构造函数和其他函数
    String(const char * s);// 带参构造函数
    String();// 默认构造函数
    String(const String &);// 拷贝构造函数
    ~String();//析构函数
    int length() const {return len;}

    // 重载运算符函数
    String & operator=(const String &);// 重赋值运算符=
    String & operator=(const char *);// 重赋值运算符=
    char & operator[](int i);// 中括号[]取值运算符
    const char & operator[](int i) const;// 中括号[]取值运算符 不能对取出的值进行修改

    // 重载运算符友元函数
    friend bool operator<(const String & st,const String & st2);
    friend bool operator>(const String & st,const String & st2);
    friend bool operator==(const String & st,const String & st2);
    friend ostream & operator<<(ostream & os,const String & st);
    friend istream & operator>>(istream & is,String & st);// 输入操作符，因此st不再是const类型

    // 静态函数
    static int HowMany();
    int size(const String st);
    static bool isShorter(const String &s1,const String &s2);// 测试常量引用
};

#endif
