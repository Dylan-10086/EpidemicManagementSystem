#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"


int main() {
    ResidentInfoList *list = createResidentInfoList();

    for (int i = 0; i < 2; i++) {
        appendResidentInfo(list, initResidentInfo(createResidentInfo()));
    }

    ResidentInfo *nums[list->data->HealthCode];

    ResidentInfoListToNums(nums, list);


    for (int i = 0; i < 2; i++) {
        printResidentData(nums[i]);
    }
    return 0;
}