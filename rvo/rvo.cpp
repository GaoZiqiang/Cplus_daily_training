// C++ rvo返回值优化
// 参考：https://app.yinxiang.com/Home.action?_sourcePage=paBnKv_sdYriMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=O1UEVUx40mo3yWPvuidLz-TPR6I9Jhx8&hpts=1653446284731&referralCode=ebcc-organic-yxbj&showSwitchService=true&usernameImmutable=false&login=&login=%E7%99%BB%E5%BD%95&login=true&username=gaoziqianghi%40163.com&hptsh=3sqxR%2FPTcf2XCI5VH2fDMBNnDCI%3D#n=35eed6e6-1c85-4f51-a4e0-36b3463912d9&s=s3&ses=4&sh=2&sds=5&

#include <iostream>

using namespace std;

struct Foo {
    Foo() {cout << "Foo ctor" << endl;}
    Foo(const Foo&) {cout << "Foo copy ctor" << endl;}
    void operator=(const Foo&) {cout << "Foo operator=" << endl;}
    ~Foo() {cout << "Foo dtor" << endl;}
};

Foo make_foo() {
    Foo f;
    return f;
}

int main() {
    make_foo();
    return 0;
}