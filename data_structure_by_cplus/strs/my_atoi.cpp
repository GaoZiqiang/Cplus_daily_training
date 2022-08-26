// 手动实现atoi()函数

#include <bits/stdc++.h>

using namespace std;


// 符号位
// 前置0
// 转换--非法字符去除
int my_atoi(const char* str) {
    int len = strlen(str);

    int left = 0, right;
    char flag = 1;// 正数 1
    // 字符串预处理
        // 空格 制表符-->跳过
        while (left < len && str[left] == ' ' || str[left] == '\t') left++;
        // 符号判断 非法字符
        if (str[left] == '-') {// 正常情况下 第一个字符为符号位
            flag = -1;
            left++;
        }
        else if (str[left] == '+' || str[left] < '0' || str[left] > '9') return 0;// 非法字符--退出
        // 前置0
        while (left < len && str[left] == '0') left++;// 越过前置0

    right = left;
    while (right < len && str[right] >= '0' && str[right] <= '9') right++;// 找到最右边
    if (right == left) return 0;
    if (right - left > 10) return flag == 1 ? INT_MAX : INT_MIN;// 超出范围

    // 转换为整数
//    cout << "left=" << left << endl;
//    cout << "right=" << right << endl;
    long long res = 0;
    for (int i = left; i < right; i++) {
        res = res * 10 + (str[i] - '0');
    }

    if (res > INT_MAX) return flag == 1 ? INT_MAX : INT_MIN;
    else return res * (flag == 1 ? 1 : -1);
//    return res;
}

int main() {
    char* str = "-00+0123";

    cout << my_atoi(str) << endl;

    return 0;
}

