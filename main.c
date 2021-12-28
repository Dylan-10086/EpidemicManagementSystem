#include <stdio.h>
#include "LinkList.h"


int main() {
    LinkList *list = createList();

    for (int i = 0; i < 2; i++) {
        append(list, initDataNode(createDataNode()));
    }

    Data *nums[list->data->HealthCode];

    toNums(nums, list);


    for (int i = 0; i < 2; i++) {
        printData(nums[i]);
    }
    return 0;
}