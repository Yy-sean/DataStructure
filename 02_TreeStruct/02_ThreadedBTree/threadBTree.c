#include <stdio.h>
#include <stdlib.h>
#include "threadBTree.h"

TBTNode *createTBTNode(Element_t e) {
	TBTNode *node = malloc(sizeof(TBTNode));
	if (node == NULL) {
		return NULL;
	}
    node->data = e;
    node->left = node->right = NULL;
    node->lTag = node->rTag = 0;
    return node;
}

ThreadedBTree *createThreadedBTree(TBTNode *root) {
	ThreadedBTree *tree = malloc(sizeof(ThreadedBTree));
	if (tree == NULL) {
		return NULL;
	}
	tree->root = root;
	tree->count = 1;

	return tree;
}

void visitTBTNode(TBTNode *node) {
	if (node) {
		printf("\t%c", node->data);
	}
}

static void freeTBTNode(ThreadedBTree *tree, TBTNode *node) {
	if (node) {
		if (node->lTag == 0) {
			freeTBTNode(tree, node->left);
		}
		if (node->rTag == 0) {
			freeTBTNode(tree, node->right);
		}
		free(node);
		tree->count--;
	}
}

void releaseThreadedBTree(ThreadedBTree *tree) {
	freeTBTNode(tree, tree->root);
	printf("tree->node number: %d\n", tree->count);
}
// 插入节点到线索二叉树
void insertThreadedBTree(ThreadedBTree *tree, TBTNode *parent, TBTNode *left, TBTNode *right) {
    if (tree == NULL || parent == NULL) {
        return;
    }

    parent->left = left;
    parent->right = right;

    if (left != NULL) {
        parent->lTag = 0; // 指向左子树
    } else {
        parent->lTag = 1; // 指向前驱
    }

    if (right != NULL) {
        parent->rTag = 0; // 指向右子树
    } else {
        parent->rTag = 1; // 指向后继
    }

    tree->count++;
}

static TBTNode *pre = NULL; // 全局前驱节点指针
static void inOrdering(TBTNode *node) {
   if (node) {
        // 1. 递归左边
        inOrdering(node->left);

        // 2. 处理当前节点 (核心业务)

        // A. 处理左指针 (找前驱) 
        if (node->left == NULL) {
            node->lTag = 1; // 设置左标志为前驱
            node->left = pre; // 前驱节点
        }

        // B. 处理右指针 (帮前驱找后继)
        // 关键修复：必须判断 pre != NULL
        if(pre && pre->right == NULL) {
            pre->rTag = 1; // 设置前驱节点的右标志为后继
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
            pre->rTag = 1;      // 告诉后面的人：到站了，没路了
            pre->right = NULL;  // 显式封口
        }
    }
}

/* 1. 一路向左，找到虚线的节点，访问这个节点
 * 2.  以这个节点为准，一路向右（是虚线）
 * 3. 一路向右（是实线），把实线指向的节点当做新节点， 重复1
 */
void inOrderTravel(ThreadedBTree *tree){
    TBTNode *node = tree->root;
    while(node){
        // 1. 一路向左，找到可以作为线索的节点
        while(node->lTag == 0){
            node = node->left;
        }
        // 访问节点
        visitTBTNode(node);

        // 2.  以这个节点为准，一路向右（是虚线）
        // 只要是线索，就一直顺着线索往后跳
        while(node->rTag == 1 && node->right){
            node = node->right;
            visitTBTNode(node);
        }

        // 3. 一路向右（是实线），把实线指向的节点当做新节点， 重复1
        node = node->right;
    }
}
// 总结思路：  “一直往左钻 -> 触底反弹顺线索滑 -> 碰到实线切换右子树 -> 继续往左钻” 的循环
//          第一步：“钻” —— 找到起点 (Find Start)
//          第二步：“滑” —— 顺藤摸瓜 (Follow Threads) 
//          第三步：“跨” —— 切换跑道 (Switch to Right Subtree)
