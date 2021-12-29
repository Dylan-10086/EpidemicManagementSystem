#include "../headers/VisitorInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/Utils.h"

VisitorInfo *createVisitorInfo() {
    return (VisitorInfo *) malloc(sizeof(VisitorInfo));
}

VisitorInfo *
initVisitorInfo(VisitorInfo *data, char *name, char *phone, long arrive, long leave, char *from, HealthCode healthCode,
                char *remarks) {
    strcpy(data->name, name);
    strcpy(data->phone, phone);
    data->arriveTime = arrive;
    data->leaveTime = leave;
    strcpy(data->fromWhere, from);
    data->healthCode = healthCode;
    strcpy(data->remarks, remarks);

    return data;
}

VisitorInfo *getVisitorInfo(VisitorInfo *data) {
    getVisitorName(data);
    getVisitorPhoneNum(data);
    getVisitorArriveTime(data);
    getVisitorLeaveTime(data);
    getVisitorFromWhere(data);
    getVisitorHealthCode(data);
    getVisitorRemarks(data);

    return data;
}

void getVisitorName(VisitorInfo *data) {
    printf("\n请输入人员姓名:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isNameValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->name, temp);
}

void getVisitorPhoneNum(VisitorInfo *data) {
    printf("\n请输入电话号码:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isPhoneNumValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->phone, temp);
}

void getVisitorArriveTime(VisitorInfo *data) {
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
    data->arriveTime = mktime(time);
}

void getVisitorLeaveTime(VisitorInfo *data) {
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
    data->leaveTime = mktime(time);
}

void getVisitorFromWhere(VisitorInfo *data) {
    printf("\n请输入人员出发地:\n");

    char temp[50];
    scanf("%s", temp);

    while (!isVisitorAddressValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%s", temp);
    }

    strcpy(data->fromWhere, temp);
}

void getVisitorHealthCode(VisitorInfo *data) {
    printf("\n请输入健康码情况(0:红; 1:黄; 2:绿):\n");

    unsigned short int temp;
    scanf("%hu", &temp);

    while (!isHealthCodeValid(temp)) {
        printf("输入错误,请重新输入!\n");
        scanf("%hu", &temp);
    }

    data->healthCode = temp;
}

void getVisitorRemarks(VisitorInfo *data) {
    printf("请输入备注(可留空):\n");

    char temp;
    char str[256];

    getchar();
    scanf("%[^\n]", str);

    strcpy(data->remarks, str);
}

void printVisitorData(VisitorInfo *data) {
    char *code;
    char red[] = "红码";
    char yellow[] = "黄码";
    char green[] = "绿码";


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

    printf("%s %s %ld %ld %s %s\n", data->name, data->phone, data->arriveTime, data->leaveTime,
           data->fromWhere, code);
}

void saveVisitorInfoToFile(FILE *file, VisitorInfo *data) {
    if (file == NULL) {
        printf("出错了!");
        return;
    }

    fprintf(file, "%s %s %ld %ld %s %hu %s\n", data->name, data->phone, data->arriveTime, data->leaveTime,
            data->fromWhere, data->healthCode, data->remarks);
}