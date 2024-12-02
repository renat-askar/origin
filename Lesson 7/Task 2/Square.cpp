#include "Square.h"

#include "BadFigure.h"

#include <iostream>

Square::Square(int sides):
	Quadrangle{sides, sides, sides, sides, 90, 90, 90, 90, "�������"}
{
	std::cout << get_name() << " (������� " << sides << ", " << sides << ", " << sides << ", " << sides
		<< "; ���� " << 90 << ", " << 90 << ", " << 90 << ", " << 90 << ") ������\n";
}

Square::Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "�������"}
{
	if (sideA != sideB || sideA != sideC || sideA != sideD || sideB != sideC || sideB != sideD || sideC != sideD)
		throw BadFigure{"������� �� �����"};
	if (angleA != 90 || angleB != 90 || angleC != 90 || angleD != 90)
		throw BadFigure{"���� �� ����� 90"};

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") ������\n";
}
