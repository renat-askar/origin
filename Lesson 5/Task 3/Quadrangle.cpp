#include "Quadrangle.h"

#include <iostream>

Quadrangle::Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD, const std::string& name):
	a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, name}{}

Quadrangle::Quadrangle(): Figure{4, "��������������"}{};

Quadrangle::Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD):
	a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, "��������������"}{}

void Quadrangle::print_info() const
{
	std::cout << get_name() << ": \n"
		<< "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n'
		<< "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}
