/*factory_shape.cpp --工厂模式示例 shape*/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstddef>

using namespace std;

// 创建shape接口
class Shape {
public:
    virtual ~Shape() {};
    virtual void draw() = 0;

};

// 创建实现接口的实体类
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Rectangle Shape!" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Square Shape!" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Circle Shape!" << endl;
    }
};

// 创建工厂 工厂类
class Factory {
public:
    Shape* createShape(string ShapeType) {// 创建产品的方法
//        if(ShapeType == "")
//            return "";
        if(ShapeType=="Rectangle")
            return new Rectangle();
        if(ShapeType=="Square")
            return new Square();
        else if(ShapeType=="Circle")
            return new Circle();
    };
};

// 实际应用
int main() {
    Factory factory;
    Shape* rectangle = factory.createShape("Rectangle");
    rectangle->draw();

    return 0;
}