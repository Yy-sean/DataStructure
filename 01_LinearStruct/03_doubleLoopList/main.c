#include <stdio.h>
#include <stdlib.h>
#include "doubleLoopList.h"
DLinkHeader_t stulink;
void test01(){
    
    initDLink(&stulink);
    for(int i = 0; i < 5; i++){
        insertDLinkRear(&stulink, i+100);
    }
    showDLinkList(&stulink);
    insertDLinkHeader(&stulink, 800);
    insertDLinkHeader(&stulink, 500);
    deleteDLink(&stulink, 103);
    showDLinkList(&stulink);
    printf("num: %d\n", stulink.val);
    //deleteAllDLinkV1(&stulink);
    //printf("num: %d\n", stulink.val);
    deleteAllDLinkV2(&stulink);
    printf("num: %d\n", stulink.val);
}
int main(){
    test01();
    return 0;
}