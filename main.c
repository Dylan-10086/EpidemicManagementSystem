#include <stdio.h>
#include "LinkList.h"

int main() {
    LinkList *list = createList();

    for (int i = 0; i < 2; i++) {
        add(list, initDataNode(createDataNode()));
    }

    printList(list);

    return 0;
}