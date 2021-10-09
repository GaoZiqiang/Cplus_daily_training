/* leetcode T145:二叉树的后序遍历
 * 原题链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * */

#include <vector>
#include <iostream>
#include <queue>
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

/*后序遍历实现方式*/
void postorderTraverse(BiTree &root) {
    /*保存遍历结果*/
    vector<ELEM_TYPE> res;
    /*初始化辅助栈*/
    stack<BiTNode *> s;
    /*定义工作指针work和访问标记指针visited*/
    BiTNode *work, *visited;

    work = root;
    while(!s.empty() || work != NULL) {
        /*左子树遍历到头*/
        if (work != NULL) {
            s.push(work);
            work = work->lchild;
        }else {
            /*work指向栈顶节点--很重要！！！*/
            work = s.top();
            /*下面对栈顶节点的右子树的存在和访问情况进行分类讨论--很重要*/
            /*第一种：右子树存在且未被访问*/
            if (work->rchild != NULL && work->rchild != visited) {
                visited = work->rchild;// 右子树做访问标记
                work = work->rchild;// 转右子树
            /*第二种：右子树存在且已被访问--work->rchild != NULL && work->rchild = visited*/
            /*第三种：右子树不存在--work->rchild = NULL*/
            /*二三两种情况的处理方式是一样的，可以写在一起*/
            }else {
                /*取出栈顶，并访问*/
                auto node = s.top();
                visit(node);
                /*栈顶元素出栈*/
                s.pop();
                /*work指向NULL，这样下次循环work又会重新指向栈顶元素，重新对栈顶元素做判断*/
                work = NULL;// 这很重要！！！
            }
        }
    }
}

/*测试*/
int main() {
    BiTree BT;

    /*创建二叉树*/
    createBiTreePre(BT);

    /*后序遍历*/
    postorderTraverse(BT);
    
}
