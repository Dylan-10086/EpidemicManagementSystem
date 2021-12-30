#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"
#include "headers/VisitorInfo.h"
#include "headers/VisitorInfoList.h"


int main() {
    VisitorInfoList *list = createVisitorInfoList();
    ResidentInfoList *residentInfoList = createResidentInfoList();

    readVisitorInfoListFromFile("../Data/visitorData.txt", list);
    readResidentInfoListFromFile("../Data/residentData.txt", residentInfoList);

    VisitorInfo *nums1[list->data->healthCode];
    ResidentInfo *nums2[residentInfoList->data->healthCode];

    visitorInfoListToNums(nums1, list);
    residentInfoListToNums(nums2, residentInfoList);

    visitorListSortByFromWhere(nums1, list->data->healthCode);
    residentListSortByIsolation(nums2, residentInfoList->data->healthCode);

    for (int i = 0; i < list->data->healthCode; i++) {
        printVisitorData(nums1[i]);
    }

    for (int i = 0; i < residentInfoList->data->healthCode; i++) {
        printResidentData(nums2[i]);
    }
    return 0;
}