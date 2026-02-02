#pragma once

// 定义线索二叉树的节点结构
typedef int Element_t;                // 给 int 起个艺名叫 Element_t
typedef struct _node{
    Element_t data;                  // 节点数据
    struct _node *left;            // 左子节点指针
    struct _node *right;            // 右子节点指针
    int ltag;                        // 左标志，0表示指向左子树，1表示指向前驱
    int rtag;                        // 右标志，0表示指向右子树，1表示指向后继
} TBTNode;

// 二叉线索树的头
typedef struct{
    TBTNode *root;                  // 根节点指针
    int count;                   
} ThreadedBTree;

ThreadedBTree* createThreadedBTree(TBTNode *root);    // 创建空的线索二叉树
void releaseThreadedBTree(ThreadedBTree *tree); // 释放线索二叉树
void insertThreadedBTree(ThreadedBTree *tree, TBTNode *parent, TBTNode *left, TBTNode *right); // 插入节点
void visitTBTNode(TBTNode *node); // 访问节点

// 中序线索化二叉树
void inOrderThreading(ThreadedBTree *tree); 
// 线索化后， 开始二叉树的中序遍历
void inOrderTravel(ThreadedBTree *tree, void (*visit)(TBTNode *node));