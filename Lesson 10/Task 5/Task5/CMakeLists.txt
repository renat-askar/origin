cmake_minimum_required(VERSION 3.22)

project(Task5)

add_library(Figures SHARED Figure.cpp Triangle.cpp Quadrangle.cpp
EquilateralTriangle.cpp IsoscelesTriangle.cpp RectangularTriangle.cpp
Rectangle.cpp Square.cpp Parallelogram.cpp Rhombus.cpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(Task5 Task5.cpp)

target_link_libraries(Task5 Figures)
