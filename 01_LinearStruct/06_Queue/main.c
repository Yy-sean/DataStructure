#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "linkQueue.h"

void test01(){
    ArrayQueue *queue = createArrayQueue();
    if(queue == NULL) {
        return;
    }
    printf("Queue created.\n");
    printf("enQueueing elements:\n");
    for(int i = 0; i < 5; i++){
        if(enArrayQueue(queue, i+100) == 0){
            printf("enQueue element: %d\t\n", i+100);
        }
    }
    enArrayQueue(queue, 500);
    Element_t e;
    printf("\n");
    printf("deQueueing elements:\n");
    while(deArrayQueue(queue, &e) == 0){
        printf("deQueue element: %d\t\n", e);
    }
    printf("\n");
    releaseArrayQueue(queue);
}

void test02(){
    LinkQueue *queue = createLinkQueue();
    if(queue == NULL) {
        return;
    }
    printf("enQueueing elements:\n");
    for(int i = 0; i < 5; i++){
        if(enLinkQueue(queue, i+100) == 0){
            printf("enQueue element: %d\t\n", i+100);
        }
    }
    printf("\n");
    printf("deQueueing elements:\n");
    Element_t e;
    while(deLinkQueue(queue, &e) == 0){
        printf("deQueue element: %d\t\n", e);
    }
    printf("\n");
    releaseLinkQueue(queue);
}
int main() {
    test01();
    test02();
    return 0;
}