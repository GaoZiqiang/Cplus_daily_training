/*const_cation_param.cpp --const cation常量引用*/
#include <iostream>
#include <string>

using namespace std;

bool is_include_upper(const string &s) {
    for (auto ch : s) {
        if ('A' <= ch && ch <= 'Z') {
            return true;
        }
    }

    return false;
}

void to_lower(string &s) {
    for (auto &ch : s) {
        if ('A' <= ch && ch <= 'Z') {
            ch = ch + 32;
        }
    }
}
int main() {
    string s = "Hello World";
    cout << is_include_upper(s) << endl;
    to_lower(s);
    cout << s << endl;
    cout << is_include_upper(s);
}