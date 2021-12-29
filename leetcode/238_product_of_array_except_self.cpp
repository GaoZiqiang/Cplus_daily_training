/* leetcode T238:除自身以外数组的乘积
 * 原题链接：https://leetcode-cn.com/problems/product-of-array-except-self/
 * */

/* 方法一：基于贪心算法
 *
 * 算法思想：
 * 1 分别计算一个元素的前缀积和后缀积
 * 2 计算前缀积/后缀积时使用贪心算法：
 * pre[i+1] = pre[i] * nums[i];
 * post[i-1] = post[i] * nums[i];
 * 3 然后遍历一次求每个元素的前缀积和后缀积的成积
 *
 * 时间复杂度：O(n)，3*n。
 * 空间复杂度：O(3n)。
 *
 * */


#include <vector>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1), post(n, 1), ans(n, 1);

    // 计算前缀
    for (int i = 0; i < n - 1; i++)
        pre[i+1] = pre[i] * nums[i];

    // 计算后缀
    for (int i = n - 1; i > 0; i--) {
        post[i-1] = post[i] * nums[i];
    }

    // 计算product except self
    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] * post[i];
    }

    return ans;
}
int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }
}