//Line类定义
#include <iostream>

#pragma once//防止多次定义
using namespace std;

class Stock
{
private:// 这样类对象/程序就不能直接访问这些成员，只能通过成员函数进行访问
    double shares;
    double share_val;
    double total_val;

    // 类的内联函数，在函数声明时直接进行函数实现
    void setTotalVal() {
        total_val = share_val * shares;
    }

public:
    // 默认构造器，不包含参数，当且仅当没有定义其他构造函数时，编译器才会使用默认构造函数
    Stock();
    Stock(double shar_val,double shar);//构造函数
    void setShareVal(double share_val);
    double getShareVal();
    void update();

    void setShares(double shares);
    double getShares();
    // const成员函数
    void show() const;
};