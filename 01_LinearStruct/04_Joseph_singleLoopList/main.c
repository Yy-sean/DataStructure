#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

void test01() {
    Joseph_t game1 = { NULL, NULL };

    initJosephGame(&game1, 10);
    showJoseph(&game1);

    startJosephGame(&game1, 3);
    
}
int main() {
    test01();
    return 0;
}
