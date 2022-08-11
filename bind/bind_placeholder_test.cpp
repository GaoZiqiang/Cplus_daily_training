// std::bind()函数的占位符

#include <functional>
#include <iostream>

using namespace std;


void module2(int x, int y)
{
    cout <<"\
"  << __PRETTY_FUNCTION__ <<":\\t x =" << x  <<"\\t y =" << y;
}

void module3(int x, int y, int z)
{
    cout <<"\
"  << __PRETTY_FUNCTION__ <<":\\t x =" << x  <<"\\t y =" << y <<"\\t z =" << z;
}


int main()
{
    using namespace std::placeholders;

    int a = 39;
    int b = 7;
    int c = 3;



    auto func_m2 = bind(&module2, _1, _2);
    func_m2(a, b);                                   //  OK

    auto func_m2_PH = bind(&module2, _2, _1);// 第二个位置的参数作为module2函数的第一个参数
    func_m2_PH(b, a);                                   //  OK

//    //---------------------------------------------------------
//
//    auto func_m3 = bind(&module3, a, b, c);
//    func_m3();                                          //  OK
//
//    cout <<"\
// With PlaceHolders:";
//
//    auto func_m3_PH_0 = bind(&module3, _1, _2, _3);
//    func_m3_PH_0(a, b, c);                              //  OK
//
//    auto func_m3_PH_1 = bind(&module3, _2, _1, _3);
//    func_m3_PH_1(b, a, c);                              //  OK
//
//    auto func_m3_PH_2 = bind(&module3, _3, _1, _2);
//    func_m3_PH_2(c, a, b);                              //  KO !!!
//
//    auto func_m3_PH_3 = bind(&module3, _3, _2, _1);
//    func_m3_PH_3(c, b, a);                              //  OK
//
//    auto func_m3_PH_4 = bind(&module3, _1, _3, _2);
//    func_m3_PH_4(a, c, b);                              //  OK
//
//    auto func_m3_PH_5 = bind(&module3, _2, _3, _1);
//    func_m3_PH_5(b, c, a);                              //  KO !!!

    return 0;
}