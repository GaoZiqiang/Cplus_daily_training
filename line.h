//Line类定义
#include <iostream>

using namespace std;

class Line
{
private:
    int shares;
    int share_val;
    int total_val;

//    void setTotalVal(){
//        total_val = share_val * shares;
//    }

public:
//    void sayHello();
    void setShareVal(int share_val);
    int getShareVal();

    void setShares(int shares);
    int getShares();

    void showTotalVal(int share_val,int shares);

    void printTotalVal(int tv);
    void printHello();
    void setName(string name);
    string getName();

    void showVal();


//private:
//    double length;
};