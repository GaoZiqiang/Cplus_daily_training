#include <iostream>

using std::cout, std::endl;

class stone {
public:
    stone() {}
    stone(int w, int h) : _w(w), _h(h), _weight(w*h) {}
    bool operator<(const stone& rhs) const {
        return this->_weight < rhs._weight;
    }
    int get_weight() const {return this->_weight;}
private:
    int _w, _h, _weight;
};

template<class T>
inline
const T& min(const T& a, const T& b) {
    return b < a ? b : a;
}

int main() {
    stone r1(2, 3), r2(3, 3), r3;
    r3 = min(r1, r2);
    cout << r3.get_weight() << endl;
}