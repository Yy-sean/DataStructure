#include <stdio.h>
#include <stdlib.h>
#include "linkQueue.h"

LinkQueue *createLinkQueue() {
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    queue->count = 0;
    return queue;
}

void releaseLinkQueue(LinkQueue *linkQueue) {
    if (linkQueue) {
        // 从队头开始逐个删除
        node_t *tmp;
        while(linkQueue->front){
            tmp = linkQueue->front;
            linkQueue->front = tmp->next;
            free(tmp);
            --linkQueue->count;
        }
        printf("LinkQueue last %d node.\n", linkQueue->count);
        free(linkQueue);
    }
}

int enLinkQueue(LinkQueue *linkQueue, value_t e) {
    // 1. 先申请新节点
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    
    node->data = e;
    node->next = NULL;
    // 2. 尾插法 ， 首次插入与后续插入
    if(linkQueue->rear ) { 
        //后续插入
        linkQueue->rear->next = node;
        linkQueue->rear = node;
    }
    else {
        //首次插入
        linkQueue->front = linkQueue->rear = node;
    }
    linkQueue->count++;
    return 0;
}

int deLinkQueue(LinkQueue *linkQueue, value_t *e) {
    //1. 队列为空，返回错误
    if (linkQueue && linkQueue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    //2. 头删
    if(e){
        *e = linkQueue->front->data;
    }
    node_t *tmp = linkQueue->front;
    linkQueue->front = tmp->next;
    free(tmp);
    --linkQueue->count;
    //3. 如果删除的是最后一个元素
    if(linkQueue->front == NULL){
        linkQueue->rear = NULL;
    }
    return 0;
}
