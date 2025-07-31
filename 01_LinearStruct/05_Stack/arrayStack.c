#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStack.h"

ArrayStack *createArrayStack(){
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        printf("malloc failed!\n");
        return NULL;
    }
    stack->top = -1; // 初始化栈顶索引
    memset(stack->data, 0, sizeof(stack->data)); // 将栈结构中的 data 数组的所有元素初始化为 0。
    return stack;
}

void releaseArrayStack(ArrayStack *stack){
    //你的 data 是数组，不是指针，不能 free(stack->data);，否则会导致未定义行为。
    if(stack){
        free(stack); // 释放栈结构的内存
    }
}

int pushArrayStack(ArrayStack *stack, Element_t e){
    //1. 考虑overflow的情况
    if (stack->top >= MaxStackSize - 1) {
        printf("stack overflow!\n");
        return -1;
    }

    //2. 更新栈空间
    stack->top++;
    stack->data[stack->top] = e;
    return 0;
}

int popArrayStack(ArrayStack *stack, Element_t *e){
    //1. 考虑underflow的情况
    if (stack->top < 0) {
        printf("stack underflow!\n");
        return -1;
    }

    //2. 取出栈顶元素    
    Element_t x1 = stack->data[stack->top];
    stack->top--;
    if (e) {
        *e = x1; // 将栈顶元素的值赋给 e
    }
    return 0; 
}
