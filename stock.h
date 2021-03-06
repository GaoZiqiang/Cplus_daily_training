//Line类定义
#include <iostream>

#pragma once//防止多次定义
using namespace std;

class Line
{
private:// 这样类对象/程序就不能直接访问这些成员，只能通过成员函数进行访问
    double shares;
    double share_val;
    double total_val;

    // 类的内联函数，在函数声明时直接进行函数实现
    void setTotalVal(){
        total_val = share_val * shares;
    }

public:
    Line(double shar = 6.2,double shar_val = 10);//构造函数
    void setShareVal(double share_val);
    double getShareVal();

    void setShares(double shares);
    double getShares();

    void show();
};