/*factory_demo.cpp --工厂模式示例代码*/
#include <iostream>
using namespace std;
enum PRODUCTTYPE {SFJ,XSL,NAS};// 枚举类型
// 创建一个接口(C++中是抽象类)
class soapBase
{
public:
    virtual ~soapBase(){};
    virtual void show() = 0;// 接口的主要方法
};

// 创建实现接口的实体类
class SFJSoap:public soapBase
{
public:
    void show() {cout<<"SFJ Soap!"<<endl;}
};

class XSLSoap:public soapBase
{
public:
    void show() {cout<<"XSL Soap!"<<endl;}
};

class NASSoap:public soapBase
{
public:
    void show() {cout<<"NAS Soap!"<<endl;}
};

// 创建一个工厂，生成基于给定信息的实体类的对象
// 这才是真正的加工工厂，前面的都是加工所需要的材料
class Factory
{
public:
    soapBase * creatSoap(PRODUCTTYPE type)// 根据需求按需制造产品
    {
        switch(type)
        {
            case SFJ:
                return new SFJSoap();
                break;
            case XSL:
                return new XSLSoap();
                break;
            case NAS:
                return new NASSoap();
                break;
            default:break;
        }

    }
};


// 实际应用
int main()
{
    Factory factory;
    soapBase* pSoap1 = factory.creatSoap(SFJ);
    pSoap1->show();
    soapBase* pSoap2 = factory.creatSoap(XSL);
    pSoap2->show();
    soapBase* pSoap3 = factory.creatSoap(NAS);
    pSoap3->show();
    delete pSoap1;
    delete pSoap2;
    delete pSoap3;
    return 0;
}