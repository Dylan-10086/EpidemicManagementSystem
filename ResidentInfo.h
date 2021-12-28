#ifndef EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H
#define EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H

#include <stdbool.h>


typedef struct {
    char name[20];
    char phoneNum[20];

    int buildingNum;
    int houseNum;

    unsigned short int HealthCode;

    bool isolation;
} ResidentInfo;

ResidentInfo *createResidentInfo();

ResidentInfo *initResidentInfo(ResidentInfo *info);

void getResidentName(ResidentInfo *info);

void getResidentPhoneNum(ResidentInfo *info);

void getResidentAddress(ResidentInfo *info);

void getResidentHealthCode(ResidentInfo *info);

void getResidentIsolationStatus(ResidentInfo *info);


#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFO_H
