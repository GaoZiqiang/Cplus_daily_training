//Example 6
#include <iostream>
using namespace std;

class Student{
private:
    char *name;
    int age;
    float score;
    // static成员变量
    static int num;  	//学生人数
    static float total;  //总分
public:
    Student(char *, int, float);
    void say();
    // static成员函数
    static float getAverage();  //静态成员函数，用来获得平均成绩
};

int Student::num = 0;
float Student::total = 0;

Student::Student(char *name, int age, float score)
{
    this->name = name;
    this->age = age;
    this->score = score;
    num++;
    total += score;
}

void Student::say()
{
    cout<<name<<"的年龄是 "<<age<<"，成绩是 "<<score<<"（当前共"<<num<<"名学生）"<<endl;
}
// static成员函数静态成员变量
float Student::getAverage()
{
    return total / num;
}

int main()
{
    (new Student("小明", 15, 90))->say();
    (new Student("李磊", 16, 80))->say();
    (new Student("张华", 16, 99))->say();
    (new Student("王康", 14, 60))->say();
    // 使用类成员调用static成员函数
    Student * stu = new Student("高喊", 14, 60);
    cout << "stu->getAverage()" << stu->getAverage() << endl;
    // 使用类调用static成员函数
    cout<<"平均成绩为 "<<Student::getAverage()<<endl;
    return 0;
}