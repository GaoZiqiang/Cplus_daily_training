// 手写实现strcmp()函数

#include <cstddef>
#include <assert.h>
#include <iostream>

using namespace std;

int my_strcmp(const void* buf1, const void* buf2, size_t n) {
    assert(buf1 != NULL && buf2 != NULL);

    // 替补指针
    const char* p1 = (const char*)buf1;
    const char* p2 = (const char*)buf2;

    int ans = 0;
    while (n-- > 0) {
        ans = *p1 - *p2;
        if (ans != 0) break;
        p1++;p2++;
    }

    return ans > 0 ? 1 : -1;
}

int main() {
    char* str1 = "angag";
    char* str2 = "aagag";

    cout << my_strcmp(str1, str2, 5) << endl;
}