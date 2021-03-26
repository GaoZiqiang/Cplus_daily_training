/*string1.cpp --String class methods*/
#include <cstring>
#include "string1.h"

using std::cin;
using std::cout;
using std::endl;
//using std::ostream;
//using std::istream;

// 初始化静态类成员
int String::num_strings = 0;

// 静态函数
int String::HowMany() {
    return num_strings;
}

// 其他类方法

// 构造函数
String::String(const char * s) {
    len = std::strlen(s);// 先计算s的长度
    str = new char[len + 1];// 为str开辟内存
    std::strcpy(str,s);// 将s的内容复制到str中
    num_strings ++;
}

// 默认构造函数
String::String() {
    len = 4;
    str = new char[1];// 不适用new char;是为了和析构函数中的delete []兼容
    str[0] = '\0';// 默认字符串'\0'是结束标志位 可以修改为str = 0;
    num_strings ++;

    // 或者这样
//    len = 0;
//    str = nullptr;
//    std::cout << "num_strings " << num_strings << std::endl;
//    std::cout << "str " << str << std::endl;
//    std::cout << "test str" << std::endl;
}

// 拷贝构造函数
String::String(const String & st) {
    num_strings ++;

    len = st.len;
    str = new char [len + 1];
    std::strcpy(str,st.str);
}

// 析构函数
String::~String() {
    --num_strings;
    delete [] str;// String等于str[]字符数组 因此应该用delete[]来作为析构函数
}


// 重载运算符函数

// 重赋值运算符
// assign a String to a String
String & String::operator=(const String & st) {// 这里的& st中的st的类型为String对象
    // 1自检查
    if (this == &st)
        return *this;// 赋值给自身
    // 2删除原来字符串
    delete [] str;// 将原来的那个str释放掉
    // 3深拷贝
    len = st.len;
    str = new char [len + 1];// 开辟一块新的区域
    strcpy(str,st.str);// 将st的值赋值给新变量

    return *this;
}

// assign a C String to a String
String & String::operator=(const char * s) {
    delete [] str;

    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str,s);

    return *this;
}

// 重载中括号取值运算符
// read-write for non-const String
char & String::operator[] (int i) {
    return str[i];// 可以原字符串进行修改
}

// read-only for const String
const char & String::operator[] (int i) const {
    return str[i];
}


// 重载运算符友元函数
// < 运算符
bool operator<(const String & st1,const String & st2) {
    return (std::strcmp(st1.str,st2.str) < 0);
}

// > 运算符
bool operator>(const String & st1,const String & st2) {
    return st2 < st1;// 调用上面的<重载运算符
}

// ==运算符
bool operator==(const String & st1,const String & st2) {
    return (std::strcmp(st1.str,st2.str) == 0);
}

// cout输出运算符<<
ostream & operator<<(ostream & os,const String & st) {
    os << st.str;
    return os;// 注意：是有返回值的
}

// cin输入运算符
istream & operator>>(istream & is,String & st) {// 注意：此处st是可以改变的
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if (is)
        st = temp;
    while(is && is.get() != '\n')
        continue;

    return is;
}

// 测试 返回指向const对象的引用
struct Vector {
    int magval;
};

// 返回指向const对象的引用
const Vector Max(const Vector &v1,const Vector &v2) {
    if (v1.magval > v2.magval)
        return v1;
    else
        return v2;
}

// 测试 返回对象
const Vector &Add(const Vector &v1,const Vector &v2) {
    Vector v3;// v3为一个局部变量 因此不返回对象的引用
    v3.magval = v1.magval + v2.magval;

    return v3;
}

//int main() {
////    String test;
////    test.HowMany();
//    Vector v1 = {1};
//    Vector v2 = {2};
//    const Vector v = Max(v1,v2);
//
//    cout << v.magval << endl;
//
//    Vector v3;
//    v3 = Add(v1,v2);
//    // 如果返回局部对象的引用会出现丢失
//    cout << v3.magval << endl;
//}