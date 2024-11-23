#include <iostream>

class Figure
{
	int sides_count{};
	std::string name{};

protected:
	Figure(int sides, const std::string &get_name) : sides_count{sides}, name{get_name} {};

public:
	Figure() : name{"Фигура"} {};

	int get_sides_count() const { return sides_count; }
	const std::string &get_name() const { return name; }

	virtual void print_info() const { std::cout << name << "\n\n"; }
};

class Triangle : public Figure
{
	int a{}, b{}, c{};
	int A{}, B{}, C{};

protected:
	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string &name) : a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, name} {}

public:
	Triangle() : Figure{3, "Треугольник"} {}

	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, "Треугольник"} {}

	void print_info() const override
	{
		std::cout << get_name() << ": \n"
				  << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n'
				  << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
	}
};

class Quadrangle : public Figure
{
	int a{}, b{}, c{}, d{};
	int A{}, B{}, C{}, D{};

protected:
	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD, const std::string &name) : a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, name} {}

public:
	Quadrangle() : Figure{4, "Четырёхугольник"} {};

	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, "Четырёхугольник"} {}

	void print_info() const override
	{
		std::cout << get_name() << ": \n"
				  << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n'
				  << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
	}
};

class RectangularTriangle : public Triangle
{
public:
	RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle{sideA, sideB, sideC, angleA, angleB, 90, "Прямоугольный треугольник"} {}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB) : Triangle{sidesAC, sideB, sidesAC, anglesAC, angleB, anglesAC, "Равнобедренный треугольник"} {}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int sides) : Triangle{sides, sides, sides, 60, 60, 60, "Равносторонний треугольник"} {}
};

class Rectangle : public Quadrangle
{
public:
	Rectangle(int sidesAC, int sidesBD) : Quadrangle{sidesAC, sidesBD, sidesAC, sidesBD, 90, 90, 90, 90, "Прямоугольник"} {}
};

class Square : public Quadrangle
{
public:
	Square(int sides) : Quadrangle{sides, sides, sides, sides, 90, 90, 90, 90, "Квадрат"} {}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD) : Quadrangle{sidesAC, sidesBD, sidesAC, sidesBD, anglesAC, anglesBD, anglesAC, anglesBD, "Параллелограмм"} {}
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(int sides, int anglesAC, int anglesBD) : Quadrangle{sides, sides, sides, sides, anglesAC, anglesBD, anglesAC, anglesBD, "Ромб"} {}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle triangle{10, 20, 30, 50, 60, 70};

	RectangularTriangle rectangularTriangle{10, 20, 30, 50, 60};
	IsoscelesTriangle isoscelesTriangle{10, 20, 50, 60};
	EquilateralTriangle equilateralTriangle{30};

	Quadrangle quadrangle{10, 20, 30, 40, 50, 60, 70, 80};

	Rectangle rectangle{10, 20};
	Square square{20};
	Parallelogram parallelogram{20, 30, 30, 40};
	Rhombus rhombus{30, 30, 40};
	;

	triangle.print_info();

	rectangularTriangle.print_info();
	isoscelesTriangle.print_info();
	equilateralTriangle.print_info();

	quadrangle.print_info();

	rectangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhombus.print_info();

	return 0;
}
