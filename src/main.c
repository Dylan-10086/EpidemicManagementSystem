#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"
#include "headers/VisitorInfo.h"
#include "headers/VisitorInfoList.h"

#define visitorFile "../Data/visitorData.txt"
#define residentFile "../Data/residentData.txt"


int main() {
    VisitorInfoList *list = createVisitorInfoList();

//    appendVisitorInfo(list, getVisitorInfo(createVisitorInfo()));
//    saveVisitorInfoListToFile(visitorFile, list);

    readVisitorInfoListFromFile("../Data/visitorData.txt", list);

    VisitorInfo *nums1[list->data->healthCode];

    visitorInfoListToNums(nums1, list);

    visitorListSortByName(nums1, list->data->healthCode);

    for (int i = 0; i < list->data->healthCode; i++) {
        printVisitorData(nums1[i]);
    }
    printf("\n");

    printVisitorInfoList(visitorListSearchByArrive(list, createTime(2021, 2, 1, 12, 00)));
    return 0;
}