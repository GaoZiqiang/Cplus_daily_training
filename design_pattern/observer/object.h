// 目标

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "observer.h"
#include <vector>

using namespace std;

class Subject {
private:
    vector<Obserber*> m_observers;
    
public:
    void attach(Obserber* obs) {
        m_observers.push_back(obs);
    }
    void notify() {
        for (auto& obs : m_observers)
            obs->update();
    }
};
#endif