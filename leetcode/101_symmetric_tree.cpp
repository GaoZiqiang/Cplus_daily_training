/* leetcode T101:对称二叉树
 * 原题链接：https://leetcode-cn.com/problems/symmetric-tree/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>

/*两种宏?定义方式*/
#define ELEM_TYPE char
//typedef char ELEM_TYPE;
using namespace std;

/* 方法一：基于层次遍历与回文数判别
 * 核心思想：
 * 经观察我们发现：
 * 对称二叉树的每一层节点构成的字符串是一个回文字符串
 *
 * 分析：
 * 基于层次遍历，将每一层的节点数据暂存为一个字符串，判断该字符串是否为回文字符串；
 * 若某一层节点不符合回文字符串则返回false。
 *
 * 复杂度分析：
 * 时间复杂度：O(n) 树中每个元素进队、出队各一次；
 * 空间复杂度：O(n) 需要一个长度为n的辅助队列。
 * */

/*存储结构*/
typedef struct TreeNode {
    ELEM_TYPE data;
    struct TreeNode *lchild, *rchild;
}BiTNode;

/*声明树的根节点（的地址）*/
typedef TreeNode *BiTree;// 创建首指针 一个地址/指针而已

/*按照先序遍历的顺序创建树*/
void createBiTreePre(BiTree &BT) {// 使用引用，不会改变原数组的地址，在原数组的基础上进行修改
    ELEM_TYPE ch;
    cout << "请输入节点数值:" << endl;
    cin >> ch;// 这里输入的字符会转换成ASSIC码

    /*创建左右子树*/
    if (ch == '0')// 叶子节点后为'0'--输入'0'表示节点结束，没有子节点 切记：此处ch值类型为char
        BT = NULL;
    else {
        BT = new BiTNode;// 创建新节点
        BT->data = ch;
        /*递归调用*/
        createBiTreePre(BT->lchild);// 先把左子树创建完
        createBiTreePre(BT->rchild);// 再创建右子树
    }

    // return BT;// 使用引用形参，就不用返回创建好的树，而使用指针作为形参则需要进行返回值，返回创建好的那棵树
}

// 回文串判断
bool isPalindrome(string s) {
    string sgood;
    for (char ch: s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend());
    return sgood == sgood_rev;
}

/*实现方法*/
int isSymmetric(BiTree &root) {
    /*创建队列*/
    queue <BiTNode *> q;
    /*二叉树根节点入队*/
    q.push(root);// root既是数组的首指针，也是第一个元素 root[0]
    while(!q.empty()) {
        /*1 获取当前层的节点个数*/
        int n = q.size();// 栈当前元素个数-即当前层的元素个数
        std::string level_str = "";
        /*2 使用n控制 保证将当前层（一层的）的所有元素pop出来*/
        /*将当前层的所有元素全部出栈，（建立层的概念）*/
        for (int i = 0; i < n; i ++) {
            auto node = q.front();// 或者队尾元素
            level_str += node->data;
            /*2.1 队尾元素出队*/
            q.pop();// 出队

            /*2.2 判断左右子树--先做后右*/
            if (node->lchild)
                /*左子树入队*/
                q.push(node->lchild);
            /*右子树入队*/
            if (node->rchild)
                q.push(node->rchild);
        }

        // 对level进行回文判断
        if (!isPalindrome(level_str))
            return 0;
    }
    return 1;
}

/*测试*/
int main() {
    BiTree BT;
    /*创建二叉树*/
    createBiTreePre(BT);
    if (isSymmetric(BT))
        printf("is sysmmetric tree\n");
    else
        printf("not sysmmetric tree\n");
    return 0;
}