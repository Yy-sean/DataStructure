#pragma once

typedef int value_t;
// 链式栈的节点结构
typedef struct _node
{
    value_t data;       // 栈元素
    struct _node *next; // 指向下一个节点的指针
} node_t;

// 定义链式栈的栈头
typedef struct
{
    node_t *top;
    int count; // 指向栈顶元素的指针
} LinkStack;

LinkStack *createLinkStack(); // 创建链式栈
void releaseLinkStack(LinkStack *stack);

int pushLinkStack(LinkStack *stack, value_t e);

// 之所以用 *e，是因为需要通过参数把弹出的栈顶元素的值“返回”给调用者。

// 原因如下：

// 如果用 value_t e（传值），函数内部对 e 的修改不会影响外部变量，调用者拿不到弹出的值。
// 用 value_t *e（传址），函数内部可以通过 *e = ... 把弹出的元素赋值给调用者传入的变量，实现“返回值”效果。
int popLinkStack(LinkStack *stack, value_t *e);