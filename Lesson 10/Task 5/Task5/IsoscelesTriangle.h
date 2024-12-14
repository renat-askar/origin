#pragma once

#include "Triangle.h"

class IsoscelesTriangle: public Triangle
{
	public:
		FIGURE_API IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB);
};
