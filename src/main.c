#include "SystemBody.h"

int choose;
char test_username[] = "windbell";
char test_password[] = "123456";
VisitorInfoList *list;
ResidentInfoList *residentInfoList;

void Login() {
    int success = FALSE, index = 0;

    while (!success) {
        success = TRUE;
        char user_name[20];
        char user_password[20];
        char temp;
        system("cls");
        PrintLogin();
        goto_xy(32, 5);
        index = 0;
        while ((temp = getchar()) != '\n') {
            user_name[index++] = temp;
        }
        for (size_t i = 0, flag = 1; test_username[i] != '\0'; i++) {
            if (user_name[i] != test_username[i])
                success = FALSE;
        }
        goto_xy(30, 7);
        index = 0;
        while ((temp = getch()) != 13) {
            putchar('*');
            user_password[index++] = temp;
        }
        for (size_t i = 0, flag = 1; test_password[i] != '\0'; i++) {
            if (user_password[i] != test_password[i])
                success = FALSE;
        }
        if (!success) {
            goto_xy(20, 11);
            printf("用户名或密码错误\n\n");
            system("pause");
        }
    }
    system("cls");
    goto_xy(30, 7);
    printf("管理员 : %s , 欢迎回来...\n", test_username);
    system("pause");
}

void MainProcess() {
    list = createVisitorInfoList();
    residentInfoList = createResidentInfoList();
    readVisitorInfoListFromFile("visitorData.txt", list);
    readResidentInfoListFromFile("residentData.txt", residentInfoList);

    int a;

    l:
    while (1) {
        int n;
        int flag = FALSE;
        system("cls");
        PrintMenu();
        scanf("%d", &n);
        switch (n) {
            case 1: //公告
            {
                system("cls");
                Notice();
                goto l;
            }
                break;
            case 2: {
                system("cls");
                SearchInformation();
                while (1) {
                    scanf("%d", &a);
                    switch (a) {
                        case 1: {
                            SearchResident();
                        }
                            goto l;
                            break;
                            break;
                        case 2: {
                            SearchVisitor();
                        }
                            goto l;
                            break;
                        case 0:
                            goto l;
                            break;
                        default:
                            break;
                    }
                }
            }
                break;
            case 3: {
                system("cls");
                SearchInformation();
                scanf("%d", &a);
                switch (a) {
                    case 1: {
                        DeleteResident();
                    }
                        goto l;
                        break;
                        break;
                    case 2: {
                        DeletVisitor();
                    }
                        goto l;
                        break;
                    case 0:
                        goto l;
                        break;
                    default:
                        break;
                }
            }
            case 4: {
                system("cls");
                SearchInformation();
                scanf("%d", &a);
                switch (a) {
                    case 1: {
                        AddResident();
                    }
                        goto l;
                        break;
                        break;
                    case 2: {
                        AddVisitor();
                    }
                        goto l;
                        break;
                    case 0:
                        goto l;
                        break;
                    default:
                        break;
                }
            }
                goto l;
                break;
            case 5: {

            }
                goto l;
                break;
            case 6: {
                Event();
                system("pause");
            }
                goto l;
                break;
            case 7:
                printf("thanks!\n");
                exit(1);
        }

        if (flag)
            break;
    }
}

void goto_xy(int x, int y)//定位光标位置到指定坐标
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

void PrintLogin() {
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                   用户登录                    \n\n");
    printf("\t                用户名:                       \n\n");
    printf("\t                密码:                       \n\n");
    printf("    ----------------------------------------------------------\n");
}

void PrintMenu() {
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                1:发布公告                       \n\n");
    printf("\t                2:查找人员信息                       \n\n");
    printf("\t                3:删除人员信息                       \n\n");
    printf("\t                4:添加人员信息                       \n\n");
    printf("\t                5:查询统计信息                       \n\n");
    printf("\t                6:突发事件记录                           \n\n");
    printf("\t                7:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(1~7):");
}

void Event() {
    char temp;
    printf("是否要阅读(y/n)\n");
    getchar();
    temp = getchar();
    if (temp == 'y') {
        FILE *fr = fopen("logevent.txt", "rt+");
        while ((temp = fgetc(fr)) != EOF) {
            putchar(temp);
        }
        fclose(fr);
    }
    printf("\n是否要写入(y/n)\n");
    getchar();
    temp = getchar();
    if (temp == 'y') {
        FILE *fw = fopen("logevent.txt", "wt+");
        printf("\n             请输入内容:\n");
        while ((temp = getchar()) != EOF) {
            fputc(temp, fw);
        }
        printf("修改完成\n");
        fclose(fw);
    }
}

void Notice() {
    printf("             当前公告\n");
    FILE *fr = fopen("notice.txt", "rt+");
    if (fr != NULL) {
        printf("Open the file successful.\n");
    } else {
        printf("Open the file fault!\n");
        exit(1); //退出程序
    }
    char temp;
    while ((temp = fgetc(fr)) != EOF) {
        putchar(temp);
    }
    printf("\n             是否需要修改(y/n):");
    getchar();
    scanf("%c", &temp);
    if (temp == 'y') {
        printf("\n             请输入修改内容:\n");
        fclose(fr);
        FILE *fw = fopen("notice.txt", "wt+");
        while ((temp = getchar()) != EOF) {
            fputc(temp, fw);
        }
        printf("修改完成\n");
        fclose(fw);
    }

    system("pause");
}

void SearchInformation() {
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                请选择操作对象                       \n\n");
    printf("\t                1:居民                       \n\n");
    printf("\t                2:访客                       \n\n");
    printf("\t                0:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(0~2):");
}

void SearchREIInformation() {
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                请选择查询信息                       \n\n");
    printf("\t                1:查找姓名                       \n\n");
    printf("\t                2:查找电话号码                       \n\n");
    printf("\t                3:查找住宅楼                       \n\n");
    printf("\t                4:查找隔离情况                       \n\n");
    printf("\t                0:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(0~4):");
}

void SearchVISInformation() {
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                请选择查询信息                       \n\n");
    printf("\t                1:查找姓名                       \n\n");
    printf("\t                2:查找来访时间                       \n\n");
    printf("\t                3:查找离开时间                       \n\n");
    printf("\t                4:查找健康码                       \n\n");
    printf("\t                0:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(0~4):");
}

void SearchResident() {
    system("cls");
    SearchREIInformation();
    scanf("%d", &choose);
    switch (choose) {
        case 1: {
            char name[20];
            printf("请输入姓名:");
            scanf("%s", name);
            ResidentInfoList *temp = createResidentInfoList();
            temp = residentListSearchByName(residentInfoList, name);
            printResidentList(temp);
            system("pause");
        }
            break;
        case 2: {
            char name[20];
            printf("请输入电话号码:");
            scanf("%s", name);
            ResidentInfoList *temp = createResidentInfoList();
            temp = residentListSearchByPhone(residentInfoList, name);
            printResidentList(temp);
            system("pause");
        }
            break;
        case 3: {
            int name;
            printf("请输入住宅楼:");
            scanf("%d", &name);
            ResidentInfoList *temp = createResidentInfoList();
            temp = residentListSearchByBuildingNum(residentInfoList, name);
            printResidentList(temp);
            system("pause");
        }
            break;
        case 4: {
            int name;
            printf("请输入隔离情况(1==隔离):");
            scanf("%d", &name);
            ResidentInfoList *temp = createResidentInfoList();
            temp = residentListSearchByIsolation(residentInfoList, name);
            printResidentList(temp);
            system("pause");
        }
            break;
        case 0:
        default:
            break;
    }
}

void SearchVisitor() {
    system("cls");
    SearchVISInformation();
    scanf("%d", &choose);
    switch (choose) {
        case 1: {
            char name[20];
            printf("请输入姓名:");
            scanf("%s", name);
            VisitorInfoList *temp = createVisitorInfoList();
            temp = visitorListSearchByName(list, name);
            printVisitorInfoList(temp);
            system("pause");
        }
            break;
        case 2: {
            int year, mon, day, hour, min;
            printf("请输入来访时间(int year, int mon, int day, int hour, int min):");
            scanf("%d %d %d %d %d", &year, &mon, &day, &hour, &min);
            Time *name = createTime(year, mon, day, hour, min);
            VisitorInfoList *temp = createVisitorInfoList();
            temp = visitorListSearchByArrive(list, name);
            printVisitorInfoList(temp);
            system("pause");
        }
            break;
        case 3: {
            int year, mon, day, hour, min;
            printf("请输入离开时间(int year, int mon, int day, int hour, int min):");
            scanf("%d %d %d %d %d", &year, &mon, &day, &hour, &min);
            Time *name = createTime(year, mon, day, hour, min);
            VisitorInfoList *temp = createVisitorInfoList();
            temp = visitorListSearchByLeave(list, name);
            printVisitorInfoList(temp);
            system("pause");
        }
            break;
        case 4: {
            unsigned short name = 0;
            printf("请输入健康码:");
            scanf("%d", &name);
            VisitorInfoList *temp = createVisitorInfoList();
            temp = visitorListSearchByHealthCode(list, name);
            printVisitorInfoList(temp);
            system("pause");
        }
            break;
        case 0:
        default:
            break;
    }
}

void DeleteResident() {
    system("cls");
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                请选择排序信息                       \n\n");
    printf("\t                1:姓名                       \n\n");
    printf("\t                2:地址                       \n\n");
    printf("\t                3:健康码                       \n\n");
    printf("\t                4:隔离情况                       \n\n");
    printf("\t                0:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(0~4):");
    scanf("%d", &choose);
    switch (choose) {
        case 1: {
            printf("排序如下:\n");
            residentListSortByName(residentInfoList, residentInfoList->data->healthCode);
            printResidentList(residentInfoList);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeResidentInfoByIndex(residentInfoList, num);
            system("pause");
        }
            break;
        case 2: {
            printf("排序如下:\n");
            residentListSortByAddress(residentInfoList, residentInfoList->data->healthCode);
            printResidentList(residentInfoList);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeResidentInfoByIndex(residentInfoList, num);
            system("pause");
        }
            break;
        case 3: {
            printf("排序如下:\n");
            residentListSortByIsolation(residentInfoList, residentInfoList->data->healthCode);
            printResidentList(residentInfoList);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeResidentInfoByIndex(residentInfoList, num);
            system("pause");
        }
            break;
        case 4: {
            printf("排序如下:\n");
            residentListSortByHealthCode(residentInfoList, residentInfoList->data->healthCode);
            printResidentList(residentInfoList);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeResidentInfoByIndex(residentInfoList, num);
            system("pause");
        }
            break;
        case 0:
        default:
            break;
    }
}

void DeletVisitor() {
    system("cls");
    printf("\n");
    printf("\t                 疫情时期社区管理系统\n");
    printf("   ---------------------------------------------------------\n");
    printf("\t                请选择排序信息                       \n\n");
    printf("\t                1:姓名                       \n\n");
    printf("\t                2:到达时间                       \n\n");
    printf("\t                3:离开时间                       \n\n");
    printf("\t                4:健康码                       \n\n");
    printf("\t                0:退出\n\n");
    printf("    ----------------------------------------------------------\n");
    printf("\t选择要进行的操作序号(0~4):");
    scanf("%d", &choose);
    switch (choose) {
        case 1: {
            printf("排序如下:\n");
            visitorListSortByName(list, list->data->healthCode);
            printVisitorInfoList(list);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeVisitorInfoByIndex(list, num);
            system("pause");
        }
            break;
        case 2: {
            printf("排序如下:\n");
            visitorListSortByArriveTime(list, list->data->healthCode);
            printVisitorInfoList(list);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeVisitorInfoByIndex(list, num);
            system("pause");
        }
            break;
        case 3: {
            printf("排序如下:\n");
            visitorListSortByLeaveTime(list, list->data->healthCode);
            printVisitorInfoList(list);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeVisitorInfoByIndex(list, num);
            system("pause");
        }
            break;
        case 4: {
            printf("排序如下:\n");
            visitorListSortByHealthCode(list, list->data->healthCode);
            printVisitorInfoList(list);
            printf("请选择删除编号(0 = 取消):\n");
            int num;
            scanf("%d", &num);
            if (num == 0)
                break;
            else
                removeVisitorInfoByIndex(list, num);
            system("pause");
        }
            break;
        case 0:
        default:
            break;
    }
}

void AddResident() {
    ResidentInfo *temp = createResidentInfo();
    addResidentInfo(residentInfoList, getResidentInfo(temp));
}

void AddVisitor() {
    VisitorInfo *temp = createVisitorInfo();
    addVisitorInfo(list, getVisitorInfo(temp));
}