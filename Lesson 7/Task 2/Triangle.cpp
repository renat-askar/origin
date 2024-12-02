#include "Triangle.h"

#include "BadFigure.h"

#include <iostream>

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string& name) :
	a{ sideA }, b{ sideB }, c{ sideC }, A{ angleA }, B{ angleB }, C{ angleC }, Figure{ 3, name } {}

Triangle::Triangle() : Figure{ 3, "Треугольник" } {}

Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) :
	a{ sideA }, b{ sideB }, c{ sideC }, A{ angleA }, B{ angleB }, C{ angleC }, Figure{ 3, "Треугольник" }
{
	if(angleA + angleB + angleC != 180)
		throw BadFigure{"сумма углов не равна 180"};
	if (get_sides_count() != 3)
		throw BadFigure{"количество сторон не равно 3"};

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ") создан\n";
}

void Triangle::print_info() const
{
	std::cout << get_name() << ": \n"
		<< "Стороны: a=" << a << " b=" << b << " c=" << c << '\n'
		<< "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
}
