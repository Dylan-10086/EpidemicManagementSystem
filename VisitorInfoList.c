#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "VisitorInfoList.h"
#include <string.h>

ResidentInfoList * createList() {
    ResidentInfoList *head = (ResidentInfoList *) malloc(sizeof(ResidentInfoList));

    head->data = (VisitorInfo *) malloc(sizeof(VisitorInfo));
    head->data->HealthCode = 0;
    strcat(head->data->name, "个数");
    head->next = NULL;

    return head;
}

ResidentInfoList *createNode(VisitorInfo *val) {
    ResidentInfoList *cur_node = (ResidentInfoList *) malloc(sizeof(ResidentInfoList));
    cur_node->data = val;
    cur_node->next = NULL;

    return cur_node;
}

void add(ResidentInfoList *head, VisitorInfo *val) {
    ResidentInfoList *cur_node = createNode(val);

    cur_node->next = head->next;
    head->next = cur_node;

    head->data->HealthCode++;
}

void append(ResidentInfoList *head, VisitorInfo *val) {
    ResidentInfoList *cur_node = createNode(val);
    ResidentInfoList *p = head;

    while (p->next) {
        p = p->next;
    }
    p->next = cur_node;

    head->data->HealthCode++;
}

ResidentInfoList *fromNums(VisitorInfo val[], size_t len) {
    ResidentInfoList *head = createList();
    ResidentInfoList *p = head;

    for (size_t i = 0; i < len; ++i) {
        ResidentInfoList *cur_node = createNode(&val[i]);
        p->next = cur_node;
        p = p->next;
        head->data++;
    }

    return head;
}

void removeByIndex(ResidentInfoList *head, size_t index) {
    assert(index < head->data->HealthCode);

    ResidentInfoList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    ResidentInfoList *deleteItem = p->next;
    p->next = deleteItem->next;
    free(deleteItem);
}

ResidentInfoList *getByIndex(ResidentInfoList *head, size_t index) {
    assert(index < head->data->HealthCode);

    ResidentInfoList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    return p->next;
}

void toNums(VisitorInfo **nums, ResidentInfoList *head) {
    size_t len = head->data->HealthCode;
    head = head->next;

    for (int i = 0; i < len; i++, head = head->next) {
        nums[i] = head->data;
    }
}

void printList(ResidentInfoList *head) {
    head = head->next;
    while (head) {
        printData(head->data);
        head = head->next;
    }
    printf("\n");
}


