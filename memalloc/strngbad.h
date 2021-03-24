#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

using namespace std;

class StringBad {
private:
    // new的对象不会自动释放内存，因此需要delete函数并进行析构，即释放内存
    // 因此就发生了后边的构造函数、析构函数的一些新的定义和理解
    // 在使用new对象为堆开辟内存时，需要重新构造拷贝构造函数和赋值运算符，不然就会发生悬垂指针dangling pointer错误
    // 这就是所谓的三五原则
    char * str;// string字符串指针
    int len;
    // 类对象个数/字符串个数
    static int num_strings;// 注意：此为静态类成员变量

public:
    StringBad(const char * s);// 自定义构造函数
    StringBad();// 默认构造器
    // 此处编译器还会自动生成两个默认成员函数：
    // 1复制（拷贝）构造函数
    // 复制构造函数只进行简单的shallow copy，只复制指针的值，并不复制/开辟内存空间 例如：str = xxx.str
    // 2赋值运算符

    // 在使用new对象为堆开辟内存时，需要重新构造拷贝构造函数和赋值运算符，不然就会发生悬垂指针dangling pointer错误
    // 这就是所谓的三五原则

    // 重新定义拷贝构造函数
    StringBad (const StringBad & st) {
        num_strings ++;// 因为是拷贝，所以并不会删除原来的
        len  =st.len;
        str = new char [len + 1];
        strcpy(str,st.str);
        cout << num_strings << ":\"" << str << "\" object created\n";
    }

    // 重新定义赋值运算符=
    // 但是要注意的是：在我使用的这个C++编译器的版本中，不需要重新定义赋值运算符
    StringBad & operator=(const StringBad & st) {// 注意：这里的& st中st是String对象类型
        // 1自检查
        if (this == &st)
            return *this;// 赋值给自身
        // 2删除原来字符串（释放成员指针原来指向的内存） 注意：这里一定要删除掉原来的
        delete [] str;// 将原来的那个str释放掉
        // 3深拷贝
        len = st.len;
        str = new char [len + 1];// 开辟一块新的区域
        strcpy(str,st.str);// 将st的值赋值给新变量

        return *this;// 返回一个指向调用对象的引用
    }

    ~StringBad();// 析构函数
    // 友元函数
    friend std::ostream & operator << (std::ostream & os,const StringBad & st);

    // 测试析构函数在何时调用
//    void showScope();
};
#endif