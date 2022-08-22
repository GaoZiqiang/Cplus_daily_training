// 归并排序--链表

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

// 两个链表合并
ListNode* merge(ListNode* head1, ListNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    ListNode* pseudoHead = new ListNode(-1);
    ListNode* cur = pseudoHead;

    while (head1 && head2) {
        if (head1->val < head2->val) {
            cur->next = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }

    if (head1) cur->next = head1;
    if (head2) cur->next = head2;

    return pseudoHead->next;
}

ListNode* merge_sort(ListNode* head) {
    // write code here
    if (!head || !head->next) return head;

    // 关键：将链表分为两半
    ListNode* left = head;
    ListNode* mid = head->next;// 后半段的head
    ListNode* right = head->next->next;

    while (right && right->next) {
        left = left->next;
        mid = mid->next;
        right = right->next->next;
    }

    left->next = nullptr;

    // merg从短合并成长的 因此merge_sort要递归到一个节点为止
    return merge(merge_sort(head), merge_sort(mid));
}