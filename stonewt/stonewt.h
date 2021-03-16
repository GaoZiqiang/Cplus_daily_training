#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt{
private:
    enum {Lbs_per_stn  = 14};// pounds per stone
    int stone;
    double pds_left;// fractional pounds
    double pounds;
public:
    Stonewt(double lbs);// 只有一个参数的构造器
    // Stonewt(long lbs);// 这样会出现二义性
    Stonewt(int stn,double lbs);// 两个参数构造器
    Stonewt();// 默认构造器

    void show_lbs() const;// show weight in pounds format
    void show_stn() const;// show weight in stone format

    // 转换函数
    // 将Stonewt对象转换为int double普通数值类型
    // 声明使用显式类型转换 可防止隐式转换，而只允许显式转换
    explicit operator int() const;// int转换将待转换的值转换为最接近该数值的整数值，转换函数没有声明返回类型，但是仍要返回所需的值
    operator double() const;
};
#endif