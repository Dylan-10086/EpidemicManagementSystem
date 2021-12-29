#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"
#include "headers/VisitorInfo.h"
#include "headers/VisitorInfoList.h"


int main() {
    VisitorInfoList *list = createVisitorInfoList();

    readVisitorInfoListFromFile("../Data/visitorData.txt", list);

    saveVisitorInfoListToFile("../Data/visitorData.txt", list);
    printVisitorInfoList(list);
    return 0;
}