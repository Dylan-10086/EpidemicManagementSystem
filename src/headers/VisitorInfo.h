#ifndef EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H
#define EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

typedef struct tm Time;
typedef unsigned short int HealthCode;

typedef struct vInfo {
    char name[20];
    char phone[20];

    // 时间储存的是从1970年开始到输入时间到ms数
    time_t arriveTime;
    time_t leaveTime;

    char fromWhere[50];
    HealthCode healthCode;

    char remarks[256];
} VisitorInfo;

VisitorInfo *createVisitorInfo();

VisitorInfo *
initVisitorInfo(VisitorInfo *data, char *name, char *phone, long arrive, long leave, char *from, HealthCode healthCode,
                char *remarks);

VisitorInfo *getVisitorInfo(VisitorInfo *data);


void getVisitorName(VisitorInfo *data);


void getVisitorPhoneNum(VisitorInfo *data);


void getVisitorArriveTime(VisitorInfo *data);


void getVisitorLeaveTime(VisitorInfo *data);

void getVisitorFromWhere(VisitorInfo *data);


void getVisitorHealthCode(VisitorInfo *data);


void getVisitorRemarks(VisitorInfo *data);


void printVisitorData(VisitorInfo *data);

void saveVisitorInfoToFile(FILE *file, VisitorInfo *data);


#endif //EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H
