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
void append(ResidentInfoList *head, ResidentInfo *val);

void add(ResidentInfoList *head, ResidentInfo *val);

/**
 * 按索引获取元素，索引的行为和数组相同
 * @param head
 * @param index
 * @return
 */
ResidentInfoList *getByIndex(ResidentInfoList *head, size_t index);

/**
 * 创建一个节点
 * @param val
 * @return
 */
ResidentInfoList *createNode(ResidentInfo *val);

ResidentInfoList *createList();

void removeByIndex(ResidentInfoList *head, size_t index);

void toNums(ResidentInfo **nums, ResidentInfoList *head);

void printList(ResidentInfoList *head);

#endif //EPIDEMICMANAGEMENTSYSTEM_RESIDENTINFOLIST_H
