#include <stdio.h>
#include "threadBTree.h"

ThreadedBTree *initTree() {
	TBTNode *nodeA = createTBTNode('A');
	TBTNode *nodeB = createTBTNode('B');
	TBTNode *nodeC = createTBTNode('C');
	TBTNode *nodeD = createTBTNode('D');
	TBTNode *nodeE = createTBTNode('E');
	TBTNode *nodeF = createTBTNode('F');
	TBTNode *nodeG = createTBTNode('G');
	TBTNode *nodeH = createTBTNode('H');
	TBTNode *nodeK = createTBTNode('K');

	ThreadedBTree *tree = createThreadBTree(nodeA);
	insertThreadBTree(tree, nodeA, nodeB, nodeE);
	insertThreadBTree(tree, nodeB, NULL, nodeC);
	insertThreadBTree(tree, nodeE, NULL, nodeF);
	insertThreadBTree(tree, nodeC, nodeD, NULL);
	insertThreadBTree(tree, nodeF, nodeG, NULL);
	insertThreadBTree(tree, nodeG, nodeH, nodeK);

	return tree;
}

int test01() {
	ThreadedBTree *tree1 = initTree();
	printf("tree node: %d\n", tree1->count);

	inOrderThreading(tree1);
	printf("inOrder: \t");
	inOrderTravel(tree1);
	printf("\n");

	releaseThreadBTree(tree1);
	return 0;
}

int main() {
	test01();

	return 0;
}
