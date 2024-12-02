#include "Rhombus.h"

#include "BadFigure.h"

#include <iostream>

Rhombus::Rhombus(int sides, int anglesAC, int anglesBD):
	Quadrangle{ sides, sides, sides, sides, anglesAC, anglesBD, anglesAC, anglesBD, "Ромб"}
{
	std::cout << get_name() << " (стороны " << sides << ", " << sides << ", " << sides << ", " << sides
		<< "; углы " << anglesAC << ", " << anglesBD << ", " << anglesAC << ", " << anglesBD << ") создан\n";
}

Rhombus::Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "Ромб" }
{
	if (sideA != sideB || sideA != sideC || sideA != sideD || sideB != sideC || sideB != sideD || sideC != sideD)
		throw BadFigure{ "стороны не равны" };
	if (angleA != angleC)
		throw BadFigure{ "углы A и C не равны" };
	if (angleB != angleD)
		throw BadFigure{ "углы B и D не равны" };

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") создан\n";
}
