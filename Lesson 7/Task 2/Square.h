#pragma once

#include "Quadrangle.h"

class Square : public Quadrangle
{
public:
	Square(int sides);

	Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};
