#ifndef LINKLIST_LINKLIST_H

#include <stdlib.h>
#include "VisitorInfo.h"
#include <stdbool.h>


typedef struct vList {
    VisitorInfo *data;
    struct vList *next;
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

/**
 * 变成数组
 * @param desNums
 * @param head
 *
 * 使用方法:
 * VisitorInfo *nums[head->data->healthCode];
 * visitorInfoListToNums(nums, head);
 */
void visitorInfoListToNums(VisitorInfo **desNums, VisitorInfoList *head);

void printVisitorInfoList(VisitorInfoList *head);

void saveVisitorInfoListToFile(const char *fileName, VisitorInfoList *head);

void readVisitorInfoListFromFile(const char *fileName, VisitorInfoList *head);

void visitorListSortByName(VisitorInfo **resNums, VisitorInfoList *head);
#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H
