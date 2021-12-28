#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ResidentInfo.h"
#include "Utils.h"

ResidentInfo *createResidentInfo() {
    return (ResidentInfo *) malloc(sizeof(ResidentInfo));
}

ResidentInfo *initResidentInfo(ResidentInfo *info) {
    getResidentName(info);
    getResidentPhoneNum(info);
    getResidentAddress(info);
    getResidentHealthCode(info);
    getResidentIsolationStatus(info);
}

void getResidentName(ResidentInfo *info) {
    printf("\n请输入居民姓名:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isNameValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(info->name, temp);
}

void getResidentPhoneNum(ResidentInfo *info) {
    printf("\n请输入电话号码:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isPhoneNumValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(info->phoneNum, temp);
}

void getResidentAddress(ResidentInfo *info) {
    printf("\n请输入居民住宅地址(楼号 门牌号):\n");

    int bNum, hNum;
    scanf("%d %d", &bNum, &hNum);

    while (!isResidentAddressValid(bNum, hNum)) {
        printf("输入错误,请重新输入!\n");
        scanf("%d %d", &bNum, &hNum);
    }

    info->buildingNum = bNum;
    info->houseNum = hNum;
}

void getResidentHealthCode(ResidentInfo *info) {
    printf("\n请输入健康码情况(0:红; 1:黄; 2:绿):\n");

    unsigned short int temp;
    scanf("%hu", &temp);

    while (!isHealthCodeValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%hu", &temp);
    }

    info->HealthCode = temp;
}

void getResidentIsolationStatus(ResidentInfo *info) {
    printf("\n请输入人员姓名:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isNameValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(info->name, temp);
}