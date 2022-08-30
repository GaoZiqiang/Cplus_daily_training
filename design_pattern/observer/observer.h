#ifndef OBSERVER_H_
#define OBSERVER_H_
#include <iostream>

using std::cout, std::endl;

// 观察者
class Obserber {
public:
    virtual ~Obserber() {}
public:
    virtual void update() = 0;
};

// 观察者实例
class Obs1 : public Obserber {
public:
    virtual void update() {
        cout << "Obs1 update" << endl;
    }
};

class Obs2 : public Obserber {
public:
    virtual void update() {
        cout << "Obs2 update" << endl;
    }
};
#endif