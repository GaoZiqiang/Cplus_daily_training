// 单例模式测试
#include <iostream>

using namespace std;

class Singleton {
public:
    ~Singleton() {cout << "destructor called!" << m_id << endl;}
    static Singleton& get_instance(int id) {
        static Singleton instance(id);
        return instance;
    }
    int m_id;
private:
    Singleton(int id) :m_id(id) {cout << "constructor called, and m_id = " << m_id << endl;}

};

int main() {
    // 进行测试
    Singleton& instance1 = Singleton::get_instance(10);
    cout << instance1.m_id << endl;
    Singleton& instance2 = Singleton::get_instance(2);
    cout << instance2.m_id << endl;
    Singleton& instance3 = Singleton::get_instance(5);
    cout << instance3.m_id << endl;
    return 0;
}