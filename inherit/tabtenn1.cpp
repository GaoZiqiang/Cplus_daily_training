/*tabtenn1.cpp --simple base-class methods*/
#include "tabtenn1.h"
#include <iostream>

using namespace std;

TableTennisPlayer::TableTennisPlayer(const string &fn,const string &ln,bool ht) : firstname(fn),lastname(ln),hasTable(ht) {

}

void TableTennisPlayer::Name() const {
    cout << lastname << "," << firstname;
}

// 派生类方法
RatedPlayer::RatedPlayer(unsigned int r,const string &fn,const string &ln,bool ht) :     TableTennisPlayer(fn,ln,ht) {
    rating = r;
}

// 使用基类对象作为初始化列表参数
RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer &tp) : TableTennisPlayer(tp),rating(r) {

}