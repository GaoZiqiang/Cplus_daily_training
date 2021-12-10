/* leetcode T347:前 K 个高频元素
 * 原题链接：https://leetcode-cn.com/problems/top-k-frequent-elements/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于快速排序
 *
 * 算法思想：
 * 关键点一：比较枢pivot的下标序号index--序列是从小到大排序，第k个大的元素下标为len - k，
 * 当枢pivot的下标index等于len - k时，此时的元素即为我们要查找的第k个大的元素
 * 关键点二：使用快速排序中的partition算法确定pivot的index
 * 关键点三：二分法，使用二分法确定partition算法在哪一个子序列中进行
 *
 * 改进一：
 * int mid = partition(nums, left, right);只需要在if判断前总的执行一次即可，避免多次执行，浪费时间
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，最多需要遍历1+2+3+...+n次，最少需要1+1+1+...+1=n次。
 * 空间复杂度：O(1)，原地操作。
 * */

#include <unordered_map>
#include <algorithm>
#include <queue>

class Solution {
public:
    // 比较函数
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    // 实现方法
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tmp_map;
        for (auto& num : nums) {
            tmp_map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto& [num, freq] : tmp_map) {
            if (pq.size() == k) {
                if (pq.top().second < freq) {
                    pq.pop();
                    pq.emplace(num, freq);
                }
            } else {
                pq.emplace(num, freq);
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};