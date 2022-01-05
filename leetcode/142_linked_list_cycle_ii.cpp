/* leetcode T142:环形链表II
 * 原题链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * */

/* 方法一：set表法
 *
 * 算法思想：
 * 核心：
 * 使用set暂存链表中的元素，若出现重复则返回
 *
 * 时间复杂度：O(n)；
 * 空间复杂度：O(n)，set表。
 *
 * 方法二：快慢指针法
 *
 * 算法思想：
 * 1 第一次相遇
 * fast指针走两步，slow指针走一步，直到fast套圈slow
 * 2 第二次相遇
 * fast指针回到head，fast和slow都只走一步，直到二者相遇--二者相遇点即为环的入口节点
 *
 * 时间复杂度：O(n)：在最初判断快慢指针是否相遇时，slow指针走过的距离不会超过链表的总长度；
 * 随后寻找入环点时，走过的距离也不会超过链表的总长度。因此，总的执行时间为O(N)+O(N)=O(N)。
 * 空间复杂度：O(1)。
 * */

// 实现方法
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一
ListNode* deleteCycle(ListNode* head) {
    set<ListNode*> nodes;
    ListNode* work = head;
    while (work != nullptr) {
        if (nodes.find(work) != nodes.end())
            return work;
        nodes.insert(work);

        work = work->next;
    }
    return nullptr;
}

// 方法二
ListNode* deleteCycle2(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    do {// 一开始fast==head，因此考虑将while (fast != slow)放在后面
        if (!fast || !slow) return nullptr;// 某一个指针走到头--没有环路
        fast = fast->next->next;// fast指针走两步
        slow = slow->next;
    } while (fast != slow);
    // fast回到起点
    fast = head;
    while (fast != slow) {
        fast = fast->next;// 都走一步
        slow = slow->next;
    }
    return fast;
}

int main() {
    ListNode* head = new ListNode(1);
    deleteCycle2(head);
}