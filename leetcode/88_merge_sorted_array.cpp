/* leetcode T88:合并两个有序数组
 * 原题链接：https://leetcode-cn.com/problems/merge-sorted-array/
 * */

/* 方法一：双指针
 *
 * 算法思想：
 * 先设置一个临时数组，将两个数组中排好序的元素置于临时数组中
 *
 * 复杂度分析：
 * 时间复杂度：O(m+n)。
 * 空间复杂度：O(m+n)，临时数组。
 * */


#include <vector>
#include <iostream>

using namespace std;

// 实现方法
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = 0, p2 = 0;
    int sorted[m + n];
    int cur;
    while (p1 < m || p2 < n) {
        if (p1 == m) {// 数组nums1已经遍历完成，然后将nums2中的元素一次添加到sorted数组中即可
            cur = nums2[p2++];
        } else if (p2 == n) {// 数组nums2已经遍历完成，然后将nums1中的元素一次添加到sorted数组中即可
            cur = nums1[p1++];
        } else if (nums1[p1] < nums2[p2]) {
            cur = nums1[p1++];
        } else {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }
    for (int i = 0; i != m + n; ++i) {
        nums1[i] = sorted[i];
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for (auto num : nums1)
        cout << num << " ";
//    vector<int> ans = merge(nums1, 6, nums2, 3);
}