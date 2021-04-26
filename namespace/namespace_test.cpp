//#include <conio>
#include <iostream>

using namespace std;

namespace car {// 命名空间的定义
    int model;
    int length;
    int width;

    void ShowLength(int len) {
        cout << "in car namespace:" << len << endl;
    }
}

namespace plane {
    int model;
    namespace size {// 命名空间的嵌套
        int length;
        int width;
    }
    int length;
    int width;
    void ShowLength(int len) {
        cout << "in plane namespace:" << len << endl;
    }
}

namespace car {// 添加命名空间的成员
    char *name;
}

namespace c = car;// 定义命名空间的别名
int Time;// 外部变量属于全局命名空间

int main() {
    car::length = 3;
    cout << "the length of car is " << car::length << endl;
    cout << "the length of c is " << c::length << endl;// 使用namespace的别名
    using namespace car;
    ShowLength(9);// 前面这个可以不声明namespace

    using namespace plane;
    plane::ShowLength(10);// 因为前面的namespace car的作用域会与后边的namespace plane的作用域冲突，所以要声明namespace

    return 0;
}