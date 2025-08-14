#pragma once

typedef int value_t;
// 先定义节点
typedef struct _node
{
    value_t data;
    struct _node *next;
} node_t;

// 定义链式队列的头结构
typedef struct
{
    node_t *front;
    node_t *rear;
    int count;
} LinkQueue;

LinkQueue *createLinkQueue();
void releaseLinkQueue(LinkQueue *linkQueue);
int enLinkQueue(LinkQueue *linkQueue, value_t e);
int deLinkQueue(LinkQueue *linkQueue, value_t *e);
