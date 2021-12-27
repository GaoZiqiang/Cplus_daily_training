/* leetcode T326:3的幂
 * 原题链接：https://leetcode-cn.com/problems/power-of-three/
 * */

/* 方法一：暴力解法
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，对数。
 * 空间复杂度：O(1)。
 *
 * 方法二：
 * 核心思想：
 * 在 int 范围内 3 的最大次方是3^19 = 1162261467，如果 n 是 3 的整数次方，
 * 那么 1162261467 除以 n 的余数一定是零；反之亦然。
 *
 * 复杂度分析：
 * 时间复杂度：O(1)。
 * 空间复杂度：O(1)。
 * */

// 实现方法
bool isPowerOfThree(int n) {
    if (1 == n) return true;
    if (3 == n) return true;
    // 判断个位数
    // 只有个位数为1 3 7 9的才能是3的整数幂次
    int ob = n % 10;
    if (ob != 1 && ob != 3 && ob != 7 && ob != 9)
        return false;
    // 暴力求解
    long tmp = 3;
    while (tmp <= n) {
        if (tmp == n) {
            return true;
        }
        tmp *= 3;
    }
    return false;
}

// 方法二
bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}