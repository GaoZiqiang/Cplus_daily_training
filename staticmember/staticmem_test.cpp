/*类的静态成员*/
#include <iostream>

using namespace std;

class Box
{
public:
    // 声明静态成员变量
    static int objectCount;
    // 构造函数定义
    Box(double l=2.0, double b=2.0, double h=2.0)
    {
        cout <<"Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        // 每次创建对象时增加 1
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    // 定义静态成员函数
    static int getCount() {
        return objectCount;
    }
private:
    double length;     // 长度
    double breadth;    // 宽度
    double height;     // 高度
};

// 在类外 初始化类 Box 的静态成员
// 在初始化时，没有使用static关键字
int Box::objectCount = 0;

int main(void)
{
    // 在创建对象之前输出对象的总数
    cout << "Initial Stage Count by getCount(): " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    // 分析：在初始化第一个对象后，objectCount已经变成了1，因为静态成员变量是共享的关系
    // 所以下面的Box初始化后，objectCount变成了2
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 输出对象的总数
    cout << "Total objects by getCount(): " << Box::getCount() << endl;

    return 0;
}