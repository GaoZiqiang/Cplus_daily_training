/*测试stack类*/

#include <iostream>
#include <cctype>

#include "stack.h"

using namespace std;

int main(){
    unsigned long po;
    Stack st;
    char ch;

    cout << "please enter A to add a purchase order,\n"
    << "P to process a po,or Q to quit.\n";

    while (cin >> ch && toupper(ch) != 'Q'){
        while (cin.get() != '\n')
            continue;
        if(!isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch){
            case 'A':
            case 'a': cout << "Enter a PO number to add:";
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
            case 'p':
            case 'P': if (st.isempty())
                          cout << "stack already empty\n";
                      else{
                          st.pop();
                      }
                      break;
        }
        cout << "please enter A to add a purchase order,\n"
             << "P to process a po,or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
//    if (!st.isempty())
//        cout << "the stack is empty!" << endl;
//    else
//        cout << "the stack is not empty!" << endl;
//
//     st.push(10);
//     st.push(9);
//     st.pop();
//     st.pop();
//     st.pop();

//    if (st.pop(po))
//        cout << "pop successfully!" << endl;
//    else
//        cout << "pop failed!" << endl;
}