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
 *
 * 方法二：“三”指针法
 * 因为这两个数组已经排好序,我们可以把两个指针分别放在两个数组的末尾,即 nums1 的m − 1 位和 nums2 的 n − 1 位。
 * 每次将较大的那个数字复制到 nums1 的后边,然后向前移动一位。
 * 因为我们也要定位 nums1 的末尾,所以我们还需要第三个指针,以便复制。
 *
 * 在以下的代码里,我们直接利用 m 和 n 当作两个数组的指针,再额外创立一个 pos 指针,起
 * 始位置为 m + n − 1。每次向前移动 m 或 n 的时候,也要向前移动 pos。
 * 这里需要注意,如果 nums1的数字已经复制完,不要忘记把 nums2 的数字继续复制;如果 nums2 的数字已经复制完,
 * 剩余nums1 的数字不需要改变,因为它们已经被排好序。
 *
 * 复杂度分析：
 * 时间复杂度：O(max(m,n))。
 * 空间复杂度：O(1)。
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

// 实现方法二：“三”指针法
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m + n - 1;// pos指针用于控制插入到nums1数组的位置
    m--, n--;// nums1[m]和nums2[n]
    while (m >= 0 && n >= 0) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];// 将较大的那个数字复制到nums1数组后面
    }
    while (n >= 0) {// 若nums2数组没有空，则将其元素一次复制到nums1数组后即可
        nums1[pos--] = nums2[n--];
    }
    return;
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    merge2(nums1, 3, nums2, 3);
    for (auto num : nums1)
        cout << num << " ";
//    vector<int> ans = merge(nums1, 6, nums2, 3);
}