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

static void preOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    visitTreeNode(node);
    preOrderNode(node->left);
    preOrderNode(node->right);
}

void preOrderBTree(BinaryTree *tree){
    if(tree){
        preOrderNode(tree->root);
    }
}

static void inOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    
    inOrderNode(node->left);
    visitTreeNode(node);
    inOrderNode(node->right);
}

void inOrderBTree(BinaryTree *tree){
    if(tree){
        inOrderNode(tree->root);
    }
}

static void postOrderNode(TreeNode_t *node){
    if(node == NULL){
        return;
    }
    
    postOrderNode(node->left);
    postOrderNode(node->right);
    visitTreeNode(node);
}

void postOrderBTree(BinaryTree *tree){
    if(tree){
        postOrderNode(tree->root);
    }
}