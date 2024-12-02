#include "EquilateralTriangle.h"

#include "BadFigure.h"

#include <iostream>

EquilateralTriangle::EquilateralTriangle(int sides) :
	Triangle{sides, sides, sides, 60, 60, 60, "Равносторонний треугольник"}
{
	std::cout << get_name() << " (стороны " << sides << ", " << sides << ", " << sides
		<< "; углы " << 60 << ", " << 60 << ", " << 60 << ") создан\n";
}

EquilateralTriangle::EquilateralTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "Равносторонний треугольник"}
{
	if (sideA != sideB || sideA != sideC || sideB != sideC)
		throw BadFigure{ "стороны не равны" };
	if (angleA != 60 || angleB != 60 || angleC != 60)
		throw BadFigure{ "углы не равны 60" };

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ") создан\n";
}
