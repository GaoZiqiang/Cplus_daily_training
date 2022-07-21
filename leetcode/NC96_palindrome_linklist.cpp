/* NC96 判断一个链表是否为回文结构
 * 原题链接：https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=117&tqId=37813&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D96%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=96
 * */

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// 单向链表

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    // 反转链表
    ListNode* reverse(ListNode* p) {
        // 头插法建立反转后的链表
        ListNode* head = nullptr;
        while (p != nullptr) {
            ListNode* tmp = p->next;// 防止断链

            // 头插
            p->next = head;
            head = p;

            p = tmp;
        }

        return head;
    }

    bool isPail(ListNode* head) {
        // write code here
        ListNode* work = head;

        int n = 0;
        while (work != nullptr) {
            n++;
            work = work->next;
        }

        n = n / 2;
        work = head;

        while (n > 0) {
            work = work->next;
            n--;
        }

        // 从中点处反转
        ListNode* mid = reverse(work);
        work = head;

        while (mid != nullptr) {// 注意这里要用mid 不要用work
            if (work->val != mid->val) return false;
            work = work->next;
            mid = mid->next;
        }

        return true;
    }
};