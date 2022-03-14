#include "complex.h"
//#include <iostream>

using namespace std;

int main() {
    complex c(1,2);
    complex c2(1,2);
    cout << c;
    c2 += c;
    cout << c2;
}