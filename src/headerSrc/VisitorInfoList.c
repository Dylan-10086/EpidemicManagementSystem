#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/VisitorInfoList.h"
#include <string.h>

VisitorInfoList *createVisitorInfoList() {
    VisitorInfoList *head = (VisitorInfoList *) malloc(sizeof(VisitorInfoList));

    // 头节点中data域中healthCode会储存链表长度
    head->data = (VisitorInfo *) malloc(sizeof(VisitorInfo));
    head->data->healthCode = 0;
    strcat(head->data->name, "个数");
    head->next = NULL;

    return head;
}

VisitorInfoList *createVisitorInfoListNode(VisitorInfo *val) {
    VisitorInfoList *cur_node = (VisitorInfoList *) malloc(sizeof(VisitorInfoList));
    cur_node->data = val;
    cur_node->next = NULL;

    return cur_node;
}

void addVisitorInfo(VisitorInfoList *head, VisitorInfo *val) {
    VisitorInfoList *cur_node = createVisitorInfoListNode(val);

    cur_node->next = head->next;
    head->next = cur_node;

    head->data->healthCode++;
}

void appendVisitorInfo(VisitorInfoList *head, VisitorInfo *val) {
    VisitorInfoList *cur_node = createVisitorInfoListNode(val);
    VisitorInfoList *p = head;

    while (p->next) {
        p = p->next;
    }
    p->next = cur_node;

    head->data->healthCode++;
}

VisitorInfoList *createVisitorInfoListFromNums(VisitorInfo val[], size_t len) {
    VisitorInfoList *head = createVisitorInfoList();
    VisitorInfoList *p = head;

    for (size_t i = 0; i < len; ++i) {
        VisitorInfoList *cur_node = createVisitorInfoListNode(&val[i]);
        p->next = cur_node;
        p = p->next;
        head->data++;
    }

    return head;
}

void removeVisitorInfoByIndex(VisitorInfoList *head, size_t index) {
    assert(index < head->data->healthCode);

    VisitorInfoList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    VisitorInfoList *deleteItem = p->next;
    p->next = deleteItem->next;
    free(deleteItem);
}

VisitorInfoList *getVisitorInfoByIndex(VisitorInfoList *head, size_t index) {
    assert(index < head->data->healthCode);

    VisitorInfoList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    return p->next;
}

void visitorInfoListToNums(VisitorInfo **nums, VisitorInfoList *head) {
    size_t len = head->data->healthCode;
    head = head->next;

    for (int i = 0; i < len; i++, head = head->next) {
        nums[i] = head->data;
    }
}

void printVisitorInfoList(VisitorInfoList *head) {
    head = head->next;
    while (head) {
        printVisitorData(head->data);
        head = head->next;
    }
    printf("\n");
}

void saveVisitorInfoListToFile(const char *fileName, VisitorInfoList *head) {
    FILE *file = fopen(fileName, "a+");

    if (file == NULL) {
        printf("出错了!");
        return;
    }

    head = head->next;

    while (head) {
        saveVisitorInfoToFile(file, head->data);
        head = head->next;
    }
}

void readVisitorInfoListFromFile(const char *fileName, VisitorInfoList *head) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("出错了!");
        return;
    }

    char name[20], phone[20], from[50], remarks[256];
    time_t arrive, leave;
    HealthCode healthCode;

    while (fscanf(file, "%s %s %ld %ld %s %hu %s", name, phone, &arrive, &leave, from, &healthCode, remarks) != EOF) {
        appendVisitorInfo(head,
                          initVisitorInfo(createVisitorInfo(), name, phone, arrive, leave, from, healthCode, remarks));
    }
}

