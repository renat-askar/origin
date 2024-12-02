#include "Parallelogram.h"

#include "BadFigure.h"

#include <iostream>

Parallelogram::Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD) :
	Quadrangle{ sidesAC, sidesBD, sidesAC, sidesBD, anglesAC, anglesBD, anglesAC, anglesBD, "��������������" }
{
	std::cout << get_name() << " (������� " << sidesAC << ", " << sidesBD << ", " << sidesAC << ", " << sidesBD
		<< "; ���� " << anglesAC << ", " << anglesBD << ", " << anglesAC << ", " << anglesBD << ") ������\n";
}

Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) :
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "��������������" }
{
	if (sideA != sideC)
		throw BadFigure{ "������� a � c �� �����" };
	if (sideB != sideD)
		throw BadFigure{ "������� b � d �� �����" };
	if (angleA != angleC)
		throw BadFigure{ "���� A � C �� �����" };
	if (angleB != angleD)
		throw BadFigure{ "���� B � D �� �����" };

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") ������\n";
}
