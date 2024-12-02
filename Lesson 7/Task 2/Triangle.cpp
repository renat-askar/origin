#include "Triangle.h"

#include "BadFigure.h"

#include <iostream>

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string& name) :
	a{ sideA }, b{ sideB }, c{ sideC }, A{ angleA }, B{ angleB }, C{ angleC }, Figure{ 3, name } {}

Triangle::Triangle() : Figure{ 3, "�����������" } {}

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) :
	a{ sideA }, b{ sideB }, c{ sideC }, A{ angleA }, B{ angleB }, C{ angleC }, Figure{ 3, "�����������" }
{
	if(angleA + angleB + angleC != 180)
		throw BadFigure{"����� ����� �� ����� 180"};
	if (get_sides_count() != 3)
		throw BadFigure{"���������� ������ �� ����� 3"};

	std::cout << get_name() << " (������� " << sideA << ", " << sideB << ", " << sideC
		<< "; ���� " << angleA << ", " << angleB << ", " << angleC << ") ������\n";
}

void Triangle::print_info() const
{
	std::cout << get_name() << ": \n"
		<< "�������: a=" << a << " b=" << b << " c=" << c << '\n'
		<< "����: A=" << A << " B=" << B << " C=" << C << "\n\n";
}
