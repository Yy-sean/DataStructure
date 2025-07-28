#include <stdio.h>
#include <stdlib.h>
#include "doubleLoopList.h"

void initDLink(DLinkHeader_t *header){
    header->next = header;
    header->prev = header;
    header->val = 0;
}

static void addDnode(DLinkHeader_t *new_node, DNode_t *prev, DNode_t *next){
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;

}

void insertDLinkHeader(DLinkHeader_t *header, Element_t val){
    DNode_t *new_node = (DNode_t *)malloc(sizeof(DNode_t));
    new_node->val = val;
    /* 
    *   addDnode(new_node, header, header->next){
    *       (header->next)->prev = new_node; 
    *       new_node->next = header->next; 
    *       new_node->prev = header; 
    *       header->next = new_node;
    *   }
    *   
    */
    addDnode(new_node, header, header->next);
}

void insertDLinkRear(DLinkHeader_t *header, Element_t val){
    DNode_t *new_node = (DNode_t *)malloc(sizeof(DNode_t));
    new_node->val = val;
    /* 
    *   addDnode(new_node, header->prev, header){
    *       (header)->prev = new_node; 
    *       new_node->next = (header); 
    *       new_node->prev = (header->prev);
    *       (header->prev)->next = new_node;
    *   }
    *   
    */
    addDnode(new_node, header->prev, header);
}
void showDLinkList(const DLinkHeader_t *header){
    DNode_t *pos = header->next;
    while(pos != header){
        printf("%d\t ", pos->val);
        pos = pos->next;
    }
    printf("\n");
}

static void deleteDnode(DNode_t *prev, DNode_t *next){
    prev->next = next;
    next->prev = prev;
}


void deleteDLink(DLinkHeader_t *header, Element_t e){
    // 1. 找到这个元素，就可以直接删除， 不需要前置节点
    DNode_t *pos = header->next;

    while(pos != header){
        if(pos->val == e){
            deleteDnode(pos->prev, pos->next);
            free(pos);
            return;
        }
        pos = pos->next;
    }
    //2. 找不到
    printf("Element %d not found in the list.\n", e);
    
}