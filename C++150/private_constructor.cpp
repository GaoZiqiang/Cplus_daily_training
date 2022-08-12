// 测试：限制对象只能建立在堆上

class A
{
public:
    A(){}
    void destory(){delete this;}

protected:// 或者private
    ~A(){}
};

int main() {
    A a;// 创建在栈上 不可行
//    A* a = new A();
}