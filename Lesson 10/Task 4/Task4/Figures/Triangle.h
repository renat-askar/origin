#pragma once

#include "Figure.h"

class Triangle: public Figure
{
	int a{}, b{}, c{};
	int A{}, B{}, C{};

	protected:
		Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string& name);

	public:
		FIGURE_API Triangle();

		FIGURE_API Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);

		FIGURE_API void print_info() const override;
};
