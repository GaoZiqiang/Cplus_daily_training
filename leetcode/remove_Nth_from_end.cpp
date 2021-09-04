/* leetcode T328：奇偶链表
 * 原题链接：https://leetcode-cn.com/problems/odd-even-linked-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：奇偶节点分离再合并
 *
 * 算法思想：
 * 借鉴找中间节点的思想，通过指针每次移动两个节点，使两起点错位，从而实现奇、偶节点分类的目的。
 *
 * 易错点：
 * 1 while循环的终止条件
 * 2 最后的尾指针一定要置空
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，其中n指的是链表的大小。
 * 空间复杂度：O(1)，只需维护有限的指针。
 *
 * 方法二：对方法一的优化
 * 关键：
 * 1 不管链表长度为奇为偶，我都假定头结点head为第一个奇数节点，head->next为第一个偶数节点--大大简化了问题思考难度
 * 2 因为奇数节点在前，所以线更新奇数节点，具体如下：
 * odd->next = even->next;// odd指向even的下一个节点--隔一个节点
 * odd = odd->next;// odd移向新的odd
 * even->next = odd->next;
 * even = even->next;
 * 3 最后连接两个奇偶链表
 * head->next = even_head;//用even_head = head->next来暂存偶数链表的头结点
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

LinkList removeNthFromEnd(LinkList head) {
    
}