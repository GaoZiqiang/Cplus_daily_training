#include <iostream>

using namespace std;

int main() {
    float a = 10.0;
    void* pVoid;
    float* pFloat = &a;
    // 其他类型转void*--无需强制类型转换
//    pVoid = pFloat;


    cout << *pFloat << endl;
    pFloat++;
    pVoid++;
    int* pInt = (int*)pVoid;
//    cout << *pVoid << endl;
}