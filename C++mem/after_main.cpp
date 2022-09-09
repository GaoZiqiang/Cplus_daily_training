#include <bits/stdc++.h>

using namespace std;

int func1(void){
    cout << "function 1" << endl;
}
void func2(void){
    cout << "function 2" << endl;
}

int main(){
//    onexit(func1);
    atexit(func2);
    return 0;
}
