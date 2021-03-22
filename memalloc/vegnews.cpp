#include <iostream>
#include "strngbad.h"

//using namespace std;
using std::cout;

void callme1(StringBad &);// pass by reference
void callme2(StringBad);// pass by value

int main() {
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad headline3("Spanich Leaves Bowl for Dollars");

        // 析构函数的调用顺序与构造函数的调用顺序相反
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "headline3: " << headline3 << endl;

//        cout << "headline1 by callme2:\n";
//        callme2(headline1);
//        cout << "headline1: " << headline1 <<endl;
//
//        cout << "headline2 by callme2:\n";
//        callme2(headline2);
//        cout << "headline2: " << headline2 << endl;
//
//        cout << "headline3 by callme2:\n";
//        callme2(headline3);
//        cout << "headline3: " << headline3 << endl;
//
//        callme2(headline3);

        // 测试复制构造函数

        // 该对象定义方法使用的是复制构造函数
        StringBad sailor = headline3;

        // 该种定义方式也是复制构造函数
        StringBad knot;
        knot = headline2;

        // 第三种：也是复制构造函数
        StringBad cook = StringBad(headline1);

        cout << "sailor:" << sailor << endl;
    }
}

void callme1(StringBad & rsb) {
    cout << "String passed by reference:\n";
    cout << " \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "String passed by value:\n";
    cout << " \"" << sb << "\"\n";
}