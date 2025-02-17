cmake_minimum_required(VERSION 3.30)
project(Student_Portal_Login)

set(CMAKE_CXX_STANDARD 26)

add_executable(Student_Portal_Login main.cpp
        cmake-build-debug/mainwindow.h
        mainwindow.cpp
        login.ui
)
