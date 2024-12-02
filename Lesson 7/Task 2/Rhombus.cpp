#include "Rhombus.h"

#include "BadFigure.h"

#include <iostream>

Rhombus::Rhombus(int sides, int anglesAC, int anglesBD):
	Quadrangle{ sides, sides, sides, sides, anglesAC, anglesBD, anglesAC, anglesBD, "����"}
{
	std::cout << get_name() << " (������� " << sides << ", " << sides << ", " << sides << ", " << sides
		<< "; ���� " << anglesAC << ", " << anglesBD << ", " << anglesAC << ", " << anglesBD << ") ������\n";
}

Rhombus::Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "����" }
{
	if (sideA != sideB || sideA != sideC || sideA != sideD || sideB != sideC || sideB != sideD || sideC != sideD)
		throw BadFigure{ "������� �� �����" };
	if (angleA != angleC)
		throw BadFigure{ "���� A � C �� �����" };
	if (angleB != angleD)
		throw BadFigure{ "���� B � D �� �����" };

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") ������\n";
}
