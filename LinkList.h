#ifndef LINKLIST_LINKLIST_H

#include <stdlib.h>
#include "Data.h"
#include <stdbool.h>


typedef struct List {
    Data *data;
    struct List *next;
} LinkList;


/**
 * 尾插法增加链表元素
 * @param head
 * @param val
 * @return
 */
void append(LinkList *head, Data *val);

void add(LinkList *head, Data *val);

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
LinkList *createNode(Data *val);

LinkList *createList();

void removeByIndex(LinkList *head, size_t index);

void toNums(Data **nums, LinkList *head);

void printList(LinkList *head);

#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H
