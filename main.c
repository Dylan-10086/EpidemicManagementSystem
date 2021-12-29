#include <stdio.h>
#include "VisitorInfoList.h"
#include "VisitorInfo.h"
#include "ResidentInfo.h"


int main() {
    ResidentInfoList *list = createList();

    for (int i = 0; i < 2; i++) {
        append(list, initVisitorInfo(createVisitorInfo()));
    }

    VisitorInfo *nums[list->data->HealthCode];

    toNums(nums, list);


    for (int i = 0; i < 2; i++) {
        printData(nums[i]);
    }
    return 0;
}