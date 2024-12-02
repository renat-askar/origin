#include "Rectangle.h"

#include "BadFigure.h"

#include <iostream>

Rectangle::Rectangle(int sidesAC, int sidesBD) :
	Quadrangle{ sidesAC, sidesBD, sidesAC, sidesBD, 90, 90, 90, 90, "�������������" }
{
	std::cout << get_name() << " (������� " << sidesAC << ", " << sidesBD << ", " << sidesAC << ", " << sidesBD
		<< "; ���� " << 90 << ", " << 90 << ", " << 90 << ", " << 90 << ") ������\n";
}

Rectangle::Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "�������������" }
{
	if (sideA != sideC)
		throw BadFigure{ "������� a � c �� �����" };
	if (sideB != sideD)
		throw BadFigure{ "������� b � d �� �����" };
	if (angleA != 90 || angleB != 90 || angleC != 90 || angleD != 90)
		throw BadFigure{ "���� �� ����� 90" };

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") ������\n";
}
