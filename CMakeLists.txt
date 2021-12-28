cmake_minimum_required(VERSION 3.20)
project(EpidemicManagementSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(EpidemicManagementSystem LinkList.c LinkList.h main.c VisitorInfo.h VisitorInfo.c ResidentInfo.h Utils.h Utils.c ResidentInfo.c)
