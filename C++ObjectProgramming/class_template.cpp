#include <iostream>

using std::cout, std::endl;

template<typename T>
class complex {
public:
    complex(T r = 0, T i = 0) : re(r), im(i) {}
    complex& operator+=(const complex&);
    T real() const {return re;}
    T imag() const {return im;}
private:
    T re, im;
};

int main() {
    complex<double> c1(21.1, 3.6);
    complex<int> c2(1, 2);
    complex<long> c3(32424, 4353535);
    complex<char> c4('f', 'j');
    cout << c4.real() << c4.imag() << endl;
}