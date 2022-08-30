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
    // 目标的注册函数 将订阅者/观察者注册到队列中
    void attach(Obserber* obs) {
        m_observers.push_back(obs);
    }

    // 事件通知函数
    void notify() {
        for (auto& obs : m_observers)
            obs->update();
    }
};
#endif