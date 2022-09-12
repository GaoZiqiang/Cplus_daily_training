// 后置++ i++
const int operator++(int) {
    self tmp = *this;
    ++*this;// 调用前置++
    return tmp;
}

// 前置++ ++i
int& operator() {
    ++*this;
    return *this;
}
