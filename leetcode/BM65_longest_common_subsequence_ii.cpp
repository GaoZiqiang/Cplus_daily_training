/* BM65 最长公共子序列(二)
 * 原题链接：https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11?tpId=295&tqId=991075&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 算法思想：
 * 动态规划dp
 * 注意：本题是子序列，子序列可以不连续
 * /

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string getString(string& s, int i, int j, vector<vector<int>>& position) {
        string res = "";
        // 递归终止
        if (i == 0 || j == 0) return res;

        // 递归添加本级字符
        if (position[i][j] == 1) {
            res += getString(s, i-1, j-1, position);
            res += s[i-1];
        } else if (position[i][j] == 2) {
            res += getString(s, i-1, j, position);
        } else {
            res += getString(s, i, j-1, position);
        }

        return res;
    }

    string LCS(string s1, string s2) {
        // write code here
        int n1 = s1.size(), n2 = s2.size();
        if (n1 == 0 || n2 == 0) return "-1";

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        vector<vector<int>> position(n1+1, vector<int>(n2+1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j= 1; j <= n2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    position[i][j] = 1;// 左上方
                } else {
                    if (dp[i-1][j] > dp[i][j-1]) {
                        dp[i][j] = dp[i-1][j];
                        position[i][j] = 2;// 左方
                    } else {
                        dp[i][j] = dp[i][j-1];
                        position[i][j] = 3;
                    }
                }
            }
        }

        // 从后往前递归
        string ans = getString(s1, n1, n2, position);

        return ans == "" ? "-1" : ans;
    }
};