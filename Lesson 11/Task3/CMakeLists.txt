cmake_minimum_required(VERSION 3.20)

project(homework2)

find_package(Catch2 3 REQUIRED)

add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
