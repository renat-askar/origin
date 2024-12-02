#include "IsoscelesTriangle.h"

#include "BadFigure.h"

#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB):
	Triangle{ sidesAC, sideB, sidesAC, anglesAC, angleB, anglesAC, "�������������� �����������" }
{
	std::cout << get_name() << " (������� " << sidesAC << ", " << sideB << ", " << sidesAC
		<< "; ���� " << anglesAC << ", " << angleB << ", " << anglesAC << ") ������\n";
}

IsoscelesTriangle::IsoscelesTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "�������������� �����������" }
{
	if(sideA != sideC)
		throw BadFigure{"������� a � c �� �����"};
	if(angleA != angleC)
		throw BadFigure{"���� A � C �� �����"};

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ") ������\n";
}
