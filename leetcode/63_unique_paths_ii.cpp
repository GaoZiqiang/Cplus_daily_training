#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // dp数组
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (obstacleGrid[m-1][n-1])
        return 0;

    if (obstacleGrid[0][0])
        return 0;

    // dp遍历顺序
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {// 起始点--dp初始化
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else if(j == 0 && i > 0) {// 左侧
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else
                    dp[i][j] = dp[i-1][j];
            } else if( i == 0 && j > 0) {// 上侧
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1];
            } else {// 其他
                if(obstacleGrid[i][j])// 有障碍
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];// 递推方程
            }
        }

    return dp[m-1][n-1];
}