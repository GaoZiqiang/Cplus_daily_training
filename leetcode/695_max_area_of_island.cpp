/* leetcode T695:岛屿的最大面积
 * 原题链接：https://leetcode-cn.com/problems/max-area-of-island/
 * */

/* 方法一：基于图的DFS/BFS递归遍历
 *
 * 算法思想：
 * 核心：
 * 图的DFS或BFS遍历，每个岛屿就是一个联通子图
 *
 * 关键点：
 * 每一个点有上下左右四个方向（树有两个方向lchild rchild）
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，数组中元素个数。
 * 空间复杂度：O(m*n)，递归需要栈空间，递归的深度最大可能是整个网格的大小，故为m*n。
 *
 * 参考视频讲解：
 * https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/
 * */


// 实现方法
#include <vector>

using namespace std;

int islandDFS(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return 0;
    if (0 == grid[i][j])
        return 0;// 已经访问过
    grid[i][j] = 0;// 设置访问标记为已访问

    // 继续遍历上下左右四个方向
    return 1 + islandDFS(grid, i, j - 1) + islandDFS(grid, i, j + 1)
    + islandDFS(grid, i - 1, j) + islandDFS(grid, i + 1, j);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(islandDFS(grid, i, j), ans);
        }
    }

    return ans;
}