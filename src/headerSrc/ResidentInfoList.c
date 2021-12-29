#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../headers/ResidentInfo.h"
#include "../headers/ResidentInfoList.h"


ResidentInfoList *createResidentInfoList() {
    ResidentInfoList *head = (ResidentInfoList *) malloc(sizeof(ResidentInfoList));

    head->data = (ResidentInfo *) malloc(sizeof(ResidentInfo));
    head->data->healthCode = 0;
    strcat(head->data->name, "个数");
    head->next = NULL;

    return head;
}

ResidentInfoList *createResidentInfoListNode(ResidentInfo *val) {
    ResidentInfoList *cur_node = (ResidentInfoList *) malloc(sizeof(ResidentInfoList));
    cur_node->data = val;
    cur_node->next = NULL;

    return cur_node;
}

/**
 * 头插法
 * @param head
 * @param val
 */
void addResidentInfo(ResidentInfoList *head, ResidentInfo *val) {
    ResidentInfoList *cur_node = createResidentInfoListNode(val);

    cur_node->next = head->next;
    head->next = cur_node;

    head->data->healthCode++;
}

/**
 * 尾插法
 * @param head
 * @param val
 */
void appendResidentInfo(ResidentInfoList *head, ResidentInfo *val) {
    ResidentInfoList *cur_node = createResidentInfoListNode(val);
    ResidentInfoList *p = head;

    while (p->next) {
        p = p->next;
    }
    p->next = cur_node;

    head->data->healthCode++;
}

ResidentInfoList *fromNums(ResidentInfo val[], size_t len) {
    ResidentInfoList *head = createResidentInfoList();
    ResidentInfoList *p = head;

    for (size_t i = 0; i < len; ++i) {
        ResidentInfoList *cur_node = createResidentInfoListNode(&val[i]);
        p->next = cur_node;
        p = p->next;
        head->data++;
    }

    return head;
}

void removeResidentInfoByIndex(ResidentInfoList *head, size_t index) {
    assert(index < head->data->healthCode);

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

ResidentInfoList *getResidentInfoByIndex(ResidentInfoList *head, size_t index) {
    assert(index < head->data->healthCode);

    ResidentInfoList *p = head;

    size_t cnt = 0;

    while (cnt < index) {
        p = p->next;
        cnt++;
    }

    return p->next;
}

void residentInfoListToNums(ResidentInfo **nums, ResidentInfoList *head) {
    size_t len = head->data->healthCode;
    head = head->next;

    for (int i = 0; i < len; i++, head = head->next) {
        nums[i] = head->data;
    }
}

void printResidentList(ResidentInfoList *head) {
    head = head->next;
    while (head) {
        printResidentData(head->data);
        head = head->next;
    }
    printf("\n");
}

void saveResidentInfoListToFile(const char *fileName, ResidentInfoList *head) {
    FILE *file = fopen(fileName, "a+");

    if (file == NULL) {
        printf("出错了!");
        return;
    }

    head = head->next;

    while (head) {
        saveResidentInfoToFile(file, head->data);
        head = head->next;
    }
}

void readResidentInfoListFromFile(const char *fileName, ResidentInfoList *head) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("出错了!");
        return;
    }

    char name[20], phoneNum[20];
    int buildingNum, houseNum;
    HealthCode healthCode;
    bool isolation;

    while (fscanf(file, "%s %s %d %d %hu %d", name, phoneNum, &buildingNum, &houseNum, &healthCode, &isolation) !=
           EOF) {
        appendResidentInfo(
                head,
                initResidentInfo(
                        createResidentInfo(),
                        name,
                        phoneNum,
                        buildingNum,
                        houseNum,
                        healthCode,
                        isolation
                ));
    }


}


