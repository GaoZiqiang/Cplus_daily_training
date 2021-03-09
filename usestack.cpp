#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    unsigned long po;
    Stack st;
    if (!st.isempty())
        cout << "the stack is empty!" << endl;
    else
        cout << "the stack is not empty!" << endl;

    st.push(10);
    st.pop(po);
}