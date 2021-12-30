/* leetcode T462:最少移动次数使数组元素相等 II
 * 原题链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/
 * */

/* 方法一：寻找中位数
 *
 * 算法思想：
 * 核心：
 * 一个数学定理：数组中各个点到中位数的距离之和最小。
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，vector排序算法时间复杂度。
 * 空间复杂度：O(logn)，为排序需要的空间。
 *
 * */

#include <vector>
#include <algorithm>

using namespace std;

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int avg = nums[n/2];
    int count = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        count += abs(*it - avg);
    }
    return count;
}

int main() {
    vector<int> nums = {1,0,0,8,6};
    minMoves2(nums);
}