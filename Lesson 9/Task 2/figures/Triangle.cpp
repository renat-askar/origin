#include "Triangle.h"

#include <iostream>

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string& name):
	a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, name}{}

Triangle::Triangle(): Figure{3, "�����������"}{}

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, "�����������"}{}

void Triangle::print_info() const
{
	std::cout << get_name() << ": \n"
		<< "�������: a=" << a << " b=" << b << " c=" << c << '\n'
		<< "����: A=" << A << " B=" << B << " C=" << C << "\n\n";
}
