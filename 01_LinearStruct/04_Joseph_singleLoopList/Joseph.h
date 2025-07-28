#pragma once

typedef int Element_t;
// 链式存储，定义节点结构
typedef struct _node
{

    Element_t val;
    struct _node *next;
} node_t;

// 定义链表结构
typedef struct _Joseph
{
    node_t *head;
    node_t *tail;
} Joseph_t;

// 初始化约瑟夫环
void initJosephGame(Joseph_t *game, int n);

void showJoseph(const Joseph_t *game);

void startJosephGame(Joseph_t *game, int m);
