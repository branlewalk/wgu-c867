cmake_minimum_required(VERSION 3.14)
project(C867___FPP1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867___FPP1
        degree.h
    networkStudent.cpp
    networkStudent.h
    roster.cpp
    roster.h
    securityStudent.cpp
    securityStudent.h
    softwareStudent.cpp
    softwareStudent.h
    student.cpp
    student.h)
