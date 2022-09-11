#include <iostream>

using namespace std;

class A {
private:
    int x;
public:
    void set_x(int _x) {
        x = _x;
    }
    int get_x() {
        return x;
    }
    long get_x_addr() {
        return (long)&x;
    }
};

int main() {
    A a;
    a.set_x(10);
    cout << "a.get_x()1 = " << a.get_x() << endl;
    cout << a.get_x_addr() << endl;
    long x_addr = a.get_x_addr();
    *(int*)x_addr = 20;
    cout << "a.get_x()2 = " << a.get_x() << endl;
}