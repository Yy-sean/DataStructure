#include "searchTree.h"
#include <stdio.h>
void test01(){
    Element_t data[] = {55, 33, 45, 100, 22, 80, 8,130};
    BSTree *tree = createBSTree();
    for(int i = 0; i < sizeof(data)/sizeof(data[0]); i++){
        insertBSTreeRecur(tree, data[i]);
    }
    printf("====================\n");
    inOrderBSTree(tree);

    releaseBSTree(tree);
}

int main(){
    test01();
    return 0;
}