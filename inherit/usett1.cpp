/*usett1.cpp --using base class and derived class*/
#include <iostream>
#include "tabtenn1.h"

using namespace std;

int main() {
    TableTennisPlayer player1("Tara","Boomdea",false);
    RatedPlayer rplayer1(1140,"Mallory","Duck",true);

    rplayer1.Name();
    if(rplayer1.HasTable())
        cout << ": has a table" << endl;
    else
        cout << ": hasn't a table" << endl;

    player1.Name();
    if(player1.HasTable())
        cout << ": has a table" << endl;
    else
        cout << ": hasn't a table" << endl;

    cout << "Name: ";
    rplayer1.Name();// 派生类调用基类方法
    cout <<"; Rating: " << rplayer1.Rating() << endl;

    // 基类引用在不进行显式类型转换的情况下引用派生类对象
    cout << "基类引用在不进行显式类型转换的情况下引用派生类对象" << endl;
    TableTennisPlayer &rt = rplayer1;
    rt.Name();
    cout << endl;

    // 使用基类对象初始化派生类
    cout << "使用基类对象初始化派生类" << endl;
    RatedPlayer rplayer2(1212,player1);// player1为基类对象
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}