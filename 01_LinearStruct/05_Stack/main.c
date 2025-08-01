#include <stdio.h>
#include <stdlib.h>
#include "linkStack.h"
#include "arrayStack.h"

#include <string.h>

void test01(){
    ArrayStack *stack1 = createArrayStack();
    if (stack1 == NULL) {
        return;
    }
    for(int i = 0; i < MaxStackSize; i++){
        pushArrayStack(stack1, i + 100);
    }
    printf("push 5 elements!\n");
    pushArrayStack(stack1, 300);

    //弹栈
    Element_t x1;
    for(int i = 0; i < MaxStackSize; i++){
        popArrayStack(stack1, &x1);
        printf("pop element: %d\t\n", x1);
    }
    printf("\n");
    releaseArrayStack(stack1);
}

void test02(){
    LinkStack *stack2 = createLinkStack();
    if (stack2 == NULL) {
        return;
    }

    for(int i = 0; i < MaxStackSize ; i++){
        pushLinkStack(stack2, i + 10);  
    }
    printf("push 5 elements!\n");
    pushLinkStack(stack2, 300);

    value_t x2 = 0;
    while(popLinkStack(stack2, &x2) != -1){
        printf("pop element: %d\t\n", x2);
    }
    printf("\n");
}
int main() {
    test01();
    test02();
    return 0;
}