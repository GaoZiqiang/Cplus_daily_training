//#include <conio>
#include <iostream>

using namespace std;

namespace car {// 命名空间的定义
    int model;
    int length;
    int width;
}

namespace plane {
    int model;
    namespace size {// 命名空间的嵌套
        int length;
        int width;
    }
    int length;
    int width;
}

namespace car {// 添加命名空间的成员
    char *name;
}

namespace c = car;// 定义命名空间的别名
int Time;// 外部变量属于全局命名空间

int main() {
    car::length = 3;
    cout << "the length of car is " << car::length << endl;

    return 0;
}