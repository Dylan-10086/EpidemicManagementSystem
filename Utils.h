#ifndef EPIDEMICMANAGEMENTSYSTEM_UTILS_H
#define EPIDEMICMANAGEMENTSYSTEM_UTILS_H

#include <stdbool.h>
#include <time.h>
#include "VisitorInfo.h"

#define RED 0
#define YELLOW 1
#define GREEN 2

bool isNameValid(const char *name);

bool isPhoneNumValid(const char *phoneNum);

bool isTimeValid(Time *time);

bool isVisitorAddressValid(const char *address);

bool isResidentAddressValid(int buildingNum, int houseNum);

bool isHealthCodeValid(unsigned short int code);

bool isIsolationStatusValid(bool isolationStatus);


#endif //EPIDEMICMANAGEMENTSYSTEM_UTILS_H
