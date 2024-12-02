#include "RectangularTriangle.h"

#include "BadFigure.h"

#include <iostream>

RectangularTriangle::RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB):
	Triangle{ sideA, sideB, sideC, angleA, angleB, 90, "Прямоугольный треугольник" }
{
	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC
		<< "; углы " << angleA << ", " << angleB << ", " << 90 << ") создан\n";
}

RectangularTriangle::RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "Прямоугольный треугольник" }
{
	if (angleC != 90)
		throw BadFigure{"угол C не равен 90"};

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ") создан\n";
}
