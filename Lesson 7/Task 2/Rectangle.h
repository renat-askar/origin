#pragma once

#include "Quadrangle.h"

class Rectangle : public Quadrangle
{
public:
	Rectangle(int sidesAC, int sidesBD);

	Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};
