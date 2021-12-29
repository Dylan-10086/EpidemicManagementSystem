#ifndef EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H
#define EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H

#include <stdlib.h>
#include "ResidentInfo.h"

typedef struct List {
    ResidentInfo *data;
    struct List *next;
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

void ResidentInfoListToNums(ResidentInfo **nums, ResidentInfoList *head);

void printResidentList(ResidentInfoList *head);

#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H
