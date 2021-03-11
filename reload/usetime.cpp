#include <iostream>
#include "time.h"

using namespace std;

int main(){
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time t1(1,0);
    Time t2(2,0);
    Time t3(3,0);
    Time total;
    Time total1;
    Time diff;
    Time mult_result;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // 有两种方法调用重载后的加法运算符
    //total = coding + fixing;// 使用运算符表示法
    total = coding.operator+(fixing);// 使用函数表示法
    cout << "total time of coding and fixing is ";
    total.Show();
    cout << endl;

    // 多个数相加，同样有两种表示方法
    total1 = t1.operator+(t2.operator+(t3));
    //total1 = t1 + t2 + t3;
    cout << "total time of t1,t2,t3 is ";
    total1.Show();
    cout << endl;

    diff = t1 - t2;
    cout << "diff time of t1,t2 is ";
    diff.Show();
    cout << endl;

    mult_result = t1 * 2.0;
    cout << "mult_result of t1 * 2.0 is ";
    mult_result.Show();
    cout << endl;

    return 0;
}