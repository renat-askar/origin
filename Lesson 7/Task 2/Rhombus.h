#pragma once

#include "Quadrangle.h"

class Rhombus : public Quadrangle
{
public:
	Rhombus(int sides, int anglesAC, int anglesBD);

	Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};
