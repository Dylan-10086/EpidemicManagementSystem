#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../headers/ResidentInfo.h"
#include "../headers/ResidentInfoList.h"


ResidentInfoList *createResidentInfoList() {
    ResidentInfoList *head = (ResidentInfoList *) malloc(sizeof(ResidentInfoList));

    // 头节点中data域中healthCode会储存链表长度
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

bool rEqual(ResidentInfo *info1, ResidentInfo *info2) {
    if (strcmp(info1->name, info2->name) != 0) {
        return false;
    }
    if (strcmp(info1->phoneNum, info2->phoneNum) != 0) {
        return false;
    }
    if (info1->buildingNum != info2->buildingNum) {
        return false;
    }
    if (info1->houseNum != info2->houseNum) {
        return false;
    }
    if (info1->healthCode != info2->healthCode) {
        return false;
    }
    if (info1->isolation != info2->isolation) {
        return false;
    }
    return true;
}

bool removeResidentInfo(ResidentInfoList *head, ResidentInfo *info) {

    while (head != NULL && !rEqual(head->next->data, info)) {
        head = head->next;
    }

    if (head) {
        head->next = head->next->next;
        return true;
    } else {
        return false;
    }
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
    if (head == NULL) {
        printf("无数据");
    } else {
        head = head->next;
        while (head) {
            printResidentData(head->data);
            head = head->next;
        }
        printf("\n");
    }
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
    int isolation;

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

void R_sort(ResidentInfo **nums, size_t len, int (*compare)(const void *, const void *)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (compare(nums[i], nums[j]) > 0) {
                ResidentInfo *temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int compareByResidentName(const void *item1, const void *item2) {
    return strcmp(((ResidentInfo *) item1)->name, ((ResidentInfo *) item2)->name);
}

int compareByResidentHealthCode(const void *item1, const void *item2) {
    return ((ResidentInfo *) item1)->healthCode - ((ResidentInfo *) item2)->healthCode;
}

int compareByResidentAddress(const void *item1, const void *item2) {
    int bNum1, bNum2, hNum1, hNum2;

    bNum1 = ((ResidentInfo *) item1)->buildingNum;
    bNum2 = ((ResidentInfo *) item2)->buildingNum;
    hNum1 = ((ResidentInfo *) item1)->houseNum;
    hNum2 = ((ResidentInfo *) item2)->houseNum;

    return bNum1 * 10000 + hNum1 - bNum2 * 10000 - hNum2;
}

int compareByResidentIsolation(const void *item1, const void *item2) {
    return ((ResidentInfo *) item1)->isolation - ((ResidentInfo *) item2)->isolation;
}

void residentListSortByName(ResidentInfo **resNums, size_t len) {
    R_sort(resNums, len, compareByResidentName);
}

void residentListSortByHealthCode(ResidentInfo **resNums, size_t len) {
    R_sort(resNums, len, compareByResidentHealthCode);
}

void residentListSortByAddress(ResidentInfo **resNums, size_t len) {
    R_sort(resNums, len, compareByResidentAddress);
}

void residentListSortByIsolation(ResidentInfo **resNums, size_t len) {
    R_sort(resNums, len, compareByResidentIsolation);
}

ResidentInfoList *residentListSearchByName(ResidentInfoList *head, const char *name) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (strcmp(head->data->name, name) == 0) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}

ResidentInfoList *residentListSearchByPhone(ResidentInfoList *head, const char *phone) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (strcmp(head->data->phoneNum, phone) == 0) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}

ResidentInfoList *residentListSearchByHealthCode(ResidentInfoList *head, HealthCode healthCode) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (head->data->healthCode == healthCode) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}

ResidentInfoList *residentListSearchByBuildingNum(ResidentInfoList *head, int bNum) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (head->data->buildingNum == bNum) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}

ResidentInfoList *residentListSearchByHouseNum(ResidentInfoList *head, int hNum) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (head->data->houseNum == hNum) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}

ResidentInfoList *residentListSearchByIsolation(ResidentInfoList *head, int isolation) {
    ResidentInfoList *res = createResidentInfoList();
    bool flag = false;

    head = head->next;
    while (head) {
        if (head->data->isolation == isolation) {
            flag = true;
            appendResidentInfo(res, head->data);
        }
        head = head->next;
    }

    if (flag) {
        return res;
    } else {
        return NULL;
    }
}