#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayQueue.h"

ArrayQueue *createArrayQueue(){
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if(queue == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    //void *memset(void *_Dst, int _Val, size_t _Size)
    memset(queue, 0, sizeof(ArrayQueue));
    queue->front = queue->rear = 0; //显式初始化 front 和 rear 为 0，确保逻辑清晰。
    
    return queue;
}

void releaseArrayQueue(ArrayQueue *queue){
    if(queue != NULL){
        free(queue);
    }
}

int enArrayQueue(ArrayQueue *queue, Element_t e){
    //1. 判断队列是否已满
    if((queue->rear + 1) % MaxQueueSize == queue->front){
        printf("Queue is full.\n");
        return -1;
    }
    //2. 已经试探完成，再插入(保证和删除是同逻辑就行)，入队时，rear 先移动再赋值
    queue->rear = (queue->rear + 1) % MaxQueueSize;
    queue->data[queue->rear] = e;
    return 0;
}

int deArrayQueue(ArrayQueue *queue, Element_t *e){
    //1. 判断队列是否为空
    if(queue->front == queue->rear){
        printf("Queue is empty.\n");
        return -1;
    }
    //2. 已经试探完成，再删除(保证和插入是同逻辑就行)，出队时，front 先移动再取值
    queue->front = (queue->front + 1) % MaxQueueSize;
    if(e){
        *e = queue->data[queue->front];
    }
    
    return 0;
}