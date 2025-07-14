#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"

LinkList_t *createLinkList(){
    LinkList_t *link_table = NULL;
    link_table = (LinkList_t *)malloc(sizeof(LinkList_t));
    if(link_table == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    link_table->count = 0;
    link_table->head.val = 0; // 初始化头节点的值为0, 方便后续插入操作(也可取任意值，自行约定)
    link_table->head.next = NULL;

    return link_table;
}

// 头插法插入链表, 无需再寻找插入位置的前置节点
// 带头节点的链表，头节点就是头插法的前置节点
int insertLinkListHeader(LinkList_t *link_table, Element_t val){
    node_t *p = &link_table->head;// 指向头节点
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if(new_node == NULL){
        printf("Memory allocation failed.\n");
        return -1;
    }
    new_node->val = val;// 新节点的值

    new_node->next = p->next;
    p->next = new_node;

    link_table->count++;

    return 0;
}

void showLinkList(LinkList_t *link_table){
    //辅助指针指向第一个元素，辅助指针不断向后指向，直到遇到NULL
    node_t *p = link_table->head.next;// head.next 本身就是一个指针，应该直接使用它的值
    while(p!= NULL){
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");
}

