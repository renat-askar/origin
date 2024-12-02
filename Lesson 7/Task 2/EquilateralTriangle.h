#pragma once

#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int sides);

	EquilateralTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
