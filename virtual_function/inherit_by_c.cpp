// C语言实现继承
// 方法：子类引用父类对象--组合
#include <bits/stdc++.h>

using namespace std;

//基类
typedef struct Base
{
	//基类自身属性和方法
	int b_val = 0;
	void show()
	{
		printf("b_val:%d\n", b_val);
	}
}Base;
typedef struct Son
{
	//隐藏基类对象
	Base base;// 子类包含/组合父类对象
	//派生类自身属性和函数
	int s_val = 10;
	void show()
	{
		printf("s_val:%d\n", s_val);
	}

}Son;

int main()
{
	Son s;
	s.show();
	s.base.show();
	return 0;
}

