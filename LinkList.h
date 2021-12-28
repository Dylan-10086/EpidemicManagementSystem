#ifndef LINKLIST_LINKLIST_H

#include <stdlib.h>
#include "VisitorInfo.h"
#include <stdbool.h>


typedef struct List {
    VisitorInfo *data;
    struct List *next;
} LinkList;


/**
 * 尾插法增加链表元素
 * @param head
 * @param val
 * @return
 */
void append(LinkList *head, VisitorInfo *val);

void add(LinkList *head, VisitorInfo *val);

/**
 * 按索引获取元素，索引的行为和数组相同
 * @param head
 * @param index
 * @return
 */
LinkList *getByIndex(LinkList *head, size_t index);

/**
 * 创建一个节点
 * @param val
 * @return
 */
LinkList *createNode(VisitorInfo *val);

LinkList *createList();

void removeByIndex(LinkList *head, size_t index);

void toNums(VisitorInfo **nums, LinkList *head);

void printList(LinkList *head);

#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H
