#include "linkStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkStack *createLinkStack()
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    if (stack == NULL) {
        printf("malloc failed!\n");
        return NULL;
    }
    stack->top = NULL;
    stack->count = 0; // 初始化栈的元素个数为0
    return stack;
}
int pushLinkStack(LinkStack *stack, value_t e){
    node_t *node = (node_t *)malloc(sizeof(node_t));

    node->data = e;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
}

int popLinkStack(LinkStack *stack, value_t *e){
    //1. 考虑underflow的情况
    if (stack->top == NULL) {
        printf("underflow!\n");
        return -1;
    }
    //2. 取出栈顶元素
    value_t x1 = stack->top->data;    
    node_t *tmp = stack->top;
    stack->top = tmp->next;
    free(tmp); //释放tmp节点的内存
    stack->count--;
    //3. 返回栈顶元素的值
    if(e){
        *e = x1;
    }
    return 0;
}

