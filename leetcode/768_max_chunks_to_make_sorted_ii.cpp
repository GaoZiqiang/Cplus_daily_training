/* leetcode T769:最多能完成排序的块
 * 原题链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
 * */

/* 方法一：单调栈改进
 * 算法思想：
 * 基于本题，j之后小于当前arr[i->j]中的最大值curMax的元素都可以和arr[i->j]划分为同一块
 * -->因此单调栈中存放的是当前块中的最大值curMax
 * -->在curMax入栈之前要更新curMax curMax = max(stack.top(), curMax);
 *
 * 关键点：
 * 1 仍然基于单调栈的思想，但是栈中存放的是当前块的最大值
 * 2 栈中存放的实际上是每个块中的最大值curMax
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)。
 * */

#include <stack>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    stack<int> stack;

    for (int i = 0; i < n; i++) {
        int curMax = arr[i];// 记录当前块的最大值
        while (!stack.empty() && stack.top() > arr[i]) {// 小于当前最大值则可划分为同一块
            curMax = max(stack.top(), curMax);// 更新curMax
            stack.pop();// 小于最大值的元素出栈
        }
        stack.push(curMax);// 最大值入栈
    }

    return stack.size();
}