#ifndef EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H
#define EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H

#include <stdlib.h>
#include "ResidentInfo.h"

typedef struct rList {
    ResidentInfo *data;
    struct rList *next;
} ResidentInfoList;


/**
 * 尾插法增加链表元素
 * @param head
 * @param val
 * @return
 */
void appendResidentInfo(ResidentInfoList *head, ResidentInfo *val);

void addResidentInfo(ResidentInfoList *head, ResidentInfo *val);

/**
 * 按索引获取元素，索引的行为和数组相同
 * @param head
 * @param index
 * @return
 */
ResidentInfoList *getResidentInfoByIndex(ResidentInfoList *head, size_t index);

/**
 * 创建一个节点
 * @param val
 * @return
 */
ResidentInfoList *createResidentInfoListNode(ResidentInfo *val);

ResidentInfoList *createResidentInfoList();

void removeResidentInfoByIndex(ResidentInfoList *head, size_t index);

bool removeResidentInfo(ResidentInfoList *head, ResidentInfo *info);

void residentInfoListToNums(ResidentInfo **nums, ResidentInfoList *head);

void printResidentList(ResidentInfoList *head);

void saveResidentInfoListToFile(const char *fileName, ResidentInfoList *head);

void readResidentInfoListFromFile(const char *fileName, ResidentInfoList *head);

void residentListSortByName(ResidentInfo **resNums, size_t len);

void residentListSortByHealthCode(ResidentInfo **resNums, size_t len);

void residentListSortByAddress(ResidentInfo **resNums, size_t len);

void residentListSortByIsolation(ResidentInfo **resNums, size_t len);

ResidentInfoList *residentListSearchByName(ResidentInfoList *head, const char *name);

ResidentInfoList *residentListSearchByPhone(ResidentInfoList *head, const char *phone);

ResidentInfoList *residentListSearchByHealthCode(ResidentInfoList *head, HealthCode healthCode);

ResidentInfoList *residentListSearchByBuildingNum(ResidentInfoList *head, int bNum);

ResidentInfoList *residentListSearchByHouseNum(ResidentInfoList *head, int hNum);

ResidentInfoList *residentListSearchByIsolation(ResidentInfoList *head, int isolation);

#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H
