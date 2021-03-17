#include <cstring>
#include "strngbad.h"

using namespace std;

// 初始化静态类成员
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str,s);
    num_strings++;
    cout << num_strings << ":\"" << str << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    strcpy(str,"C++");
    num_strings++;
    cout << num_strings << ":\"" << str <<"\" default object created\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted,";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

ostream & operator << (ostream & os,const StringBad & st) {
    os << st.str;
    return os;
}

//int main() {
//    StringBad sb("hello");
//    //cout << "Initial num_strings is" << sb::num_strings;
//}