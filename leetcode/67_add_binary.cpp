/* leetcode T67:二进制求和
 * 原题链接：https://leetcode-cn.com/problems/add-binary/
 * */

/* 方法一：基于T415:字符串相加 https://leetcode-cn.com/problems/add-strings/
 *
 * 算法思想：
 * 十进制转换为二进制
 *
 * 时间复杂度：O(n)，n = max(len1, len2)。
 * 空间复杂度：O(1)。
 *
 * */

// 实现方法
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0) {
        int n1 = i >= 0 ? num1[i] - '0' : 0;// 超出字符串/数组边界(j/j < 0)则置为0
        int n2 = j >= 0 ? num2[j] - '0' : 0;
        int bit_sum = n1 + n2 + add;// 各位相加
        ans.push_back('0' + bit_sum % 2);// 存余数s
        add = bit_sum / 2;// 计算进位
        i--;
        j--;
    }

    // 将结果进行翻转
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string num1 = "1010", num2 = "1011";
    cout << "ans = " << addStrings(num1, num2) << endl;
}