#include "RectangularTriangle.h"

#include "BadFigure.h"

#include <iostream>

RectangularTriangle::RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB):
	Triangle{ sideA, sideB, sideC, angleA, angleB, 90, "������������� �����������" }
{
	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC
		<< "; ���� " << angleA << ", " << angleB << ", " << 90 << ") ������\n";
}

RectangularTriangle::RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "������������� �����������" }
{
	if (angleC != 90)
		throw BadFigure{"���� C �� ����� 90"};

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ") ������\n";
}
