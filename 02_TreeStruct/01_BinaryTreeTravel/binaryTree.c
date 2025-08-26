#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#define MAX_QUEUE_SIZE 10

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

//后序遍历，删除每个节点

static void destroyTreeNode(BinaryTree *tree, TreeNode_t*node){
    if(node == NULL){
        return;
    }
    destroyTreeNode(tree,node->left);
    destroyTreeNode(tree,node->right);
    free(node);
    tree->num--;
}
void releaseBinaryTree(BinaryTree *tree){
    if(tree){

        destroyTreeNode(tree, tree->root);
        printf("tree count: %d\n", tree->num);
        free(tree);

    }
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
        printf("PreOrderBTree: ");
        preOrderNode(tree->root);
    }
}



void inOrderBTree(BinaryTree *tree){
    if(tree){
        printf("InOrderBTree: ");
        inOrderNode(tree->root);
    }
}

void postOrderBTree(BinaryTree *tree){
    if(tree){
        printf("PostOrderBTree: ");
        postOrderNode(tree->root);
    }
}

//层次遍历，激活一个节点，就可能产生两个新任务， 引入了缓存区
//查看任务，不断从缓存区获取任务
void levelOrderBTree(BinaryTree *tree){
    //1. 申请一个顺序队列，放到栈上，层次遍历结束后，自动回收
    TreeNode_t *queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    //2. 预激活队列
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    queue[rear] = tree->root;
    rear = (rear + 1) % MAX_QUEUE_SIZE;

    //3.不断地出队列，每出一个元素，就访问，执行访问逻辑，直到队列为空
    printf("LevelOrderBTree: \n");
    TreeNode_t *node;
    while (front != rear) {
        //3.1 出队一个元素， 处理一个任务
        node = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;

        //3.2 访问这个节点，再发现新任务
        visitTreeNode(node);
        if (node->left) {
            // 检查队列是否已满，避免覆盖
            if ((rear + 1) % MAX_QUEUE_SIZE == front) {
                printf("Queue overflow.\n");
                break;
            }
            queue[rear] = node->left;
            rear = (rear + 1) % MAX_QUEUE_SIZE;
        }
        if (node->right) {
            // 检查队列是否已满，避免覆盖
            if ((rear + 1) % MAX_QUEUE_SIZE == front) {
                printf("Queue overflow.\n");
                break;
            }
            queue[rear] = node->right;
            rear = (rear + 1) % MAX_QUEUE_SIZE;
        }
    }

}
