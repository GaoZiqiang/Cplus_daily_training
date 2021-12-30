/* leetcode T169:多数元素
 * 原题链接：https://leetcode-cn.com/problems/majority-element/
 * */

/* 方法一：哈希法
 *
 * 算法思想：
 * 使用哈希表记录每个元素出现的次数
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，哈希表长度。
 * 空间复杂度：O(n)，原地操作哈希表最多包含n - n/2(向下取整)个键值对，所以空间复杂度为O(n)。
 * */

// 实现方法
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size(), max_num = 0, max_cnt = 0;
    unordered_map<int, int> umap;
    for (auto num : nums) {
        umap[num]++;
        if (umap[num] > n / 2)
            return num;
    }
    return 0;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);
}