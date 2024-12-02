#include "Parallelogram.h"

#include "BadFigure.h"

#include <iostream>

Parallelogram::Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD) :
	Quadrangle{ sidesAC, sidesBD, sidesAC, sidesBD, anglesAC, anglesBD, anglesAC, anglesBD, "Параллелограмм" }
{
	std::cout << get_name() << " (стороны " << sidesAC << ", " << sidesBD << ", " << sidesAC << ", " << sidesBD
		<< "; углы " << anglesAC << ", " << anglesBD << ", " << anglesAC << ", " << anglesBD << ") создан\n";
}

Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) :
	Quadrangle{ sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD, "Параллелограмм" }
{
	if (sideA != sideC)
		throw BadFigure{ "стороны a и c не равны" };
	if (sideB != sideD)
		throw BadFigure{ "стороны b и d не равны" };
	if (angleA != angleC)
		throw BadFigure{ "углы A и C не равны" };
	if (angleB != angleD)
		throw BadFigure{ "углы B и D не равны" };

	std::cout << get_name() << " (стороны " << sideA << ", " << sideB << ", " << sideC << ", " << sideD
		<< "; углы " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ") создан\n";
}
