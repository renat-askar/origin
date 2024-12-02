#include "IsoscelesTriangle.h"

#include "BadFigure.h"

#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB):
	Triangle{ sidesAC, sideB, sidesAC, anglesAC, angleB, anglesAC, "Равнобедренный треугольник" }
{
	std::cout << get_name() << " (стороны " << sidesAC << ", " << sideB << ", " << sidesAC
		<< "; углы " << anglesAC << ", " << angleB << ", " << anglesAC << ") создан\n";
}

IsoscelesTriangle::IsoscelesTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC):
	Triangle{ sideA, sideB, sideC, angleA, angleB, angleC, "Равнобедренный треугольник" }
{
	if(sideA != sideC)
		throw BadFigure{"стороны a и c не равны"};
	if(angleA != angleC)
		throw BadFigure{"углы A и C не равны"};

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ") создан\n";
}
