//Line类定义
#include "stock.h"
#include <iostream>

using namespace std;

// 类的默认构造器，为参数定义初始值
Stock::Stock(){
    cout << "creating a Stock object using default constructor" << endl;
    Stock::shares = 0.0;
    Stock::share_val = 0.0;
}
// 类的构造函数实现
Stock::Stock(double shar_val,double shar){
    cout << "creating a Stock object using constructor" << endl;

    Stock::share_val = shar_val;
    Stock::shares = shar;
}
void Stock::setShareVal(double share_val) {
    Stock::share_val = share_val;
}

double Stock::getShareVal() {
    return Stock::share_val;
}

void Stock::setShares(double shares) {
    Stock::shares = shares;// 千万注意，这里的变量引用一定要用作用域解析符::
}

double Stock::getShares() {
    return Stock::shares;
}

void Stock::update() {
    Stock::total_val = Stock::share_val * Stock::shares;
}
void Stock::show() const{

    // 对show()函数进行修改实现测试

    // 预先保存常用的cout设置 set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout << "share_val: " << Stock::share_val << endl;
    cout << "shares: " << Stock::shares << endl;

    // 修改cout的设置为 #.##
    cout.precision(2);
    //Stock::setTotalVal();// 调用内联函数有两种方式，可以直接调用，也可以使用作用域解析符::
    cout << "total_val: " << Stock::total_val << endl;

    // 上述代码使用完之后，立即将cout的设置恢复到原来的格式
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}



int main(){
    Stock stock3;// 将使用默认构造器
    Stock stock = Stock(5.1, 10);
    stock.update();
    //cout << "stock before changing" << endl;
    stock.show();
//    stock.setShares(20);
//    cout << endl;
//    cout << "stock after changing" << endl;
//    stock.show();

    // 两种不同的对象生成方法/列表初始化方法
//    Stock stock1 = {7.3,20};
//    stock1.show();
//
//    Stock stock2{8.4,30};
//    stock2.show();


}