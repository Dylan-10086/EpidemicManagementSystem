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


#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H
