/* leetcode T547:省份数量
 * 原题链接：https://leetcode-cn.com/problems/number-of-provinces/
 * */

/* 方法一：基于图的DFS/BFS递归遍历
 *
 * 算法思想：
 * 核心：
 * 图的DFS或BFS遍历，每个省份就是一个连通子图
 *
 * 关键点：
 * 与T695:岛屿的最大面积相比，如何判断两个节点是否相邻？
 * 判断if (isConnected[i][j] == 1)即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)，数组中元素个数。
 * 空间复杂度：O(n*n)，递归需要栈空间，递归的深度最大可能是整个网格的大小，故为m*n。
 *
 * 参考讲解：
 * https://leetcode-cn.com/problems/number-of-provinces/solution/sheng-fen-shu-liang-by-leetcode-solution-eyk0/
 * */

// 解决方法
#include <vector>

using namespace std;

// dfs递归
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int province_num, int i) {
    for (int j = 0; j < province_num; j++) {// for循环就是一次判断相邻节点
        if (!visited[j] && isConnected[i][j] == 1) {
            visited[j] = 1;
            dfs(isConnected, visited, province_num, j);// 从j作为起点，遍历其相邻节点
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int provice_num = isConnected.size();
    vector<int> visited(provice_num, 0);
    int circle_num = 0;
    for (int i = 0; i < provice_num; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, provice_num, i);
            circle_num++;// 一个新连通子图
        }
    }
    return circle_num;
}