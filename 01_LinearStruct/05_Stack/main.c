#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

void test01(){
    ArrayStack *stack1 = createArrayStack();
    if (stack1 == NULL) {
        return;
    }
    for(int i = 0; i < 5; i++){
        pushArrayStack(stack1, i + 10);
    }
    printf("push 5 elements!\n");
    pushArrayStack(stack1, 300);

    //弹栈
    Element_t x1;
    for(int i = 0; i < MaxStackSize; i++){
        popArrayStack(stack1, &x1);
        printf("pop element: %d\n", x1);
    }
    printf("\n");
    releaseArrayStack(stack1);
}

int main() {
    test01();
    return 0;
}