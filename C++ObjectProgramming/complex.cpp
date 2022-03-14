#include "complex.h"

inline complex& __doapl(complex* ths, const complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

complex& complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

complex operator+(const complex& x, const complex& y) {
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

ostream& operator<<(ostream& os, const complex& x) {
    return os << '(' << x.real() << ',' << x.imag() << ')';
}