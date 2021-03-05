//Line类定义
#include "line.h"
#include <iostream>

using namespace std;

//void Line::printHello() {
//    cout << "hello " << name << "!" << endl;
//}
//
////通过下面的setName()和getName()方法可以访问私有成员变量name
//void Line::setName(string nm){
//    name = nm;//Line::setName()表明了变量name和该方法属于同一个作用于，因此可以直接使用name来调用name这一private私有成员变量
//}
//
//string Line::getName(){
//    return name;
//}
void Line::setShareVal(int share_val) {
    share_val = share_val;
}

int Line::getShareVal() {
    return Line::share_val;
}

void Line::setShares(int shares) {
    Line::shares = shares;
//    cout << "shares is " << shares << endl;
}

int Line::getShares() {
    return Line::shares;
}


void Line::showTotalVal(int share_val,int shares) {
    total_val = share_val * shares;
    cout << "total value is " << total_val;
}

void Line::printTotalVal(int tv) {
    total_val = tv;
    cout << "total value is " << total_val;
}
//void Line::showVal() {
//    setTotalVal();
//    cout << "total_val is " << total_val << endl;
//}
int main(){
    Line line;

//    line.setShareVal(10);
    line.setShares(5);
    cout << "shares is " << line.getShares() << endl;

//    line.showVal();

}