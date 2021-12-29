#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"
#include "headers/VisitorInfo.h"
#include "headers/VisitorInfoList.h"


int main() {
    VisitorInfoList *list = createVisitorInfoList();

    readVisitorInfoListFromFile("../Data/visitorData.txt", list);

    VisitorInfo *nums[list->data->healthCode];

    visitorInfoListToNums(nums, list);

    visitorListSortByHealthCode(nums, list->data->healthCode);

    for (int i = 0; i < list->data->healthCode; i++) {
        printVisitorData(nums[i]);
    }
    return 0;
}