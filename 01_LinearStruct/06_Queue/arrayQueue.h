#pragma once

#define MaxQueueSize 5

typedef int Element_t;

// 定义顺序队列的结构
typedef struct
{
    Element_t data[MaxQueueSize];
    int front;
    int rear;
} ArrayQueue;

ArrayQueue *createArrayQueue();
void releaseArrayQueue(ArrayQueue *queue);

int enArrayQueue(ArrayQueue *queue, Element_t e);
int deArrayQueue(ArrayQueue *queue, Element_t *e);