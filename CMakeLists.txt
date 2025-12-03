cmake_minimum_required(VERSION 3.29)
project(TodolistApp)

set(CMAKE_CXX_STANDARD 20)

add_library(file Activity.cpp
        Activity.h
        Todolist.cpp
        Todolist.h)

add_executable(main main.cpp)
target_link_libraries(main file)

add_subdirectory(test)