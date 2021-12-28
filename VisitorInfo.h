#ifndef EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H
#define EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H

#include <stdbool.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

typedef struct tm Time;

typedef struct {
    char name[20];
    char phoneNum[20];

    Time *arriveTime;
    Time *leaveTime;

    char fromWhere[50];
    unsigned short int HealthCode;

    char remarks[256];
} VisitorInfo;


void getVisitorName(VisitorInfo *data);


void getVisitorPhoneNum(VisitorInfo *data);


void getVisitorArriveTime(VisitorInfo *data);


void getVisitorLeaveTime(VisitorInfo *data);

void getVisitorFromWhere(VisitorInfo *data);


void getVisitorHealthCode(VisitorInfo *data);


void getVisitorRemarks(VisitorInfo *data);

void getDataFromFile(VisitorInfo *data, const char *filePath);

VisitorInfo *createVisitorInfo();

void printData(VisitorInfo *data);

VisitorInfo *initVisitorInfo(VisitorInfo *data);

#endif //EPIDEMICMANAGEMENTSYSTEM_VISITORINFO_H
