#ifndef LINKLIST_LINKLIST_H

#include <stdlib.h>
#include "VisitorInfo.h"
#include <stdbool.h>


typedef struct List {
    VisitorInfo *data;
    struct List *next;
} ResidentInfoList;


/**
 * 尾插法增加链表元素
 * @param head
 * @param val
 * @return
 */
void append(ResidentInfoList *head, VisitorInfo *val);

void add(ResidentInfoList *head, VisitorInfo *val);

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
ResidentInfoList *createNode(VisitorInfo *val);

ResidentInfoList * createList();

void removeByIndex(ResidentInfoList *head, size_t index);

void toNums(VisitorInfo **nums, ResidentInfoList *head);

void printList(ResidentInfoList *head);

#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H
