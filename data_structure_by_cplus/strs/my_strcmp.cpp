// 手写实现strcmp()函数

#include <cstddef>
#include <assert.h>
#include <iostream>

using namespace std;

int my_strcmp(const void* buf1, const void* buf2, size_t n) {
    assert(buf1 != NULL && buf2 != NULL);

    // 替补指针
    const char* p1 = (const char*)buf1;
    const char* p2 = (const char*)buf2;

    int ans = 0;
    while (n-- > 0) {
        ans = *p1 - *p2;
        if (ans != 0) break;
        p1++;p2++;
    }

    return ans > 0 ? 1 : -1;
}

int main() {
    char* str1 = "angag";
    char* str2 = "aagag";

    cout << my_strcmp(str1, str2, 5) << endl;
}

class Solution {
private int[] p;
private int max;
private int[] cnt;
    int[][] dirs = {{1, 0}, {0, 1}};

public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        p = new int[m * n];
        cnt = new int[m * n];
        max = 0;
        // 并查集初始化
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    p[i * n + j] = i * n + j;
                    cnt[i * n + j] = 1;
                    max = 1;
                }
            }
        }
        // 扫描并合并
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int[] dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            union(i * n + j, ni * n + nj);
                        }
                    }
                }
            }
        }
        return max;
    }

    void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            p[rootB] = rootA;
            cnt[rootA] += cnt[rootB];
            max = Math.max(max, cnt[rootA]);
        }
    }

    int find(int i) {
        if (p[i] != i) {
            return find(p[i]);
        }
        return p[i];
    }
}

        作者：user2269A
        链接：https://leetcode.cn/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-bing-cha-ji-wei-mmm8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。