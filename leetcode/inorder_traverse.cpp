/* leetcode T94:二叉树的中序遍历
 * 原题链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * */

#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>

/*两种宏?定义方式*/
#define ELEM_TYPE char
//typedef char ELEM_TYPE;
using namespace std;

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

/*节点访问函数*/
void visit(BiTNode *node) {
    cout << "visited node:" << node->data << endl;
}

/*中序遍历实现方式*/
vector<ELEM_TYPE> inorderTraverse(BiTree &root) {
    /*保存遍历结果*/
    vector<ELEM_TYPE> res;
    /*初始化辅助栈*/
    stack <BiTNode *> s;// s是一个指针，是一个地址
    /*设置工作指针*/
    BiTNode *work;// 工作指针

    /*工作指针指向根节点*/
    work = root;
    /*开始遍历--注意遍历终止的条件*/
    while(!s.empty() || work != NULL) {// work != NULL:一开始栈中是没有元素的，保证第一遍循环成立
        /*1 左子树一直入栈*/
        if (work != NULL) {
            s.push(work);
            work = work->lchild;
        }else {
            /*2 栈顶节点出栈*/
            auto node = s.top();
            /*保存出栈节点值*/
            res.push_back(node->data);
            /*访问*/
            visit(node);
            /*将栈顶节点出栈*/
            s.pop();
            /*3 work指针指向右子树*/
            work = node->rchild;
        }
    }

    return res;

}

/*测试*/
int main() {
    BiTree BT;

    /*创建树*/
    createBiTreePre(BT);
    /*先序遍历*/
    inorderTraverse(BT);
}
