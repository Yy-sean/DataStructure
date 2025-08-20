#pragma once

typedef int Element_t;

// 定义节点
typedef struct tree_node
{
    Element_t data;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode_t;

// 定义二叉树的头结构
typedef struct
{
    TreeNode_t *root;
    int num;
} BinaryTree;

BinaryTree *createBinaryTree(TreeNode_t *root);
TreeNode_t *createTreeNode(Element_t e);
void insertBinaryTree(BinaryTree *tree, TreeNode_t *parent, TreeNode_t *left, TreeNode_t *right);
void preOrderBTree(BinaryTree *tree);
void inOrderBTree(BinaryTree *tree);
void postOrderBTree(BinaryTree *tree);

void visitTreeNode(TreeNode_t *node);