/* leetcode T417:太平洋大西洋水流问题
 * 原题链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
 * */

/* 方法一：基于DFS
 *
 * 算法思想：
 * 回溯法
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，数组中元素个数。
 * 空间复杂度：O(n*n)，递归需要栈空间，递归的深度最大可能是整个网格的大小，故为m*n。
 *
 * 解析参考：
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/solution/shui-wang-gao-chu-liu-by-xiaohu9527-xxsx/
 * */

// 实现方法
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j);

vector<vector<int>> P, A, ans;
int m, n;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size(), n = heights[0].size();
    P = A = vector<vector<int>> (m, vector<int>(n, 0));

    // P太平洋--上边和左边 A大西洋--下边和右边
    for (int i = 0; i < n; i++) {
        dfs(heights, P, i, 0);// 太平洋-左边
        dfs(heights, A, i, n - 1);// 大西洋-右边
    }
    for (int j = 0; j < m; j++) {
        dfs(heights, P, 0, j);// 太平洋-上边
        dfs(heights, A, m - 1, j);// 大西洋-下边
    }

    return ans;
}

void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j) {
    // 同一侧--用一个大洋已经访问过，则停止遍历
    // 这个地方的设计很巧妙
    if (visited[i][j]) return;
    visited[i][j] = 1;

    // 当前大洋访问过[i][j]，且另一个大洋也访问过了--则表示该点[i][j]即为目标点
    if (P[i][j] && A[i][j]) ans.push_back({i, j});

    // 继续对该点做DFS
    if (i - 1 >= 0 && heights[i-1][j] >= heights[i][j]) dfs(heights, visited, i - 1, j);// 上边
    if (i + 1 < m && heights[i+1][j] >= heights[i][j]) dfs(heights, visited, i + 1, j);// 下边
    if (j - 1 >= 0 && heights[i][j-1] >= heights[i][j]) dfs(heights, visited, i, j - 1);// 左边
    if (j + 1 < n && heights[i][j+1] >= heights[i][j]) dfs(heights, visited, i, j + 1);// 右边
}