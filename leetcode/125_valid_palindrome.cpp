/* leetcode T125:验证回文串
 * 原题链接：https://leetcode-cn.com/problems/valid-palindrome/
 * */

/* 方法一：双指针法
 *
 * 核心思想：
 * 1 先剔除干扰字符，手机字母和数字；
 * 2 然后通过left和right两个指针进行判断
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，n为字符串长度。
 * 空间复杂度：O(n)。
 * */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    // 剔除干扰字符
    vector<char> vals;
    for (auto val : s) {
        if ((val >= 'a' && val <= 'z') || (val >= 'A' && val <= 'Z') || (val >= '0' && val <= '9')) {
            vals.push_back(val);
        }
    }

    // 进行回文串判断
    int left = 0, right = vals.size() - 1;
    while (left <= right) {
        auto lval = vals[left], rval = vals[right];
        // lval或rval出现数字
        if ((lval >= '0' && lval <= '9') || (rval >= '0' && rval <= '9')) {
            if (lval == rval)// 只能相等
                left++, right--;
            else
                return false;
        } else {// 字母
            if ((lval == rval) || (abs(lval - rval) == 32))// 相等或同一个字母的大小写
                left++, right--;
            else
                return false;
        }
    }
    return true;
}

int main() {
    string a = "A man, a plan, a canal: Panama";
    string b = "race a car";
    string c = "0P";
    cout << isPalindrome(b);
}