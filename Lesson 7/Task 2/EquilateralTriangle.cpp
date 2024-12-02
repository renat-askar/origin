#include "EquilateralTriangle.h"

#include "BadFigure.h"

#include <iostream>

EquilateralTriangle::EquilateralTriangle(int sides) :
	Triangle{sides, sides, sides, 60, 60, 60, "�������������� �����������"}
{
	std::cout << get_name() << " (������� " << sides << ", " << sides << ", " << sides
		<< "; ���� " << 60 << ", " << 60 << ", " << 60 << ") ������\n";
}

EquilateralTriangle::EquilateralTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "�������������� �����������"}
{
	if (sideA != sideB || sideA != sideC || sideB != sideC)
		throw BadFigure{ "������� �� �����" };
	if (angleA != 60 || angleB != 60 || angleC != 60)
		throw BadFigure{ "���� �� ����� 60" };

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ") ������\n";
}
