#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

BinaryTree *initTree(){
    TreeNode_t *nodeA = createTreeNode('A');
    TreeNode_t *nodeB = createTreeNode('B');
    TreeNode_t *nodeC = createTreeNode('C');
    TreeNode_t *nodeD = createTreeNode('D');
    TreeNode_t *nodeE = createTreeNode('E');
    TreeNode_t *nodeF = createTreeNode('F');
    TreeNode_t *nodeG = createTreeNode('G');
    TreeNode_t *nodeH = createTreeNode('H');
    TreeNode_t *nodeK = createTreeNode('K');

    BinaryTree *tree = createBinaryTree(nodeA);
    insertBinaryTree(tree, nodeA, nodeB, nodeE);
    insertBinaryTree(tree, nodeB, NULL, nodeC);
    insertBinaryTree(tree, nodeE, NULL, nodeF);
    insertBinaryTree(tree, nodeC, nodeD, NULL);
    insertBinaryTree(tree, nodeF, nodeG, NULL);
    insertBinaryTree(tree, nodeG, nodeH, nodeK);

    return tree;
}

int main(){
    BinaryTree *tree = initTree();
    printf("Tree has %d nodes.\n", tree->num);
    printf("PreOrder: ");
    preOrderBTree(tree);
    printf("\n");
    printf("InOrder: ");
    inOrderBTree(tree);
    printf("\n");
    printf("PostOrder: ");
    postOrderBTree(tree);
    return 0;
}