#include <stdio.h>
#include "linkList.h"
void test01() {
    LinkList_t *link_table = createLinkList();
    if (link_table == NULL) {
        return;
    }
    for (int i = 0; i < 10; i++) {
        insertLinkListHeader(link_table, i+100);
    }
    showLinkList(link_table);
    printf("===========\n" );
    deleteLinkListElement(link_table, 109);
    deleteLinkListElement(link_table, 104);
    showLinkList(link_table);
    printf("===========\n" );

}
int main() {
    test01();
    return 0;  
    
}