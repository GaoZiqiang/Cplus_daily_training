#include <iostream>

using namespace std;

const int M = 3;

class Ik{
private:
    //enum {Months = 3};
    static const int Months = 3;
    int costs[Months];
    int fuss;

    // 作用域内枚举 或者使用struct代替class以防止变量作用域冲突
    enum class egg {Small,Medium,Large};
    enum class t_shirt {Small,Medium,Large};

public:
    Ik(int f =9){fuss = f;}// 构造器，有默认参数
    void ViewIk() const;
    void updateCosts();
    void showCosts();
    void showEnum();

};

void Ik::ViewIk() const {
    cout << Ik::fuss <<endl;
}
void Ik::updateCosts(){
    //Ik::costs[M] = {1,2,3};// 数组定义与初始化分开时，只能进行单个元素的赋值，而不能进行统一赋值
    Ik::costs[0] = 0;
    Ik::costs[1] = 1;
    Ik::costs[2] = 2;
}
void Ik::showCosts(){
    int i;
    for (i = 0;i < M;i++)
        cout << Ik::costs[i] << endl;

}
void Ik::showEnum() {
    egg one = egg::Small;
    int king = int(one);// 显式类型转换
    //cout << egg::Large;
    cout << king << endl;

}
int main(){

    Ik ee = Ik(10);
    ee.updateCosts();
    ee.showCosts();

    ee.showEnum();
    //ee.ViewIk();

//    Ik *pik = new Ik;
//    pik->ViewIk();
}