#pragma once

#include "Quadrangle.h"

class Parallelogram: public Quadrangle
{
	public:
		FIGURE_API Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD);
};
