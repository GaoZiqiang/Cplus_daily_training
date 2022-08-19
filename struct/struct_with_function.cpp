// struct中添加函数

#include<iostream>
#include<string>

using namespace std;

struct Person
{
public:
    Person(string name);// 构造函数
    void greet(string other_name);// 定义函数

private:
    string m_name;
};

// 构造器
Person::Person(string name)
{
    m_name = name;
}

// 函数定义
void Person::greet(string other_name)
{
    cout << "Hello " << other_name << endl;
}

int main()
{
//    Person student = {"gaoziqiang"};
    Person student {"gaoziqiang"};
    student.greet("gaohan");
//    student.greet("nihao!");
//
//    Person m_person("大壮");
//    m_person.greet("喜子");
}

