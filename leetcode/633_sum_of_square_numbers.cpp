/* leetcode T633:平方数之和
 * 原题链接：https://leetcode-cn.com/problems/sum-of-square-numbers/
 * */

/* 方法一：暴力解法
 *
 * 注意点：
 * double是双精度，有效位数为16~16位置，此题使用float精度会不够，导致结果出现偏差
 *
 * 复杂度分析：
 * 时间复杂度：O(sqrt(c))。
 * 空间复杂度：O(1)。
 *
 * 方法二：双指针法
 * 易错点：
 * 不能使用
 * while (left*left + right*right < c)对left和right进行逼近，因为在这样容易导致某一侧边界溢出也无法找到
 * 合适的解，智能一次判断一个
 *
 * 复杂度分析：
 * 时间复杂度： O(sqrt(c))。
 * 空间复杂度：O(1)。
 * */

#include <math.h>
#include <iostream>

using namespace std;

bool judgeSquareSum(int c) {
    for (long i = 0; i * i <= c; i++) {
        double tmp = sqrt(c - i * i);// double的是双精度类型，其有效位数为15~16位
        if (tmp >= 0 && tmp == int(tmp)) {
            return true;
        }
    }
    return false;
}

// 方法二：双指针
bool judgeSquareSum2(int c) {
    long left = 0, right = (long)sqrt(c);
    while (left <= right && left >= 0) {
        long tmp_sum = left*left + right*right;
        if (c == tmp_sum)
            return true;
        else if (tmp_sum > c)
            right--;
        else
            left++;
    }
    return false;
}
int main() {
//    cout << sqrt(999824438) << endl;
    cout << judgeSquareSum(999999999) << endl;
}