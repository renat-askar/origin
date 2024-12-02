#include "Rectangle.h"

#include "BadFigure.h"

#include <iostream>

Rectangle::Rectangle(int sidesAC, int sidesBD) :
	Quadrangle{ sidesAC, sidesBD, sidesAC, sidesBD, 90, 90, 90, 90, "Прямоугольник" }
{
	std::cout << get_name() << " (стороны " << sidesAC << ", " << sidesBD << ", " << sidesAC << ", " << sidesBD
		<< "; углы " << 90 << ", " << 90 << ", " << 90 << ", " << 90 << ") создан\n";
}

Rectangle::Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "Прямоугольник" }
{
	if (sideA != sideC)
		throw BadFigure{ "стороны a и c не равны" };
	if (sideB != sideD)
		throw BadFigure{ "стороны b и d не равны" };
	if (angleA != 90 || angleB != 90 || angleC != 90 || angleD != 90)
		throw BadFigure{ "углы не равны 90" };

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") создан\n";
}
