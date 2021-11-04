#include <iostream>

using namespace std;

class Box {
public:
    Box(double wid) : width(wid) {}
    void setWidth(double wid);
    friend void printWidth(Box box);

private:
    double width;
};