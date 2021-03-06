//Line类定义
#include "stock.h"
#include <iostream>

using namespace std;

// 类的构造函数实现
Line::Line(double shar,double shar_val){
    Line::shares = shar;
    Line::share_val = shar_val;
}
void Line::setShareVal(double share_val) {
    Line::share_val = share_val;
}

double Line::getShareVal() {
    return Line::share_val;
}

void Line::setShares(double shares) {
    Line::shares = shares;// 千万注意，这里的变量引用一定要用作用域解析符::
}

double Line::getShares() {
    return Line::shares;
}


void Line::show(){

    // 对show()函数进行修改实现测试

    // 预先保存常用的cout设置 set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout << "shares: " << Line::shares << endl;
    cout << "share_val: " <<Line::share_val << endl;

    // 修改cout的设置为 #.##
    cout.precision(2);
    Line::setTotalVal();// 调用内联函数有两种方式，可以直接调用，也可以使用作用域解析符::
    cout << "total_val: " << Line::total_val << endl;

    // 上述代码使用完之后，立即将cout的设置恢复到原来的格式
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}



int main(){
    //Line line = Line(5.1,10);


//    line.setShares(5.1);
//    line.setShareVal(10);
    Line line = Line(5.1,10);
//    line.setShares(5.1);
//    line.setShareVal(10);
    line.show();
}