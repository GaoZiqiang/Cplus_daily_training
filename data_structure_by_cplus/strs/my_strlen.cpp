// 实现strlen()函数

#include <cstddef>

size_t strlen(const char* str) {// str不能修改
    assert(str != NULL);// str不能为空

    int cnt = 0;
    while (*str != '\0') {
        cnt++;
        str++;
    }

    return cnt;
}