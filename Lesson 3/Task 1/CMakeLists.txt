cmake_minimum_required(VERSION 3.5)

project(Task1 LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME} Task1.cpp)

target_link_libraries(Task1 PRIVATE Catch2::Catch2WithMain)
