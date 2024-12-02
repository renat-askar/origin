#include "Square.h"

#include "BadFigure.h"

#include <iostream>

Square::Square(int sides):
	Quadrangle{sides, sides, sides, sides, 90, 90, 90, 90, " вадрат"}
{
	std::cout << get_name() << " (стороны " << sides << ", " << sides << ", " << sides << ", " << sides
		<< "; углы " << 90 << ", " << 90 << ", " << 90 << ", " << 90 << ") создан\n";
}

Square::Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, " вадрат"}
{
	if (sideA != sideB || sideA != sideC || sideA != sideD || sideB != sideC || sideB != sideD || sideC != sideD)
		throw BadFigure{"стороны не равны"};
	if (angleA != 90 || angleB != 90 || angleC != 90 || angleD != 90)
		throw BadFigure{"углы не равны 90"};

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") создан\n";
}
