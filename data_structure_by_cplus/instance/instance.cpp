// 单例模式
// 懒汉模式
// DCL双重检查

#include <bits/stdc++.h>

using namespace std;

class Instance {
public:
    delete Instance();
    delete ~Instance();

public:
    static Instance& getInstance() {
        if (instance == nullptr) {
            pthread_mutex_lock(mutex);
            if (instance == nullptr) {
                instance = new Instance();
                return *instance;
            }
            pthread_mutex_unlock(mutex);
        }
    }

private:
    Instance* instance;
    Instance();
    ~Instance();
};