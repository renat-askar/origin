cmake_minimum_required(VERSION 3.22.2)

project(figures)

add_executable(figures Task3.cpp Figure.cpp Triangle.cpp Quadrangle.cpp
	RectangularTriangle.cpp IsoscelesTriangle.cpp EquilateralTriangle.cpp
	Rectangle.cpp Square.cpp Parallelogram.cpp Rhombus.cpp)
