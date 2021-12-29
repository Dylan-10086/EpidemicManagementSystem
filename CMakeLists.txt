cmake_minimum_required(VERSION 3.14)
project(EpidemicManagementSystem C)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        EpidemicManagementSystem
        src/headerSrc/VisitorInfoList.c
        src/headers/VisitorInfoList.h
        src/main.c
        src/headers/VisitorInfo.h
        src/headerSrc/VisitorInfo.c
        src/headers/ResidentInfo.h
        src/headers/Utils.h
        src/headerSrc/Utils.c
        src/headerSrc/ResidentInfo.c
        src/headers/ResidentInfoList.h
        src/headerSrc/ResidentInfoList.c
)
