#pragma once

typedef int Element_t;

//定义节点
typedef struct _bsNode{
    Element_t data;
    struct _bsNode *left;
    struct _bsNode *right;
}BSNode;

// 二分搜索树的结构
typedef struct {
    BSNode *root;
    int count;
}BSTree;

BSTree *createBSTree();
void releaseBSTree(BSTree *tree);

void insertBSTreeRecur(BSTree *tree, Element_t e);
void visitBSNode(BSNode *tree);