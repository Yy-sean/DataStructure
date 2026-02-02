#include <stdio.h>
#include <stdlib.h>
#include "threadBTree.h"

static TBTNode *pre = NULL; // 全局前驱节点指针
static void inOrdering(TBTNode *node) {
   if (node) {
        // 1. 递归左边
        inOrdering(node->left);

        // 2. 处理当前节点 (核心业务)

        // A. 处理左指针 (找前驱) 
        if (node->left == NULL) {
            node->ltag = 1; // 设置左标志为前驱
            node->left = pre; // 前驱节点
        }

        // B. 处理右指针 (帮前驱找后继)
        // 关键修复：必须判断 pre != NULL
        if(pre && pre->right == NULL) {
            pre->rtag = 1; // 设置前驱节点的右标志为后继
            pre->right = node; // 当前节点为后继
        }

        // C. 移动指针，我现在变成了"前驱"，准备迎接下一个人
        pre = node;

        // 3. 递归右边
        inOrdering(node->right);
   }
}
void inOrderThreading(ThreadedBTree *tree) {
    // 【修复点 1】必须重置！防止受上一次运行的影响
    //  static 变量（或全局变量）是长生不老的，它活着的时候会一直保留最后一次修改的值，除非你手动再次把它的记忆抹除。
    //  如未重置pre ，会导致上一棵树的尾节点和这棵树的头节点连在一起

    //  为了能处理多棵树，或者能多次运行，必须在函数入口处手动写上 pre = NULL;
    pre = NULL;  

    //  “如果不给我盒子（tree不存在），或者给了盒子但里面没东西（root不存在），那我就什么都不做，直接返回。”
    if (tree && tree->root) {
        inOrdering(tree->root);
        
        // 【修复点 2】处理最后一个节点 (烂尾收尾)
        // 此时 pre 指向中序遍历的最后一个节点 (图中的 C)
        if (pre->right == NULL) {
            pre->rtag = 1;      // 告诉后面的人：到站了，没路了
            pre->right = NULL;  // 显式封口
        }
    }
}