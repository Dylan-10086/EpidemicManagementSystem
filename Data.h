#ifndef EPIDEMICMANAGEMENTSYSTEM_DATA_H
#define EPIDEMICMANAGEMENTSYSTEM_DATA_H

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
} Data;


void getName(Data *data);

bool isNameValid(const char *name);

void getPhoneNum(Data *data);

bool isPhoneNumValid(const char *phoneNum);

void getArriveTime(Data *data);

bool isTimeValid(Time *time);

void getLeaveTime(Data *data);

void getFromWhere(Data *data);

bool isAddressValid(const char *address);

void getHealthCode(Data *data);

bool isHealthCodeValid(unsigned short int code);

void getRemarks(Data *data);

void getDataFromFile(Data *data, const char *filePath);

Data *createDataNode();

void printData(Data *data);

Data *initDataNode(Data *data);

#endif //EPIDEMICMANAGEMENTSYSTEM_DATA_H
