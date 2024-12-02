#pragma once

#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
	public:
		IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB);

		IsoscelesTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
