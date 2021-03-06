#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/ResidentInfo.h"
#include "../headers/Utils.h"

ResidentInfo *createResidentInfo() {
    return (ResidentInfo *) malloc(sizeof(ResidentInfo));
}

ResidentInfo *
initResidentInfo(ResidentInfo *info, char *name, char *phone, int buildingNum, int houseNum, HealthCode healthCode,
                 bool isolation) {
    strcpy(info->name, name);
    strcpy(info->phoneNum, phone);
    info->buildingNum = buildingNum;
    info->houseNum = houseNum;
    info->healthCode = healthCode;
    info->isolation = isolation;

    return info;
}

ResidentInfo *getResidentInfo(ResidentInfo *info) {
    getResidentName(info);
    getResidentPhoneNum(info);
    getResidentAddress(info);
    getResidentHealthCode(info);
    getResidentIsolationStatus(info);

    return info;
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

    info->healthCode = temp;
}

void getResidentIsolationStatus(ResidentInfo *info) {
    printf("\n是否隔离(0: 否; 1: 是):\n");

    int flag;
    scanf("%d", &flag);

    while (!isIsolationStatusValid(flag)) {
        printf("输入错误,请重新输入!\n");
        scanf("%d", &flag);

    }

    info->isolation = flag;
}

void saveResidentInfoToFile(FILE *file, ResidentInfo *info) {

    if (file == NULL) {
        printf("出错了!");
        return;
    }

    fprintf(file, "%s %s %d %d %hu %d\n", info->name, info->phoneNum, info->buildingNum, info->houseNum,
            info->healthCode, info->isolation);
}

void printResidentData(ResidentInfo *data) {
    char *code, *isolation;
    char red[] = "红码";
    char yellow[] = "黄码";
    char green[] = "绿码";
    char yes[] = "是";
    char no[] = "否";


    switch (data->healthCode) {
        case RED:
            code = red;
            break;
        case YELLOW:
            code = yellow;
            break;
        case GREEN:
            code = green;
            break;
    }

    if (data->isolation) {
        isolation = yes;
    } else {
        isolation = no;
    }

    printf("%s %s %d-%d %s %s\n", data->name, data->phoneNum, data->buildingNum, data->houseNum, code, isolation);
}