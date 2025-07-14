#pragma once

typedef int Element_t;
// 链式存储，定义节点结构
typedef struct _node
{
    Element_t val;
    struct _node *next;
} node_t;

// 定义链表头结构
typedef struct
{
    node_t head; // 头节点
    int count;   // 链表长度
} LinkList_t;

LinkList_t *createLinkList(); // 创建链表

int insertLinkListHeader(LinkList_t *link_table, Element_t val);
int insertLinkListPos(LinkList_t *link_table, int pos, Element_t val);
int deleteLinkListElement(LinkList_t *link_table, Element_t val);
void showLinkList(LinkList_t *link_table); // 显示链表
