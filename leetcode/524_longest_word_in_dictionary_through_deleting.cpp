/* leetcode T524:通过删除字母匹配到字典里最长单词
 * 原题链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 * */

/* 方法一：暴力匹配
 *
 * 算法思想：
 * dictionary中子串逐个与s进行匹配。
 *
 * 复杂度分析：
 * 时间复杂度： O(m*n*l)，m为s长度，n为dictionary中每次子串的长度，l为子串个数。
 * 空间复杂度：O(1)。
 * */

// 解决方法
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 判断每次子串是否匹配
bool isMatched(string& s1, string& s2) {
    int len1 = s1.size(), len2 = s2.size();
    int j = 0;
    for (int i = 0; i < len2; i++) {
        while (s1[j] != s2[i] && j < len1) {
            j++;
        }
        // 判断匹配失败
        if (j == len1) {
            return false;
        }
        j++;// 匹配成功仍然要后移一位
    }
    return true;
}

// 求得最长单词
string findLongestWord(string s, vector<string>& dictionary) {
    int max_len = 0;
    string max_string = "";
    for (auto dic : dictionary) {
        if (isMatched(s, dic)) {
            // 最长
            if (dic.size() > max_len) {
                max_len = dic.size();
                max_string = dic;
            }
            // 字母序最小
            if (dic.size() == max_len) {
                if (dic < max_string) {
                    max_string = dic;
                }
            }
        }
    }
    return max_string;
}

int main() {
    string s1 = "abpcplea",s2 = "monkey";
    vector<string> dictionary = {"ale","apple","monkey","plea", "abpcllllll"};
    cout << findLongestWord(s1, dictionary);
}