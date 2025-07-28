#include <stdio.h>
#include <stdlib.h>
#include "doubleLoopList.h"
void test01(){
    DLinkHeader_t stulink;
    initDLink(&stulink);
    for(int i = 0; i < 5; i++){
        insertDLinkHeader(&stulink, i+100);
    }
    showDLinkList(&stulink);
    for(int i = 0; i < 5; i++){
        insertDLinkRear(&stulink, i+100);
    }
    showDLinkList(&stulink);
}
int main(){
    test01();
    return 0;
}