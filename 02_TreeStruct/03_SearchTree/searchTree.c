#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"

// 1. 创建树
BSTree *createBSTree(){
    BSTree *tree = (BSTree *)malloc(sizeof(BSTree));
    if(tree == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

// 2. 递归释放节点内存 (后序遍历)
static void freeNode(BSTree *tree, BSNode *node){
    if(node != NULL){
        freeNode(tree, node->left);
        freeNode(tree, node->right);
        free(node);
        tree->count--;
    }
}

// 3. 释放整棵树
void releaseBSTree(BSTree *tree){
    if(tree != NULL){
        freeNode(tree, tree->root); // 调用 freeNode 释放树的所有节点
        printf("BSTree released successfully. Remaining node count: %d\n", tree->count);
        free(tree); // 释放树的控制结构
    }
}

// 4. 创建单个节点
static BSNode *createBSNode(Element_t e){
    BSNode *node = (BSNode *)malloc(sizeof(BSNode));
    if(node == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 5. 递归插入节点 (修复了断链 Bug)
static BSNode *insertBSNodeRecur(BSTree *tree, BSNode *node, Element_t e){
    if(node == NULL){
        tree->count++;
        return createBSNode(e); 
    }
    
    // 必须将返回值重新赋值给左右指针，才能把树连起来！
    if(e < node->data){
        node->left = insertBSNodeRecur(tree, node->left, e);
    } else {
        node->right = insertBSNodeRecur(tree, node->right, e);
    }
    return node;
}

// 6. 对外的插入接口 (递归版实现)
void insertBSTreeRecur(BSTree *tree, Element_t e){
    if(tree == NULL){
        printf("Tree is NULL.\n");
        return;
    }
    // 必须更新 tree->root，否则空树插入第一个节点时 root 永远是 NULL
    tree->root = insertBSNodeRecur(tree, tree->root, e);
}

void visitBSNode(BSNode *node){
    if(node != NULL){
        printf("\t%d ", node->data);
    }
}

static void inOrderBSNode(BSNode *node){
    if(node != NULL){
        inOrderBSNode(node->left);
        visitBSNode(node);
        inOrderBSNode(node->right);
    }
}
void inOrderBSTree(BSTree *tree){
    if(tree != NULL){
        printf("In-order traversal of BSTree:");
        inOrderBSNode(tree->root);
        printf("\n");
    }
}
// 7. 补充：非递归（迭代）版插入接口 
// (根据你原代码末尾的残缺片段修复并补全)
void insertBSTreeIterative(BSTree *tree, Element_t e){
    if(tree == NULL) return;

    BSNode *newNode = createBSNode(e);
    if(newNode == NULL) return;

    if(tree->root == NULL){
        tree->root = newNode;
        tree->count++;
        return;
    }

    BSNode *current = tree->root;
    BSNode *parent = NULL;

    while(current != NULL){
        parent = current;
        if(e < current->data){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if(e < parent->data){
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    tree->count++;
}