/* leetcode T384:打乱数组
 * 原题链接：https://leetcode-cn.com/problems/shuffle-an-array/
 * */

/* 方法一：模拟
 *
 * 算法思想：
 * reset：
 * return origin_num即可
 * shuffle：
 * 直接调用vector的shuffle函数即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，vector.size()。
 * 空间复杂度：O(n)，vector.size()。
 *
 * */

// 实现方法
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> origin;
    Solution(vector<int>& nums) {
        origin = std::move(nums);
    }

    // reset重置
    vector<int> reset() {
        return origin;
    }

    // shuffle
    vector<int> shuffle() {
        if (origin.empty()) return {};
        vector<int> shuffled(origin);
        int n = shuffled.size();
        std::random_shuffle(shuffled.begin(), shuffled.end());
        return shuffled;
    }
};