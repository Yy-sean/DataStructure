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

// 头插法插入链表, 无需再寻找插入位置的前置节点----倒序链表，最后插入的在最前面
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


int insertLinkListPos(LinkList_t *link_table, int pos, Element_t val){
    if(pos <1 || pos > link_table->count+1){//+1 是因为允许在链表末尾之后插入新节点
        printf("Position out of range.\n");
        return -1; // 位置超出范围
    }
    
    node_t *prev = &link_table->head;
    int prev_index = 0;// 记录插入位置的前置节点的索引,`index = -1` 的设计强制区分头节点和数据节点，减少歧义。

    while(prev->next != NULL && prev_index < pos-1){
        prev = prev->next;
        prev_index++;
    }
    
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if(new_node == NULL){//在C语言中，使用malloc函数分配内存时，如果内存分配失败，malloc将返回NULL
        printf("Memory allocation failed.\n");
        return -1;
    }
    new_node->val = val;
    new_node->next = prev->next;
    prev->next = new_node;
    link_table->count++;
    return 0;
}
int deleteLinkListElement(LinkList_t *link_table, Element_t val){
    //辅助指针，指向val这个元素的前置节点
    node_t *p = &link_table->head;
    while(p){
        if(p->next->val == val){
            break;
        }
        p = p->next;
    }if(p->next == NULL){
        printf("Element %d not found in the list.\n", val);
        return -1; // 元素未找到
    }
    node_t *tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    link_table->count--;
    return 0;
}
void showLinkList( const LinkList_t *link_table){
    //辅助指针指向第一个元素，辅助指针不断向后指向，直到遇到NULL
    node_t *p = link_table->head.next;// head.next 本身就是一个指针，应该直接使用它的值
    printf("LinkList:%d\n", link_table->count);
    while(p!= NULL){
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");
}

