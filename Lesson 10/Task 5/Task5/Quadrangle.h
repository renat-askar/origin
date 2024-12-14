#pragma once

#include "Figure.h"

class Quadrangle: public Figure
{
	int a{}, b{}, c{}, d{};
	int A{}, B{}, C{}, D{};

	protected:
		Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD, const std::string& name);

	public:
		FIGURE_API Quadrangle();

		FIGURE_API Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);

		FIGURE_API void print_info() const override;
};
