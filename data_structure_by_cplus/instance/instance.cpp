// 单例模式
// 懒汉模式
// DCL双重检查

#include <bits/stdc++.h>

using namespace std;

class Instance {
    // 禁外部调用构造函数
public:
    delete Instance();
    delete ~Instance();

public:
    // 懒汉+DCL双重检查
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
    // 禁止复制单例对象
    Instance(Instance& ins) {};
    ~Instance();

    // 互斥信号量
    pthread_mutex_t mutex;
};