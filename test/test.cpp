/*引用参数*/
#include <iostream>

using namespace std;

void swap(int & p1,int & p2){
    int p;
    p = p1;
    p1 = p2;
    p2 = p;
}

int main(){
    cout << "start!" << endl;
    // int * p = 10;// 不能这样给指针型变量赋值，因为无法进行自动类型转换
    // 但是可以进行强制类型转换，此时p和(int *) 10都是指针类型变量，此时将指针地址设为10，但是这种赋值是没有意义的

    // int * p = (int *) 10;// 但是出现问题：无法输出* p的值
    int a = 10;
    int * p;
    p = & a;

    cout << * p << endl;
//    int * p;
//    int a = 10;
//    p =  & a;
//    * p = a;
    cout << "*p = " << *p << endl;
    //常量引用b和a绑定,不能通过b而改变a。而且b也不可以自行重新赋值，比如b = xxx
//    const int &b = a;
//    cout << a << endl;
//    cout << b <<  endl;
//    //但是可以通过别的方式改变a
//    a = 20;
//    //b = 30;// 无法修改b的值，因为const限制，b为read-only变量
//    cout << a << endl;
//    cout << b << endl;
    //(上面的代码也反映了生活中有些事不是你以为一直不变的,它有可能已经改变了)
}