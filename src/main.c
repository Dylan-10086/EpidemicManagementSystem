#include "headers/ResidentInfo.h"
#include "headers/ResidentInfoList.h"


int main() {
    ResidentInfoList *list = createResidentInfoList();

    readResidentInfoListFromFile("../Data/residentData.txt", list);

    printResidentList(list);
    return 0;
}