#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

void initJosephGame(Joseph_t *game, int n){
    
    node_t *node = NULL;
    for(int i=1; i<=n; i++){
        node = (node_t*)malloc(sizeof(node_t));
        node->val = i;
        

        if(game->head == NULL){
            game->head = game->tail = node;
        } else {
            game->tail->next = node;
            game->tail = node;
        }
        game->tail->next = game->head; // make it circular

    }
}

void showJoseph(const Joseph_t *game){
    if(game->head == NULL){
        printf("The Joseph game is empty.\n");
        return;
    }
    node_t *p = game->head;

    //使用 do-while，即使链表中只有一个节点，循环体也会先执行一次，保证这个节点被访问和打印。
    //对于循环链表，这样可以正确遍历并输出所有节点。
    do{
        printf("%d\n", p->val);
        p = p->next;
    } while(p != game->head);
    printf("\n");

}

void startJosephGame(Joseph_t *game, int m){
    node_t *prev = NULL;
    node_t *curr = game->head;

    while(curr->next != curr){ // 直到只剩一个节点
        // 报数
        prev = curr;
        for(int i=1; i<m; i++){
            prev = curr;
            curr = curr->next;
        }

        // 删除当前节点
        prev->next = curr->next;
        printf("%d   ", curr->val);
        free(curr);
        curr = prev->next; // 移动到下一个节点     
    }
    printf("have %d number !\n", curr->val);
}
