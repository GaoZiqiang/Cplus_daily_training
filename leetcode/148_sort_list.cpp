/* leetcode T148:排序链表
 * 原题链接：https://leetcode-cn.com/problems/sort-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：插入排序
 *
 * 算法思想：
 * 使用插入排序法将后续节点一次插入排好序的子链表中--每次找子链表中第一个大于work->data的节点，并插入在该节点之后
 * 关键：
 * 如果待插入的节点大于子链表中所有节点，那么需要在子链表遍历结束后插入到链表尾。
 *
 * 复杂度分析：
 * 时间复杂度：O(n^2)，最多需要遍历1+2+3+...+n + n次。
 * 空间复杂度：O(1)，我们只会修改原本链表中节点的指向，而在堆栈上的堆栈帧不超过O(1)。
 * */

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;

/*创建单链表*/
LinkList createList(int * num) {// LinkList是个指针--地址
    // 创建头结点
    LinkList head = (LinkList)malloc(sizeof(struct LNode));

    // 工作指针指向头结点
    LinkList p = head;// 创建工作指针p
    p->next = NULL;// 尾指针置空

    int i = 0;
    while(num[i])// 无法直接获取数组的长度--这样有一个bug:num[i]为0时，退出
    {
        LinkList new_node = (LinkList)malloc(sizeof(struct LNode));

        new_node->data = num[i];
        // 尾插法
        p->next = new_node;
        new_node->next = NULL;
        p = new_node;
        i++;
    }

    return head;
}

/*单链表遍历*/
void traverseList(LinkList head) {
    // 从head之后的第一个节点开始遍历
    LinkList p = head->next;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");

    return;
}

LinkList sortList(LinkList head) {
    if (!head || !head->next || !head->next->next)// 空链表/只有头结点/只有一个节点
        return head;

    LNode *pre = head, *work = head->next->next, *temp = nullptr;
    head->next->next = nullptr;// 尾指针置空--保留第一个节点

    while (work) {
        temp = work->next;

        while (pre->next) {
            if (pre->next->data > work->data) {// 找到第一个比work->data大的节点，插在它前面
                work->next = pre->next;
                pre->next = work;
                break;
            }
            pre = pre->next;
        }

        if (!pre->next) {// 新添加的节点为最大节点--放在新链表的最后
            work->next = pre->next;
            pre->next = work;
        }

        // 继续下一轮遍历排序
        pre = head;
        work = temp;
    }

    return head;
}

int main() {
    int num_list[10] = {4,6,2,5,7};
    LinkList list = nullptr;
    list = createList(num_list);
    // 原链表遍历结果
    printf("原链表遍历结果\n");
    traverseList(list);

    LinkList result = sortList(list);
    traverseList(result);
}