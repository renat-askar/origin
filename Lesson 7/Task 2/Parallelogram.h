#pragma once

#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD);

	Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};
