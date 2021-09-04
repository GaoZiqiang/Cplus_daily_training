/* leetcode T455:分发饼干
 * 原题链接：https://leetcode-cn.com/problems/assign-cookies/
 * */

#include <vector>
#include <algorithm>
#include <stdio.h>

/* 方法一：排序 + 贪心
 *
 * 算法思想：
 * 因为饥饿度最小的孩子最容易吃饱,所以我们先考虑这个孩子。为了尽量使得剩下的饼干可
 * 以满足饥饿度更大的孩子,所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
 * 个孩子。满足了这个孩子之后,我们采取同样的策略,考虑剩下孩子里饥饿度最小的孩子,直到
 * 没有满足条件的饼干存在。
 *
 * 简而言之,这里的贪心策略是,给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。
 * 至于具体实现,因为我们需要获得大小关系,一个便捷的方法就是把孩子和饼干分别排序。
 * 这样我们就可以从饥饿度最小的孩子和大小最小的饼干出发,计算有多少个对子可以满足条件。
 *
 * 复杂度分析：
 * 时间复杂度：暂定；
 * 空间复杂度：暂定；
 * */

using namespace std;

int findContentChildren(vector<int> & children, vector<int> & cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (cookies[cookie] >= children[child]) ++child;
        ++cookie;
    }

    return child;
}

int main() {
    vector<int> children = {1,2};
    vector<int> cookies = {1,1};
    int num = findContentChildren(children, cookies);
    printf("num: %d\n",num);
}