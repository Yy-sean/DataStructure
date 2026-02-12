#pragma once
#include "binaryTree.h"
typedef TreeNode_t* data_t;
#define MaxStackSize  10

typedef struct
{
    data_t data[MaxStackSize];
    int top; // index of top element
} ArrayStack;

// 满递增栈
ArrayStack *createArrayStack();

void releaseArrayStack(ArrayStack *stack);

int pushArrayStack(ArrayStack *stack, data_t e);

/*
popArrayStack为什么使用 *e？

1.传值 vs. 传址：
    如果直接传递 data_t e（传值），函数内部对 e 的修改不会影响调用者的变量。
    如果使用 data_t* e（传址）可以通过指针间接修改调用者传入的变量，实现数据的“返回”。

2.数据传递：
    函数内部将栈顶元素的值赋给 *e，调用者可以通过 e 指针获取弹出的值。
*/
int popArrayStack(ArrayStack *stack, data_t *e);