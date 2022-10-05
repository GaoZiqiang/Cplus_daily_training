// C语言实现C++的继承和虚函数多态
#include <bits/stdc++.h>

using namespace std;
//虚函数表结构
typedef struct vftable
{
	void (*show)(void*);	//根据所需自定义虚函数指针类型
}vftable;

//基类
typedef struct Base
{
	//虚表指针
	vftable* __vfptr;
	//基类自身属性
	int b_val = 0;
}Base;


typedef struct Son
{
	//隐藏基类对象
	Base base;

	//派生类自身属性和函数
	int s_val = 10;
}Son;

//基类函数
void ShowBase(void* th)
{
	Base* bs = (Base*)th;
	printf("b_val:%d\n", bs->b_val);
}
//派生类函数
void ShowSon(void* th)
{
	Son* ss = (Son*)th;
	printf("s_val:%d\n", ss->s_val);
}

//生成基类虚函数表
vftable base_vftable = { ShowBase};
//生成派生类虚函数表
vftable son_vftable = { ShowSon };

//基类构造函数
Base* create_Base(int val)
{
	Base* tmp = (Base*)malloc(sizeof(Base));
	memset(tmp, 0, sizeof(Base));
	//设置虚表指针 指向基类虚函数表
	tmp->__vfptr = &base_vftable;
	//初始化Base中成员
	tmp->b_val = val;
	return tmp;
}
//派生类构造函数
Son* create_Son(int val)
{
	Son* tmp = (Son*)malloc(sizeof(Son));
	memset(tmp, 0, sizeof(Son));
	//设置虚表指针
	tmp->base.__vfptr = &son_vftable;
	
	//初始化Base中成员
	tmp->base.b_val = 0;
	//初始化Son中成员
	tmp->s_val = val;
	
	return tmp;
}

int main()
{
	//1.构造派生类对象
	Son* sp = create_Son(10);

	Base* bp = (Base*)sp;
	//2.调用show函数指针 查派生类 虚函数表调用派生类的函数
	bp->__vfptr->show((void*)sp);
	free(sp);
	bp = NULL;
	sp = NULL;
	
	return 0;
}

