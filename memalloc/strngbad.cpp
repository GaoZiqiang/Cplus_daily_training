#include <cstring>
#include "strngbad.h"

using namespace std;

// 初始化静态类成员
int StringBad::num_strings = 0;

// 自定义构造函数 只有一个参数的构造函数可以用作转换函数，因此该构造函数可以通过StringBad s = "Hello World"进行赋值
StringBad::StringBad(const char *s) {
    len = strlen(s);

    // 为指针变量str开辟一块内存，并将内存的首地址赋值给str
    // new的对象不会自动释放内存，因此需要delete函数并进行析构，即释放内存
    str = new char[len + 1];
    // 将s的值赋值为str
    strcpy(str,s);// str = s;叫做shallow copy浅copy

    num_strings++;
    cout << num_strings << ":\"" << str << "\" object created\n";
}

// 默认构造函数
StringBad::StringBad() {
    len = 4;
    str = new char[4];
    strcpy(str,"C++");// 默认赋值"C++"
    num_strings++;
    cout << num_strings << ":\"" << str <<"\" default object created\n";
}

// new的对象不会自动释放内存，因此需要delete函数并进行析构，即释放内存
// C++中析构函数调用时机：
// ①栈中定义的对象 程序会自动调用析构函数,例如CLassName object;
// 这样声明的对象，当程序运行到了对象作用域之外或者程序退出，对象都会被销毁，当然析构函数也会被调用
// ②堆中new的对象 使用new声明的对象，必须手动调用delete才会调用析构函数
StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted,";
    --num_strings;
    cout << num_strings << " left\n";
    // 堆开辟的内存不会自动释放，因此需要进行delete操作
    delete [] str;
}

ostream & operator << (ostream & os,const StringBad & st) {
    os << st.str;
    return os;
}

// 全局函数showScope() 可以直接在 int main()函数中调用
void showScope() {
    StringBad test;
}

int main() {
    StringBad s = "gaoziqiang";// 使用构造函数生成对象
    // 调用showScope()，测试析构函数的调用时机
//    showScope();

    // 测试shallow copy
    // 复制构造函数只进行简单的shallow copy，只复制指针的值，并不复制/开辟内存空间
    // s2、s3析构的时候导致删除同一块内存两次，从而发生内存错误
//    StringBad s2 = StringBad(s);// 并不使用构造函数生成对象，应该重新定义拷贝构造函数
    //StringBad s3 = s;// 并不使用构造函数生成对象，应该重新定义一个赋值运算符函数

    // StringBad sb("hello");
    //cout << "Initial num_strings is" << sb::num_strings;

    // 测试析构函数的调用时机
    cout << "这是程序的最后一条语句" << endl;
}