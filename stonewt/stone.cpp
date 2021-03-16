#include <iostream>
#include "stonewt.h"

using namespace std;

int main() {
    // 将整型数值转换为Stonewt对象 但是只适用于构造器只有一个参数的类型
    Stonewt incognito = 275;// 当构造函数只有一个参数且构造函数的参数类型没有二义性时，可以使用这种方法直接进行赋值
    // 否则会报“conversion from ‘int’ to ‘Stonewt’ is ambiguous”错误 int可被转换为long或double
    //Stonewt incognito_(275);// 跟上面的方法等价
    Stonewt wolfe(285.7);
    Stonewt taft(21,8);

    incognito.show_lbs();
    incognito.show_stn();

//    incognito_.show_lbs();
//    incognito_.show_stn();

    wolfe.show_lbs();
    wolfe.show_stn();

    taft.show_lbs();
    taft.show_stn();

    // 将Stonewt对象转换为int double普通数值类型
    Stonewt poppins(9,2.8);

    // 第一种二义性情况
    // 这种情况下会出现ambiguous overload for ‘operator<<’问题，因为前面定义了两种对象类型转换
    // cout << poppins << endl;

    // 第二种二义性情况
    // 这种情况下会出现“conversion from ‘Stonewt’ to ‘long int’ is ambiguous”问题，因为int和double都可以转换为long类型
//    long gone = poppins;// int和double都可以转换为long类型
//    cout << "long gone:" << gone << endl;
    // 对于第二种二义性情况可以使用强制类型转换来指定只用哪个转换函数
    long gone_double = (double) poppins;
    long gone_int = int (poppins);
    cout << "long gone_double:" << gone_double << endl;
    cout << "long gone_int:" << gone_int << endl;

//    double p_wt = poppins;// 隐式类型转换
//    cout << "poppins converts to double:";
//    cout << p_wt << endl;

    // 隐式类型转换
    cout << "poppins converts to int:";
    int poppins_int = poppins;// 隐式类型转换
    cout << poppins_int;
}