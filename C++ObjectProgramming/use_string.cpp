#include "string.h"

int main() {
    String str1("hello");
    String str2("world");

    String str3(str1);
    str2 = str1;
}