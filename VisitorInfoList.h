#ifndef LINKLIST_LINKLIST_H

#include <stdlib.h>
#include "VisitorInfo.h"
#include <stdbool.h>


typedef struct List {
    VisitorInfo *data;
    struct List *next;
} VisitorInfoList;


/**
 * 尾插法增加链表元素
 * @param head
 * @param val
 * @return
 */
void appendVisitorInfo(VisitorInfoList *head, VisitorInfo *val);

void addVisitorInfo(VisitorInfoList *head, VisitorInfo *val);

/**
 * 按索引获取元素，索引的行为和数组相同
 * @param head
 * @param index
 * @return
 */
VisitorInfoList *getVisitorInfoByIndex(VisitorInfoList *head, size_t index);

/**
 * 创建一个节点
 * @param val
 * @return
 */
VisitorInfoList *createVisitorInfoListNode(VisitorInfo *val);

VisitorInfoList *createVisitorInfoList();

void removeVisitorInfoByIndex(VisitorInfoList *head, size_t index);

void visitorInfoListToNums(VisitorInfo **nums, VisitorInfoList *head);

void printVisitorInfoList(VisitorInfoList *head);

#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H
