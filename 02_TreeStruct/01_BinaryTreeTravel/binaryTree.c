#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

TreeNode_t *createTreeNode(Element_t e){
    TreeNode_t *node = (TreeNode_t *)malloc(sizeof(TreeNode_t));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    return node;

}
BinaryTree *createBinaryTree(TreeNode_t *root){
    if(root){
        BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
        if (tree == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        tree->root = root;
        tree->num = 1;
        return tree;
    }
    return NULL;
}

void visitTreeNode(TreeNode_t *node){
    if(node){
        printf("%c \t", node->data);
        
    }
}

void insertBinaryTree(BinaryTree *tree, TreeNode_t *parent, TreeNode_t *left, TreeNode_t *right){
    if(tree && parent){
        parent->left = left;
        parent->right = right;
        if (left) {
            tree->num++;
        }
        if (right) {
            tree->num++;
        }
    }
}


//为了安全，防止内部函数被外部调用，所以将内部函数声明为static，
//以此隐藏实现细节，只暴露必要的接口给外部使用者。
static void preOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    visitTreeNode(node);
    preOrderNode(node->left);
    preOrderNode(node->right);
}


static void inOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    
    inOrderNode(node->left);
    visitTreeNode(node);
    inOrderNode(node->right);
}

static void postOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    
    postOrderNode(node->left);
    postOrderNode(node->right);
    visitTreeNode(node);
}

void preOrderBTree(BinaryTree *tree){
    if(tree){
        preOrderNode(tree->root);
    }
}



void inOrderBTree(BinaryTree *tree){
    if(tree){
        inOrderNode(tree->root);
    }
}

void postOrderBTree(BinaryTree *tree){
    if(tree){
        postOrderNode(tree->root);
    }
}
