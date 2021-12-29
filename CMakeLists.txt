cmake_minimum_required(VERSION 3.20)
project(EpidemicManagementSystem C)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        EpidemicManagementSystem
        VisitorInfoList.c
        VisitorInfoList.h
        main.c
        VisitorInfo.h
        VisitorInfo.c
        ResidentInfo.h
        Utils.h
        Utils.c
        ResidentInfo.c
        ResidentInfoList.h
        ResidentInfoList.c
)
