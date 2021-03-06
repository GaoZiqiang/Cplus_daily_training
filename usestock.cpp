#include <iostream>

#include "stock.h"

int main(){

    Line line;

    //line.printTotalVal(200);
    //line.setShareVal(10);
    line.setShares(5);
    //line.getShares();
    cout << "shares by getShares() is " << line.getShares() << endl;

//    cout << "share_val is " << line.getShareVal() << endl;
//
//    line.showTotalVal(line.getShareVal(),line.getShares());
}