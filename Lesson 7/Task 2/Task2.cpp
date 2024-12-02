#include <iostream>

#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "RectangularTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

#include "BadFigure.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		RectangularTriangle rectangularTriangle{3, 4, 5, 30, 60};
		Triangle triangle{3, 4, 5, 0, 0, 0};

		Triangle triangle2{ 10, 20, 30, 50, 60, 70 };

		RectangularTriangle rectangularTriangle2{ 10, 20, 30, 50, 60 };
		IsoscelesTriangle isoscelesTriangle{ 10, 20, 50, 60 };
		EquilateralTriangle equilateralTriangle{ 30 };

		Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };

		Rectangle rectangle{ 10, 20 };
		Square square{ 20 };
		Parallelogram parallelogram{ 20, 30, 30, 40 };
		Rhombus rhombus{ 30, 30, 40 };
	}
	catch (const BadFigure& badFigure)
	{
		std::cout << badFigure.what() << " Причина: " << badFigure.getError() << '\n';
	}

	return 0;
}
