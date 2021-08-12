// function_override.cpp--函数重载

// 函数重载的适用范围：
// 仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应采用函数重载。

// 函数重载是函数多态的重要实现方式
// 函数重载--函数名相同，参数列表不同--完成相同的工作，但使用不同的参数列表
// 需要根据函数上下文确定要使用的函数版本

// 重载函数的关键--参数列表（函数特征标）--参数列表==函数特征标
// 特征标相同--两个函数的参数数目、类型、排列顺序都相同--变量名无关紧要
// 在调用重载函数时，编译器将根据所采取的用法使用有相应特征标的原型

// 当函数调用传入的参数（实参）与函数原型中的参数列表不对应时：
// 1 函数原型唯一时--则对实参中与函数原型不匹配的参数进行强制类型转换
// 2 当函数原型不唯一时--编译器将不再为实参进行参数类型转换等工作，并报错处理


// 几种特殊情况
// 1 编译器在检查函数特征标时，会将类型引用和类型本身视为用一个特征标
// 例如：
// double cube(double x);
// double cube(double & x);
// 函数调用：cout << cube*(x);
// 函数调用时，参数x和double x原型以及double & x原型都匹配

// 2 关于const变量和非const变量
// 2-1 非const实参可以赋值给const形参也可以赋值给const形参
// 2-2 const实参智能赋值给const形参
// 例如：
// void sink(double & r);// 只能匹配非const实参--调用const变量可能会将其改变，不安全--因此只能匹配非const变量
// void sank(const & r);// 既可以匹配const实参，也可以匹配非const实参

// 3 是特征标而不是函数类型使可以对函数进行重载
// 例如，下面两个声明是互斥的:
// long gronk(int n, float m);
// double gronk(int n, float m);

// 下面是示例演示

#include <iostream>
#include <cstring>

using namespace std;

unsigned long left(unsigned long num, unsigned ct);// unsigned ct是啥？
char * left(const char * str, int n = 1);

int main() {
    // 关于字符char和字符串和字符数字以及指针
    //  char * a = (char *)'a';// 'a'char不能转换为char *，可以使用强制类型转换(char *)'a'
    // char类型的字符串
    char * a1 = "gaoziqang";// 创建一个char类型的指针（地址）a1--a1保存字符串的首地址
    cout << a1 << endl;
    // 字符串类型的数组
    char * a2[10] = {"ga","ga"};
    cout << a2[0] << endl;
    // 总结：
    // 核心：'a'为单个char字符,不可以转换为char *,"abc"类似于字符串

    // 1 char a = 'g';或者char a = 'gaoziqiang';是定义单个字符，必须用单引号''初始化--C++中''单引号和""双引号有显著的区别
    // 此时a或者'a'的类型为char/const char且不可转换为char * a
    // char * a = 'g';就是invalid conversion

    // 2 char * a = "gaoziqiang";为创建char类型的字符串，a为char类型的指针变量（保存字符串"gaoziqiang"的首地址）

    // 3 char a = {'b','c'};为创建char类型的数组，数组元素为char/const char
    // 4 char * a = {"gaoziqiang","gaohan"};为创建字符串数组，a保存数组的首元素地址。
    // 且数组元素只能为""，''报错--char不能转换成char *

    char * trip = "Hawaii";// 字符串
    unsigned long n = 12345678;
    int i;
    char * temp;

    for (i = 0; i < 10; i++) {
        cout << left(n,i) << endl;

        temp = left(trip,i);
        cout << temp << endl;
        delete [] temp;// 要释放left(trip,i)函数返回值所在的内存空间--期本质不是删除指针temp，而是删除保存结果的那块内存空间
    }

    return 0;
}

// 返回long型数字的前ct位digits
unsigned long left(unsigned long num, unsigned ct) {
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;// return 0 if no digits
    while (n /= 10)
        digits++;

    if (digits > ct) {
        ct = digits - ct;// 要删除的位数
        while (ct--)
            num /= 10;// 每次删除一位
        return num;
    }else
        return num;//digits < ct--要展示的位数大于实际位数digits
}

// 查看字符串的前n位
char * left(const char * str, int n) {
    int len = strlen(str);
    n = (n < len) ? n : len;

    char * p = new char[n+1];// 要及时删除开辟的内存空间--往往在函数调用完成之后删除
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];
    while (i <= n)
        p[i++] = '\0';// 不够的位置补'\0'

    return p;
}