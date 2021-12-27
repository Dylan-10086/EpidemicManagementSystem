#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Data *createDataNode() {
    return (Data *) malloc(sizeof(Data));
}

Data *initDataNode(Data *data) {
    getName(data);
    getPhoneNum(data);
    getArriveTime(data);
    getLeaveTime(data);
    getFromWhere(data);
    getHealthCode(data);
    getRemarks(data);

    return data;
}

void getName(Data *data) {
    printf("\n请输入人员姓名:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isNameValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->name, temp);
}

void getPhoneNum(Data *data) {
    printf("\n请输入电话号码:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isPhoneNumValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->phoneNum, temp);
}

void getArriveTime(Data *data) {
    printf("\n请输入人员到达时间(?年?月?日?时?分, 空格隔开):\n");

    int year = -1, month = -1, day = -1, hour = -1, min = -1;

    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &min);

    Time *time = (Time *) malloc(sizeof(Time));
    time->tm_year = year;
    time->tm_mon = month;
    time->tm_mday = day;
    time->tm_hour = hour;
    time->tm_min = min;

    while (!isTimeValid(time)) {
        printf("输入错误,请重新输入!\n");
        scanf("%d %d %d %d %d", &year, &month, &day, &hour, &min);
    }
    data->arriveTime = time;
}

void getLeaveTime(Data *data) {
    printf("\n请输入人员离开时间(?年?月?日?时?分, 空格隔开):\n");

    int year = -1, month = -1, day = -1, hour = -1, min = -1;

    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &min);

    Time *time = (Time *) malloc(sizeof(Time));

    time->tm_year = year;
    time->tm_mon = month;
    time->tm_mday = day;
    time->tm_hour = hour;
    time->tm_min = min;
    time->tm_sec = 0;
    time->tm_isdst = 0;

    while (!isTimeValid(time)) {
        printf("输入错误,请重新输入!\n");
        scanf("%d %d %d %d %d", &year, &month, &day, &hour, &min);
    }
    data->leaveTime = time;
}

void getFromWhere(Data *data) {
    printf("\n请输入人员出发地:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isAddressValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->fromWhere, temp);
}

void getHealthCode(Data *data) {
    printf("\n请输入健康码情况(0:红; 1:黄; 2:绿):\n");

    unsigned short int temp;
    scanf("%hu", &temp);

    while (!isHealthCodeValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%hu", &temp);
    }

    data->HealthCode = temp;
}

void getRemarks(Data *data) {
    printf("请输入备注(可留空):\n");

    char temp;
    char str[256];

    getchar();
    while ((temp = (char) getchar()) != '\n') {
        strcat(str, &temp);
    }

    strcpy(data->remarks, str);
}

void printData(Data *data) {
    char *code;
    char red[] = "红码";
    char yellow[] = "黄码";
    char green[] = "绿码";


    switch (data->HealthCode) {
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

    printf("%s %s %d %d %s %s\n", data->name, data->phoneNum, data->arriveTime->tm_hour, data->leaveTime->tm_hour,
           data->fromWhere, code);
}

bool isHealthCodeValid(unsigned short int code) {
    if (0 <= code && code <= 2) {
        return true;
    }

    return false;
}

bool isAddressValid(const char *address) {
    return strlen(address) >= 0;
}

bool isTimeValid(Time *time) {
    if (time->tm_mon <= 0 || time->tm_mon > 12) {
        return false;
    }

    if (time->tm_mday <= 0 || time->tm_mday > 31) {
        return false;
    }

    if (time->tm_hour < 0 || time->tm_hour >= 24) {
        return false;
    }

    if (time->tm_min < 0 || time->tm_min >= 60) {
        return false;
    }

    return true;
}

bool isPhoneNumValid(const char *phoneNum) {
    return strlen(phoneNum) == 11;
}

bool isNameValid(const char *name) {
    return strlen(name) != 0;
}
