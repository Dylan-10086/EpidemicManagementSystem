//
// Created by 小学二年级的刘同学 on 2021/12/28.
//
#include <string.h>
#include "Utils.h"

bool isHealthCodeValid(unsigned short int code) {
    if (0 <= code && code <= 2) {
        return true;
    }

    return false;
}

bool isVisitorAddressValid(const char *address) {
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