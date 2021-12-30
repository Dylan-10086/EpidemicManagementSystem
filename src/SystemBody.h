#pragma once
#ifndef _SYSTEM_BODY_H_
#define _SYSTEM_BODY_H_

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <time.h>
#include"SystemBody.h"
#include "./headers/ResidentInfo.h"
#include "./headers/ResidentInfoList.h"
#include "./headers/Utils.h"
#include "./headers/VisitorInfo.h"
#include "./headers/VisitorInfoList.h"

#define TRUE 1
#define FALSE 0


void Login();

void MainProcess();

void Notice();

void Event();

void PrintMenu();

void PrintLogin();

void goto_xy(int x, int y);//��λ���λ�õ�ָ������
void SearchInformation();

void SearchResident();

void SearchVisitor();

void DeleteResident();

void DeletVisitor();

void AddResident();

void AddVisitor();

#endif !_SYSTEM_BODY_H_
