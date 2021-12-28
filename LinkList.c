#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkList.h"
#include <string.h>

LinkList *createList() {
    LinkList *head = (LinkList *) malloc(sizeof(LinkList));

    head->data = (Data *) malloc(sizeof(Data));
    head->data->HealthCode = 0;
    strcat(head->data->name, "个数");
    head->next = NULL;

    return head;
}

LinkList *createNode(Data *val) {
    LinkList *cur_node = (LinkList *) malloc(sizeof(LinkList));
    cur_node->data = val;
    cur_node->next = NULL;

    return cur_node;
}

void add(LinkList *head, Data *val) {
    LinkList *cur_node = createNode(val);

    cur_node->next = head->next;
    head->next = cur_node;

    head->data->HealthCode++;
}

void append(LinkList *head, Data *val) {
    LinkList *cur_node = createNode(val);
    LinkList *p = head;

    while (p->next) {
        p = p->next;
    }
    p->next = cur_node;

    head->data->HealthCode++;
}

LinkList *fromNums(Data val[], size_t len) {
    LinkList *head = createList();
    LinkList *p = head;

    for (size_t i = 0; i < len; ++i) {
        LinkList *cur_node = createNode(&val[i]);
        p->next = cur_node;
        p = p->next;
        head->data++;
    }

    return head;
}

void removeByIndex(LinkList *head, size_t index) {
    assert(index < head->data->HealthCode);

    LinkList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    LinkList *deleteItem = p->next;
    p->next = deleteItem->next;
    free(deleteItem);
}

LinkList *getByIndex(LinkList *head, size_t index) {
    assert(index < head->data->HealthCode);

    LinkList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    return p->next;
}

void toNums(Data **nums, LinkList *head) {
    size_t len = head->data->HealthCode;
    head = head->next;

    for (int i = 0; i < len; i++, head = head->next) {
        nums[i] = head->data;
    }
}

void printList(LinkList *head) {
    head = head->next;
    while (head) {
        printData(head->data);
        head = head->next;
    }
    printf("\n");
}


