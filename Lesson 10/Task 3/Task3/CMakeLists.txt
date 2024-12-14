cmake_minimum_required(VERSION 3.22)

project(Task3)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Leaver SHARED Leaver.h Leaver.cpp)

add_executable(Task3 main.cpp)

target_link_libraries(Task3 Leaver)
