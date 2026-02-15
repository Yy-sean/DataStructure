#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"

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