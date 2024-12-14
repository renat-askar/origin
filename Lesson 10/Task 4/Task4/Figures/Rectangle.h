#pragma once

#include "Quadrangle.h"

class Rectangle: public Quadrangle
{
	public:
		FIGURE_API Rectangle(int sidesAC, int sidesBD);
};
