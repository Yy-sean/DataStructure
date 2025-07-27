#pragma once

typedef int Element_t;

typedef struct d_node
{
    Element_t val;
    struct d_node *prev;  // 前驱指针
    struct d_node *next;  // 后继指针
} DNode_t, DLinkHeader_t; // 头节点和中间的任意节点结构相同，只是名字不一样

/* 双向循环链表的头建议是用户自己维护，表头可放在栈上，也可以放全局变量上 */

void initDLink(DLinkHeader_t *header);

/* 插入： 头插法、尾插法 */
void insertDLinkHeader(DLinkHeader_t *header, Element_t val);
void insertDLinkRear(DLinkHeader_t *header, Element_t val);

/* 遍历双向循环链表 */
void showDLinkList(const DLinkHeader_t *header);