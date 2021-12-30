#ifndef EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H
#define EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H

#include <stdbool.h>
#include <stdio.h>


typedef unsigned short int HealthCode;

typedef struct rInfo {
    char name[20];
    char phoneNum[20];

    int buildingNum;
    int houseNum;

    HealthCode healthCode;
    bool isolation;
} ResidentInfo;

ResidentInfo *createResidentInfo();

ResidentInfo *
initResidentInfo(ResidentInfo *info, char *name, char *phone, int buildingNum, int houseNum, HealthCode healthCode,
                 bool isolation);

ResidentInfo *getResidentInfo(ResidentInfo *info);

void getResidentName(ResidentInfo *info);

void getResidentPhoneNum(ResidentInfo *info);

void getResidentAddress(ResidentInfo *info);

void getResidentHealthCode(ResidentInfo *info);

void getResidentIsolationStatus(ResidentInfo *info);

void printResidentData(ResidentInfo *data);

void saveResidentInfoToFile(FILE *file, ResidentInfo *info);

void residentListSortByName(ResidentInfo **resNums, size_t len);

void residentListSortByHealthCode(ResidentInfo **resNums, size_t len);

void residentListSortByAddress(ResidentInfo **resNums, size_t len);

void residentListSortByIsolation(ResidentInfo **resNums, size_t len);


#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H
