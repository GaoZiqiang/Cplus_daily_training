#include <iostream>
#include <fstream>
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
    Time right_mult_result;
    Time left_mult_result;

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

    // 使用友元函数进行左乘运算
    left_mult_result = 3 * coding;
    cout << "left_mult_result of 2.0 * coding is ";
    left_mult_result.Show();
    cout << endl;

    // 使用乘法重载运算符进行右乘运算
    right_mult_result = coding * 2.0;
    cout << "right_mult_result of coding * 2.0 is ";
    right_mult_result.Show();
    cout << endl;


    // 使用<<重载运算符输出Time对象
    cout << "使用<<重载运算符输出right_mult_result对象: " << right_mult_result << endl;// 调用ostream的cout对象


    // 将结果写入文件
    fstream fout;
    cout << "将结果写入本地文件" << endl;
    fout.open("/home/gaoziqiang/temp/savetime.txt");
    fout << left_mult_result;

    return 0;
}