#include "line.h"
#include <iostream>

using namespace std;

void Line::printHello(string name) {
    cout << "hello " << name << "!" << endl;
}

int main(){
    Line line;
    line.printHello("gaoziqiang");
}