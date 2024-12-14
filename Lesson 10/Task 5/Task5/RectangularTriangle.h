#pragma once

#include "Triangle.h"

class RectangularTriangle: public Triangle
{
	public:
		FIGURE_API RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB);
};
